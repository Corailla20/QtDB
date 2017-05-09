# Notice name prefix of this variable, set by CMake according
# to value given with "project()" in the root CMakeLists.txt.
FILE(GLOB sources_list *.cpp *.h Controller/*.cpp Controller/*.h Model/*.cpp Model/*.h View/*.cpp)

QT4_WRAP_UI(QtDB_UISrcs View/mainwindow.ui)

add_executable(QtDB ${sources_list} ${QtDB_UISrcs} ${QtDB_MOCSrcs})
target_link_libraries(QtDB Qt4::QtGui Qt4::QtXml Qt4::QtSql)


