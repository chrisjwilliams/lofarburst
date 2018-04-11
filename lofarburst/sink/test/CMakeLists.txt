include_directories(${GTEST_INCLUDE_DIR})

link_directories(${GTEST_LIBRARY_DIR})

set(
   gtest_sink_src
    src/gtest_sink.cpp
)
add_executable(gtest_sink ${gtest_sink_src} )
target_link_libraries(gtest_sink ${LOFARBURST_TEST_UTILS} ${LOFARBURST_LIBRARIES} ${GTEST_LIBRARIES})
add_test(gtest_sink gtest_sink --test_data "${CMAKE_CURRENT_LIST_DIR}/data")
