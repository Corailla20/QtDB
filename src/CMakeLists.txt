# Notice name prefix of this variable, set by CMake according
# to value given with "project()" in the root CMakeLists.txt.
FILE(GLOB sources_list *.cpp *.h Controller/*.cpp Controller/*.h Model/*.cpp Model/*.h View/*.cpp View/*.h View/*.ui)
add_executable(QtDB ${sources_list})
target_link_libraries(QtDB Qt4::QtGui Qt4::QtXml Qt4::QtSql)
