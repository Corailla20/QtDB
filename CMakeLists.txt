cmake_minimum_required(VERSION 2.8)    
project(QtDB)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt4 REQUIRED QtGui QtXml QtSql)
add_subdirectory("src")

