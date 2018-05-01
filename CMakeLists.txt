project (exact_prediction)


cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 11)

find_package(CGAL REQUIRED COMPONENTS Widgets)
include( ${CGAL_USE_FILE} )

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets)


file(GLOB HDRS	"*.h")
file(GLOB SRCS	"*.cpp")


add_executable(tool ${SRCS} ${HDRS})

target_link_libraries(tool
Qt5::Widgets)

