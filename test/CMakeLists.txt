add_executable(testfilter testfilter.cpp)
target_link_libraries(testfilter url-filter)
add_test(NAME testfilter COMMAND testfilter)
