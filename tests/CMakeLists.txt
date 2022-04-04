include_directories("${CMAKE_SOURCE_DIR}/Include")

add_executable(testTree TestFamilyTree.cpp)
add_test(NAME testTree COMMAND testTree)