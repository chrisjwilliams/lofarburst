include_directories(${GTEST_INCLUDE_DIR})

link_directories(${GTEST_LIBRARY_DIR})

set(
   gtest_source_src
    src/gtest_source.cpp
)
add_executable(gtest_source ${gtest_source_src} )
target_link_libraries(gtest_source ${LOFARBURST_TEST_UTILS} ${LOFARBURST_LIBRARIES} ${GTEST_LIBRARIES})
add_test(gtest_source gtest_source --test_data "${CMAKE_CURRENT_LIST_DIR}/data")
