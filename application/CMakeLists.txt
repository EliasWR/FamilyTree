include_directories("${CMAKE_SOURCE_DIR}/include")
include_directories("${CMAKE_SOURCE_DIR}/libraries")

add_executable(Family_Tree Family_Tree.cpp ../include/JsonFile.hpp ../include/ExceptionHandling.hpp ../include/Date.hpp)