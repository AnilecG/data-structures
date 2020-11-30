find_package(GTest REQUIRED)

add_executable(sll_test main_test.cc)

target_link_libraries(sll_test GTest::GTest GTest::Main)

add_test(AllTests sll_test)