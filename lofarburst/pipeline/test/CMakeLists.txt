include_directories(${GTEST_INCLUDE_DIR})

link_directories(${GTEST_LIBRARY_DIR})

set(
   gtest_pipeline_src
    src/gtest_pipeline.cpp
)
add_executable(gtest_pipeline ${gtest_pipeline_src} )
target_link_libraries(gtest_pipeline ${LOFARBURST_TEST_UTILS} ${LOFARBURST_LIBRARIES} ${GTEST_LIBRARIES})
add_test(gtest_pipeline gtest_pipeline --test_data "${CMAKE_CURRENT_LIST_DIR}/data")
