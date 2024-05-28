# MoveDetector
## [Introduction]
This project was carried out with the purpose of testing the functionalities of the OpenCV library in c/c++. This so that we could use a computer webcam as a motion sensor, to make the project more interesting the team decided to add a video game in which this motion detector functionality would be implemented, and what a more ideal game would be than "Just-Dance", one where to play you must move so that the device captures your movements. This would be our goal, to emulate "Just-Dance" to make it work without the need of a game console itself.

## [How to use it]
1. First, you have to had been downloaded Visual Studio and OpenCV
   _ Visual Studio needs to have the c++ language installed
   _ OpenCV needs to be configured in c++, you can use the next tutorial like a guide (https://gist.github.com/demid5111/6faa590e4fc5813550dd95cc1c538893).
   The next its a little explanation about how to configure the program to recognize the libraries of OpenCV.
      _ First of all, open the Project->HelloOpenCV.vcxproj and search Properties and go to VC++ Directories.
      _ Next, change the Include Directories to contain corresponding include folder in the opencv installation.
      _ Insert it to the beginning of the value: C:\opencv\opencv\build\include;
      _ After, change the Library directories to include C:\opencv\opencv\build\x64\vc15\lib
      _ Change the Linker->Input->Additional dependencies to include opencv_world451d.lib if we are talking about pre-configured package installation Include opencv_core451d.lib;opencv_highgui451d.lib;opencv_videoio451d.lib;opencv_imgcodecs451d.lib; if we are talking about building from sources.
      _ Apply and close the window
To name the few more available libraries that can be included with the following linker flags (for Windows remove -l and add 451d.lib to the end if the version of opencv is 4.5.1:
<code>
                                             -lopencv_gapi -lopencv_stitching -lopencv_alphamat \
                                             -lopencv_aruco -lopencv_bgsegm -lopencv_bioinspired \
                                             -lopencv_ccalib -lopencv_dnn_objdetect -lopencv_dnn_superres \
                                             -lopencv_dpm -lopencv_face -lopencv_freetype \
                                             -lopencv_fuzzy -lopencv_hfs -lopencv_img_hash \
                                             -lopencv_intensity_transform -lopencv_line_descriptor -lopencv_mcc \
                                             -lopencv_quality -lopencv_rapid -lopencv_reg \
                                             -lopencv_rgbd -lopencv_saliency -lopencv_sfm \
                                             -lopencv_stereo -lopencv_structured_light -lopencv_phase_unwrapping \
                                             -lopencv_superres -lopencv_optflow -lopencv_surface_matching \
                                             -lopencv_tracking -lopencv_highgui -lopencv_datasets \
                                             -lopencv_text -lopencv_plot -lopencv_videostab \
                                             -lopencv_videoio -lopencv_viz -lopencv_xfeatures2d \
                                             -lopencv_shape -lopencv_ml -lopencv_ximgproc \
                                             -lopencv_video -lopencv_dnn -lopencv_xobjdetect \
                                             -lopencv_objdetect -lopencv_calib3d -lopencv_imgcodecs \
                                             -lopencv_features2d -lopencv_flann -lopencv_xphoto \
                                             -lopencv_photo -lopencv_imgproc -lopencv_core
   </code>
3. When you have installed them, download the zip archive of this repository
4. Afther that you have to also download dolphin emulator and the room of the game "Just-Dance",for legal reasons this guide not have a link to that, but is not too difficult find one.
5. Configure dolphin to play "Just-Dance"
6. With the archive uncompressed, open de program

## [Function]
When you open the program

## [Specifications]
If you want the best experience with the program, you should be have the next components:
`rgb(9, 105, 218)`From 12 to 16 of DDR4 type ram memory .
`rgb(9, 105, 218)`At least 256gb of storage in the computer.
`rgb(9, 105, 218)`A camera, not matter if is integrated (preferent) or external.
`rgb(9, 105, 218)`
`rgb(9, 105, 218)`
