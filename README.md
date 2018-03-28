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

## Functions description
**1. Show gray image <cmd:main.exe image_name 1>**<br />
**2. Show color image <cmd:main.exe image_name 2>** <br />  
**3. Otsu's thresholding <cmd:main.exe image_name 3>**  
* Description: Automatically find optimal thresholding value to binarize an image.  
* Reference: *N. Otsu, “A tlreshold selection method from gray-Level histograms,”Automatica, vol. 11, no. 1, pp. 23–27, 1975.*<br /> 
**4. Valley emphasis(VE) Otsu's thresholding <cmd:main.exe image_name 4>**
* Description: Automatically find optimal thresholding value to binarize an image.  
* Reference: *H.-F. Ng, “Automatic thresholding for defect detection,” Pattern recognition letters, vol. 27, no. 14, pp. 1644–1649, 2006.*<br /> 
**5. Weighted object variance(WOV) Otsu's thresholding <cmd:main.exe image_name 5>**  
* Description: Automatically find optimal thresholding value to binarize an image.  
* Reference: *X.-C. Yuan, L.-S. Wu, and Q. Peng, “An improved Otsu method using the weighted object variance for defect detection,” Applied Surface Science, vol. 349, pp. 472–484, 2015.*<br />
**6. Range constraint(RC) Otsu's thresholding <cmd:main.exe image_name 6>**  
* Description: Automatically find optimal thresholding value to binarize an image.  
* Reference: *X. Xu, S. Xu, L. Jin, and E. Song, “Characteristic analysis of Otsu threshold and its applications,” Pattern Recognition Letters, vol. 32, no. 7, pp. 956–961, 2011.*<br />
**7. Binary thresholding <cmd:main.exe image_name 7 threshold_value>** <br />  
* Description: Binarize an image with indicated threshold_value.  
**8. Statistical process control(SPC) thresholding <cmd:main.exe image_name 8 control_factor>** <br />  
* Description: Binarize an image with a range of gray level away from mean gray level, the range is controlled by input control_factor, control_factor usually is between 1 to 5.
**9. Sobel filter <cmd:main.exe image_name 9 filter_size>**<br />
* Description: Calculate approximations of the derivatives of input image, the filter size is set by input filter_size
