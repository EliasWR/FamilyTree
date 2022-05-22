include_directories("${CMAKE_SOURCE_DIR}/include")
include_directories("${CMAKE_SOURCE_DIR}/libraries")

add_executable(testTree TestFamilyTree.cpp ../include/Date.hpp)
add_test(NAME testTree COMMAND testTree)