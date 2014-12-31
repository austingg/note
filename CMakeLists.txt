project(XDoGPCDemo)
cmake_minimum_required(VERSION 2.6)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

### Headers
include_directories ("${PROJECT_SOURCE_DIR}/XDoG"
"${CMAKE_CURRENT_SOURCE_DIR}/OpenCV/inc")

### src lists ###
aux_source_directory(XDoGPCDemo ARC_PEN_DEMO_SRC)
###aux_source_directory(XDoGPCDemo/jni ARC_PEN_DEMO_SRC)


set(ARC_PEN_DEMO_SRC ${ARC_PEN_DEMO_SRC})

### output files ###
add_executable(XDoGPCDemo ${ARC_PEN_DEMO_SRC})


### link the executable to the necessary library ###
target_link_libraries(ArcPenDemo "${CMAKE_CURRENT_SOURCE_DIR}/OpenCV/lib/opencv_core249.lib" 
"${CMAKE_CURRENT_SOURCE_DIR}/OpenCV/lib/opencv_highgui249.lib" 
"${CMAKE_CURRENT_SOURCE_DIR}/OpenCV/lib/opencv_imgporc249.lib" 
"${CMAKE_CURRENT_SOURCE_DIR}/OpenCV/lib/opencv_contrib249.lib")

