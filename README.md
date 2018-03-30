# image-processing-toolbox
This is toolbox for consecutive image process using OpenCV3.0 library on Visual studio 2012 platform. This program provides fast image processing algortihm development with multiple image process operation using OpenCV library.


## How can you get started
https://docs.opencv.org/2.4/doc/tutorials/introduction/windows_visual_studio_Opencv/windows_visual_studio_Opencv.html<br />
https://www.youtube.com/watch?v=l4372qtZ4dc<br />
Above are tutorial webisites which tell you how to install OpenCV library on visual studio platform, following are steps:<br />
* Download OpenCV on https://opencv.org/releases.html<br />
* Setting environment variable:PC->Properties->Advanced system setting->Environment variables->Path<br />
->Edit->New->OpenCV bin directory<br />
* Open new projects: Open Visual studio->File->New project->Visual C++->Win32 Console application->Finish<br />
* Choose configuration: Configuration manager->Active solution platform->New->Choose x86 or x64 platform <br />
* Set include path: Project->Properties->C/C++->Additional include directories->Opencv include directory<br />
* Add library directories:Project->Properties->linker->General->Additional library directories->Opencv lib directory<br />
* Add library dependency:Project->Properties->linker->Input->Additional dependecies->opencv_world300d.lib<br />
* Download msvcp120d.dll and msvcr120d.dll to your project folder(optional) <br />
* Copy all file into your project folder<br />
* Build project and find main.exe directory, put lena.png file into that folder <br />
* Open cmd.exe and go to your debug directory where main.exe was generated <br />
* Enter command "main.exe lena.png 1" <br />
* Have fun! <br />


## How does this work
This program is intended to people who need to test consecutive image processing. After each command, there will be a file output.png generated in your main.exe directory. <br />
* In cmd.exe, go to your debug directory where main.exe was generated. <br />
* Enter command "main.exe image_name method parameter1 parameter2...."<br />
* For example, you can do input image->Otsu's thresholding->Sobel filter, which is a well known method for edge detection. Following are steps:"<br />
* (Show color image) In cmd.exe: main.exe lena.png 2
<p align="center"><img src="/image/lena.png" height="30%" width="30%"></p><br />
* (Apply Sobel filter) In cmd.exe: main.exe output.png 9 3
<p align="center"><img src="/image/sobel.png" height="30%" width="30%"></p><br />
* (Apply Otsu's thresholding) In cmd.exe: main.exe output.png 3
<p align="center"><img src="/image/otsu.png" height="30%" width="30%"></p><br />

## Which function inside this toolbox(Method)
1. Show gray image<br />
2. Show color image<br />
3. Otsu's thresholding<br />
4. Valley emphasis(VE) Otsu's thresholding<br />
5. Weighted object variance(WOV) Otsu's thresholding<br />
6. Range constraint(RC) Otsu's thresholding<br />
7. Binary thresholding<br />
8. Statistical process control(SPC) thresholding<br />
9. Sobel filter<br />
10. Laplacian filter<br />
11. Canny filter<br />
12. Gabor filter<br />
13. Median filter<br />
14. Gaussian blur filter<br />
15. Local contrast enhancement<br />
16. Local binary patterns<br />
17. Difference of Gaussian<br />
18. Discrete Fourier transform<br />
19. Histogram equalization<br />
20. Image resize<br />

## Functions description
**1. Show gray image <main.exe image_name 1>**<br />
* Description: Show gray image and save as output.png in main.exe folder.

**2. Show color image <main.exe image_name 2>** <br />  
* Description: Show color image and save as output.png in main.exe folder.

**3. Otsu's thresholding <main.exe image_name 3>**  
* Description: Automatically find optimal thresholding value to binarize an image.  
* Reference: *N. Otsu, “A tlreshold selection method from gray-Level histograms,”Automatica, vol. 11, no. 1, pp. 23–27, 1975.*<br /> 

**4. Valley emphasis(VE) Otsu's thresholding <main.exe image_name 4>**
* Description: Automatically find optimal thresholding value to binarize an image.  
* Reference: *H.-F. Ng, “Automatic thresholding for defect detection,” Pattern recognition letters, vol. 27, no. 14, pp. 1644–1649, 2006.*<br /> 

**5. Weighted object variance(WOV) Otsu's thresholding <main.exe image_name 5>**  
* Description: Automatically find optimal thresholding value to binarize an image.  
* Reference: *X.-C. Yuan, L.-S. Wu, and Q. Peng, “An improved Otsu method using the weighted object variance for defect detection,” Applied Surface Science, vol. 349, pp. 472–484, 2015.*<br />

**6. Range constraint(RC) Otsu's thresholding <main.exe image_name 6>**  
* Description: Automatically find optimal thresholding value to binarize an image.  
* Reference: *X. Xu, S. Xu, L. Jin, and E. Song, “Characteristic analysis of Otsu threshold and its applications,” Pattern Recognition Letters, vol. 32, no. 7, pp. 956–961, 2011.*<br />

**7. Binary thresholding <main.exe image_name 7 threshold_value>** <br />  
* Description: Binarize an image with input threshold value "threshold_value".  

**8. Statistical process control(SPC) thresholding <main.exe image_name 8 control_factor>** <br />  
* Description: Binarize an image with a range of gray level away from mean gray level, the range is controlled by input control factor value "control_factor".
* Reference: *D.-M. Tsai and C.-Y. Hsieh, “Automated surface inspection for directional textures,” Image and Vision computing, vol. 18, no. 1, pp. 49–62, 1999.*<br />  

**9. Sobel filter <main.exe image_name 9 filter_size>**<br />
* Description: Calculate approximations of the first derivatives of input image, the filter size is set by input value "filter_size".
* Reference: https://docs.opencv.org/2.4/doc/tutorials/imgproc/imgtrans/sobel_derivatives/sobel_derivatives.html

**10. Laplacian filter <main.exe image_name 10 filter_size>**<br />
* Description: Calculate second approximations of the derivatives of input image, the filter size is set by input value "filter_size".

**11. Canny filter <main.exe image_name 11 filter_size lower_threshold upper_threshold>**<br />
* Description: Find edge by first applying sobel filter. The size of sobel filter is set by input value "filter_size". Then threshold with "lower_threshold" and "upper threshold", finally, non maximum suppression is applied to thin the edge. 
* Reference: https://docs.opencv.org/2.4/doc/tutorials/imgproc/imgtrans/canny_detector/canny_detector.html

**12. Gabor filter <main.exe image_name 12 filter_size sigma theta lambd gamma psi>**<br />
* Description: Extract various image features with a kernal from Gaussian function times sinusoidal function.
* Reference: https://cvtuts.wordpress.com/2014/04/27/gabor-filters-a-practical-overview/

**13. Median filter <main.exe image_name 13 filter_size>**<br />
* Description: Find median value from all value inside filter with size "filter_size".

**14. Gaussian blur filter <main.exe image_name 14 filter_size sigma>**<br />
* Description: Blur an image by convoluting a Gaussian filter with size "filter_size" and standard deviation "sigma".

**15. Local contrast enhancement <main.exe image_name 15 filter_size>**<br />
* Description: Enhance an image contrast by calculating ratio between center gray level and mean gray level in filter with filter size "filter_size".
* Reference: *KAO, Wen-Chung; HSU, Ming-Chai; YANG, Yueh-Yiing. Local contrast enhancement and adaptive feature extraction for illumination-invariant face recognition. Pattern Recognition, 2010*

**16. Local binary patterns <main.exe image_name 16>**<br />
* Description: Extract local image features using 3 times 3 LBP filter, which compare gray level of center pixel to gray level of neighbor pixel.
* Reference:" Ojala, T., Pietikainen, M., & Maenpaa, T. (2002). Multiresolution gray-scale and rotation invariant texture classification with local binary patterns. IEEE Transactions on pattern analysis and machine intelligence, 24(7), 971-987.*

**17. Difference of Gaussian <main.exe image_name 17 filter_size sigma1 sigma2>**<br />
* Description: Extract image features as a band-pass filter by subtacting images convoluted with Gaussian filter with different standard deviation. The size of Gaussian filter is "filter size", "sigma1" and "sigma2" are standard deviation of two Gaussian filter.
* Reference: https://en.wikipedia.org/wiki/Difference_of_Gaussians

**18. Discrete Fourier transform <main.exe image_name 18>**<br />
* Description: Transform image to Frequency domain using discrete Fourier transform.
* Reference: https://docs.opencv.org/2.4/doc/tutorials/core/discrete_fourier_transform/discrete_fourier_transform.html

**19. Histogram equalization <main.exe image_name 19>**<br />
* Description: Improve contrast of an image by remapping gray level histogram to cumulative distribution function.
* Reference: https://docs.opencv.org/2.4/doc/tutorials/imgproc/histograms/histogram_equalization/histogram_equalization.html

**20. Image resize <main.exe image_name 20 new_width new_height>**<br />
* Description: Resize input image to new size with resolution(new_width, new_height).
