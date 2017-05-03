cmake_minimum_required(VERSION 2.8)    
project(QtDB)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt4 REQUIRED QtGui QtXml QtSql)
FILE(GLOB sources_list src/*.cpp src/*.h Data/*.* src/Controller/*.cpp src/Controller/*.h src/Model/*.cpp src/Model/*.h src/View/*.cpp src/View/*.h)
add_executable(QtDB ${sources_list})
#add_subdirectory("src");