// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include "vector"
#include "opencv2\opencv.hpp"

typedef unsigned char uchar;
using namespace cv;
using namespace std;

cv::Mat otsu(cv::Mat temp, int method);
cv::Mat SPC(cv::Mat temp, double para1);
cv::Mat Sobel(cv::Mat temp, double para1);
cv::Mat Gabor(cv::Mat temp,double para1,double para2,double para3,double para4,double para5,double para6);
cv::Mat LCE(cv::Mat temp, double para1);
cv::Mat LBP(cv::Mat temp);
cv::Mat DOG(cv::Mat temp, double para1,double para2,double para3);
cv::Mat DFT(cv::Mat temp);
int main(int argc, const char *argv[])
{
	Mat input,output,colorimg;
	if(argc < 3){  //command exampl: main.exe, filename, method, parameter1, parameter2,..... 
		cout<<"command invalid";
		return -1;
	}
	std::string filename=argv[1];
	int Method=stoi(string(argv[2])); //convert string to int
	vector <double> para;
	int count=3;
	while(count<10){
		if(count<argc)
			para.push_back(stof(string(argv[count])));
		else
			para.push_back(0);
		count++;
	}
	input = imread(filename, 0);  //read a gray image
	colorimg = imread(filename, 1);  //read a color image
	if(input.empty()){
		cout<<("Can not load image: "+filename);
		return -1;
	}
	switch( Method) {
	case 1 :cout<<("show gray image:"+filename);
			input.copyTo(output);
			cv::imshow("gray image",output);
            break;  
	case 2 :cout<<("show color image:"+filename);
			colorimg.copyTo(output);
			cv::imshow("color image",output);
            break;  
	case 3 :output=otsu(input,0);
			cv::imshow("After Otsu's threshold",output);
		    break;
	case 4 :output=otsu(input,1);
			cv::imshow("After VE Otsu's threshold",output);
		    break;
	case 5 :output=otsu(input,2);
			cv::imshow("After WOV Otsu's threshold",output);
		    break;
	case 6 :output=otsu(input,3);
			cv::imshow("After RC Otsu's threshold",output);
		    break;
	case 7 :cv::threshold(input,output,para[0],255,CV_THRESH_BINARY);
			cv::imshow("After Binary threshold",output);
		    break;
	case 8 :output=SPC(input,para[0]);
			cv::imshow("After Statistical Process Control threshold",output);
		    break;
	case 9 :output=Sobel(input,para[0]);
			cv::imshow("After Sobel filter",output);
		    break;
	case 10:cv::Laplacian(input,output,CV_16S,int(para[0]),1,0);
			cv::imshow("After Laplacian filter",output);
			break;
	case 11:cv::Canny(input,output,para[0],para[1],int(para[2]));
			cv::imshow("After Canny filter",output);
			break;
	case 12:output=Gabor(input,para[0],para[1],para[2],para[3],para[4],para[5]);
			cv::imshow("After Gabor filter",output);			
			break;	
	case 13:cv::medianBlur(input,output,para[0]);
			cv::imshow("After Median filter",output);
			break;	
	case 14:cv::GaussianBlur(input,output,cv::Size(int(para[0]),int(para[0])),para[1]);
			cv::imshow("After Gaussian blur filter",output);
			break;	
	case 15:output=LCE(input,para[0]);
			cv::imshow("After Local contrast enhancement",output);
			break;
	case 16:output=LBP(input);
			cv::imshow("After Local binary patterns",output);
			break;
	case 17:output=DOG(input,para[0],para[1],para[2]);
			cv::imshow("After differential of Gaussian",output);
			break;
	case 18:output=DFT(input);
			cv::imshow("Discrete Fourier transform",output);
			break;
	case 19:cv::equalizeHist(input,output);
			cv::imshow("After histogram equalization",output);
			break;	
	case 20:cv::resize(input,output,cv::Size(para[0],para[1]));
			cv::imshow("After resize",output);
			break;	
	default:cout<<"command invalid";
			return -1;
			break;
	}
	cv::imwrite("output.png",output); //write an image in main.exe folder
	waitKey();
	return 0;
}



cv::Mat otsu(cv::Mat temp, int method){
    cv::Mat otsu,RC; //RC is for RC Otsu's threshold method
    temp.convertTo(temp,CV_8U); //image format change to unsigned 8bit/pixel 
	temp.copyTo(otsu);
	temp.copyTo(RC);
    cv::threshold(temp,RC,140,255,CV_THRESH_OTSU); //Otsu's theshold using OpenCV function(Only for RC Otsu's method)
    float pi=0,ui=0,u=0;
    float n=0;
    vector <float> p0; //p0 is cumulated probability for gray level less than threshold t
    vector <float> p1; //p1 is cumulated probability for gray level greater than a threshold t
    vector <float> u0; //u0 is mean gray level for pixels with gray level less than threshold t
    vector <float> u1; //u1 is mean gray level for pixels with gray level greater than threshold t
    vector <float> delta; //Delta is between-class variance
    float h[256];
    for(int k=0;k<256;k++)
        h[k]=0;
    for(int i=0;i<otsu.rows;i++) //compute histogram of input image
        for(int j=0;j<otsu.cols;j++){
            if(method==3){
				if(RC.ptr<uchar>(i)[j]==0){ //RC Otsu's method only count pixel with gray level greater than first Otsu's threshold
					h[otsu.ptr<uchar>(i)[j]]++;
					n++;
				}
			}
			else{
				h[otsu.ptr<uchar>(i)[j]]++;
				n++;
			}
        }
    for(int k=0;k<256;k++){
        pi+=h[k]/n;
        p0.push_back(pi);
        p1.push_back(1-pi);

    }
    for(int k=0;k<256;k++){
        if(p0[k]!=0)
            for(int l=0;l<k+1;l++)
                ui+=float(l)*h[l]/n/p0[k];
        else
            ui=0;
        u0.push_back(ui);
        if(p1[k]!=0)
            for(int l=k+1;l<256;l++)
                u+=float(l)*h[l]/n/p1[k];
        else
            u=0;
        u1.push_back(u);
        u=0;
        ui=0;
    }
	if(method==0 || method==3) //Otsu's threshold && RC Otsu's method
		for(int k=0;k<256;k++)
		 delta.push_back( p0[k]*u0[k]*u0[k]+p1[k]*u1[k]*u1[k] );
	else if(method==1) //VE method
		for(int k=0;k<256;k++)
		 delta.push_back(  (1-h[k]/n)*(p0[k]*u0[k]*u0[k]+p1[k]*u1[k]*u1[k])  );
	else if(method==2) //WOV method
		for(int k=0;k<256;k++) 
		 delta.push_back(  p0[k]*p0[k]*u0[k]*u0[k]+p1[k]*u1[k]*u1[k] );
    float max=0;
    int TH=0;
    for(int i=0;i<256;i++) //find threshold TH with maximum between-class variance
        if(delta[i]>max){
            max = delta[i];
            TH=i;
        }
	cv::threshold(temp,otsu,TH,255,CV_THRESH_BINARY); //Binary threshold with computed threshold TH
	cout<<"Computed threshold value is:"<<TH;
    return otsu;
}
cv::Mat SPC(cv::Mat temp, double para1){
	cv::Mat SPC;
	temp.copyTo(SPC);
    Scalar mean,std;
    cv::meanStdDev(SPC,mean,std); //find mean and standard deviation of gray level in input image
    double c=para1;
    for(int i=0;i<SPC.rows;i++)
        for(int j=0;j<SPC.cols;j++)
            if(SPC.ptr<uchar>(i)[j]>mean.val[0]-c*std.val[0] && SPC.ptr<uchar>(i)[j]<mean.val[0]+c*std.val[0]) //threshold out pixel with gray level less and greater than c*standard deviation from mean
                SPC.ptr<uchar>(i)[j]=0;
            else
                SPC.ptr<uchar>(i)[j]=255;
	cout<<"Computed lower bound value is:"<<mean.val[0]-c*std.val[0]<<endl;
	cout<<"Computed upper bound value is:"<<mean.val[0]+c*std.val[0];
    return SPC;
}
cv::Mat Sobel(cv::Mat temp, double para1){
	cv::Mat imgSingle;
    temp.copyTo(imgSingle);
    imgSingle.convertTo(imgSingle,CV_8U); //image format change to unsigned 8bit/pixel 
    cv::Mat sobel;
    cv::Mat grad_x,grad_y;
	int kszie=int(para1);
    cv::Sobel( imgSingle.clone(), grad_x, CV_16S, 1, 0, kszie, 1, 0, cv::BORDER_DEFAULT );
    cv::Sobel( imgSingle.clone(), grad_y, CV_16S, 0, 1, kszie, 1, 0, cv::BORDER_DEFAULT );
    cv::convertScaleAbs( grad_x, grad_x );
    cv::convertScaleAbs( grad_y, grad_y );
    cv::addWeighted( grad_x, 0.5, grad_y, 0.5, 0, sobel );
	return sobel;
}
cv::Mat Gabor(cv::Mat temp,double para1,double para2,double para3,double para4,double para5,double para6){
	cv::Mat output;
	cv::Mat kernel = cv::getGaborKernel(cv::Size(int(para1),int(para1)), para2, para3, para4, para5, para6);
	temp.convertTo(temp,CV_32F);
    cv::filter2D(temp, output, CV_32F, kernel);
	cv::normalize(output, output, 0, 255,NORM_MINMAX);
    output.convertTo(output,CV_8U);
	return output;
}
cv::Mat LCE(cv::Mat temp, double para1){
	temp.convertTo(temp,CV_32FC1); //image format change to float 
	//cv::normalize(temp, temp, 0, 1,NORM_MINMAX);
	int edge=(int(para1)-1)/2;
    Mat output=cv::Mat(temp.rows,temp.cols,CV_32FC1,cv::Scalar(0));
	Scalar mean,std;
	for(int i=edge;i<temp.rows-edge;i++)
		for(int j=edge;j<temp.cols-edge;j++){
			cv::Rect myROI(j-edge, i-edge, para1, para1);
			cv::Mat croppedImage = temp(myROI);
			cv::meanStdDev(croppedImage,mean,std); //Compute mean gray level within kernel around point(i,j)
			output.ptr<float>(i)[j]=log(temp.ptr<float>(i)[j]/mean.val[0]); //Compute ratio between gray level on point(i,j) with mean gray level within kernel around point(i,j)
		}
	cv::normalize(output, output, 0, 255,NORM_MINMAX); //normalize image gray level from 0 to 255
    output.convertTo(output,CV_8U); //image format change to unsigned 8bit/pixel 
	return output;
}
cv::Mat LBP(cv::Mat temp){
    cv::Mat I=cv::Mat(temp.rows,temp.cols,CV_8UC1,cv::Scalar(0));
    for(int i=1;i<temp.rows-1;i++) //Compare neighbor pixel gray level with center gray level one by one
        for(int j=1;j<temp.cols-1;j++){ 
            if(temp.ptr<uchar>(i)[j]<temp.ptr<uchar>(i-1)[j-1]) //If neighbor pixel gray level large than center gray level, new gray level increase bitwise
                I.ptr<uchar>(i)[j]+=128;
            if(temp.ptr<uchar>(i)[j]<temp.ptr<uchar>(i-1)[j])
                I.ptr<uchar>(i)[j]+=64;
            if(temp.ptr<uchar>(i)[j]<temp.ptr<uchar>(i-1)[j+1])
                I.ptr<uchar>(i)[j]+=32;
            if(temp.ptr<uchar>(i)[j]<temp.ptr<uchar>(i)[j+1])
                I.ptr<uchar>(i)[j]+=16;
            if(temp.ptr<uchar>(i)[j]<temp.ptr<uchar>(i+1)[j+1])
                I.ptr<uchar>(i)[j]+=8;
            if(temp.ptr<uchar>(i)[j]<temp.ptr<uchar>(i+1)[j])
                I.ptr<uchar>(i)[j]+=4;
            if(temp.ptr<uchar>(i)[j]<temp.ptr<uchar>(i+1)[j-1])
                I.ptr<uchar>(i)[j]+=2;
            if(temp.ptr<uchar>(i)[j]<temp.ptr<uchar>(i)[j-1])
                I.ptr<uchar>(i)[j]+=1;
        }
	return I;
}
cv::Mat DOG(cv::Mat temp, double para1,double para2,double para3){
	cv::Mat DOG,DOG_2;
	temp.convertTo(temp,CV_64FC1);
	cv::GaussianBlur(temp,DOG,cv::Size(int(para1),int(para1)),para2);
	cv::GaussianBlur(temp,DOG_2,cv::Size(int(para1),int(para1)),para3);
	DOG=abs(DOG_2-DOG);
	cv::normalize(DOG, DOG, 0, 255,NORM_MINMAX); //normalize image gray level from 0 to 255
	DOG.convertTo(DOG,CV_8U); //image format change to unsigned 8bit/pixel 
	return DOG;
}
cv::Mat DFT(cv::Mat temp){
	Mat F,I;
    temp.copyTo(I);
    I.convertTo(I,CV_32F);
    Mat padded;                            //expand input image to optimal size
    int m = getOptimalDFTSize( I.rows );
    int n = getOptimalDFTSize( I.cols ); // on the border add zero values
    copyMakeBorder(I, padded, 0, m - I.rows, 0, n - I.cols, BORDER_CONSTANT, Scalar::all(0));
    Mat planes[] = {Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F)};
    Mat complexI;
    merge(planes, 2, complexI);         // Add to the expanded another plane with zeros
    dft(complexI, complexI);            // this way the result may fit in the source matrix
    complexI.copyTo(I);            // copy real frequency information
    split(complexI, planes);                   // planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))
    Mat magI;
    magnitude(planes[0], planes[1], magI);// planes[0] = magnitude
    magI += Scalar::all(1);                    // switch to logarithmic scale
    log(magI, magI);
    // crop the spectrum, if it has an odd number of rows or columns
    magI = magI(Rect(0, 0, magI.cols & -2, magI.rows & -2));
    // rearrange the quadrants of Fourier image  so that the origin is at the image center
    int cx = magI.cols/2;
    int cy = magI.rows/2;
    Mat q0(magI, Rect(0, 0, cx, cy));   // Top-Left - Create a ROI per quadrant
    Mat q1(magI, Rect(cx, 0, cx, cy));  // Top-Right
    Mat q2(magI, Rect(0, cy, cx, cy));  // Bottom-Left
    Mat q3(magI, Rect(cx, cy, cx, cy)); // Bottom-Right
    Mat tmp;                           // swap quadrants (Top-Left with Bottom-Right)
    q0.copyTo(tmp);
    q3.copyTo(q0);
    tmp.copyTo(q3);

    q1.copyTo(tmp);                    // swap quadrant (Top-Right with Bottom-Left)
    q2.copyTo(q1);
    tmp.copyTo(q2);
    normalize(magI, magI, 0, 255, CV_MINMAX); // Transform the matrix with float values into a viewable image form (float between values 0 and 1).
    merge(planes, 2, complexI);
    magI.convertTo(magI,CV_8U);
    return magI;
}

