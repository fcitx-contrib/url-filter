add_executable(testfilter testfilter.cpp)
target_link_libraries(testfilter url-filter)
add_test(NAME testfilter COMMAND testfilter)

add_executable(testutil testutil.cpp)
target_link_libraries(testutil url-filter)
add_test(NAME testutil COMMAND testutil)
