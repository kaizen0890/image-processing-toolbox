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
* Open cmd.exe and go to your main.exe directory <br />
* Enter command "main.exe lena.png 1" <br />
* Have fun! <br />


## How does this work

## Which function inside this toolbox(Method)
* 1.Show gray image
* 2.Show color image
* 3.Otsu's thresholding
* 4.Valley emphasis(VE) Otsu's thresholding
* 5.weighted object variance(WOV) Otsu's thresholding
* 6.Range constraint(RC) Otsu's thresholding
* 7.Binary thresholding
* 8.Statistical process control(SPC) thresholding
* 9.Sobel filter

