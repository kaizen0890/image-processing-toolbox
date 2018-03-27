# image-processing-toolbox
Toolbox for consecutive image process using OpenCV3.0 library on Visual studio 2012 platform

## How can you get started
https://docs.opencv.org/2.4/doc/tutorials/introduction/windows_visual_studio_Opencv/windows_visual_studio_Opencv.html
https://www.youtube.com/watch?v=l4372qtZ4dc
Above are very useful tutorial webisites which tell you how to install OpenCV library on visual studio platform, following are steps:
*Download OpenCV on https://opencv.org/releases.html
*Setting environment variable on your computer: This PC->Properties->Advanced system setting->Environment variables->Path->Edit->New->Enter OpenCV bin folder directory
*Open new projects on VS: Open VS->File->New project->Visual C++->Win32 Console application->Finish
*Choose configuration on VS: Configuration manager->Active solution platform->New->Choose x86 or x64 platform base on your computer system
*Set include path on VS: Project->Properties->C/C++->Additional include directories->Enter Opencv include folder directory
*Add library directories on VS:Project->Properties->linker->General->Additional library directories->Enter Opencv lib folder directory
*Add library dependencyon VS:Project->Properties->linker->Input->Additional dependecies->Enter opencv_world300d.lib
