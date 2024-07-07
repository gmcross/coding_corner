set(TEST_MAIN ${library_name}_tests)
set(TEST_SOURCES
  renderer_tests.cc
  rectangle_tests.cc
)

add_executable(${TEST_MAIN} ${TEST_SOURCES})
target_link_libraries(${TEST_MAIN}
PRIVATE
  GTest::gtest
  GTest::gtest_main
  GTest::gmock
  GTest::gmock_main
  ${library_name}
)

include(GoogleTest)
gtest_discover_tests(${TEST_MAIN} XML_OUTPUT_DIR ${XML_TEST_RESULTS_DIR})
