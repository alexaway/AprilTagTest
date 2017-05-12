cmake_minimum_required(VERSION 3.7)
project(AprilTagTest)

set(CMAKE_CXX_STANDARD 11)

link_libraries(apriltags)
find_package(Eigen3)
find_package(OpenCV)

include_directories(${EIGEN3_INCLUDE_DIR} ${OpenCV_INCLUDE_DIRS})


set(SOURCE_FILES main.cpp)
add_executable(AprilTagTest ${SOURCE_FILES})
target_link_libraries(AprilTagTest ${OpenCV_LIBS})