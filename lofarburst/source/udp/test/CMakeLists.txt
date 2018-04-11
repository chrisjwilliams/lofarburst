include_directories(${GTEST_INCLUDE_DIR})

link_directories(${GTEST_LIBRARY_DIR})

set(
    gtest_udp_src
    #src/BeamFormerPacketInspectorTest.cpp
    src/gtest_udp.cpp
)
add_executable(gtest_udp ${gtest_udp_src} )
target_link_libraries(gtest_udp ${LOFARBURST_TEST_UTILS} ${LOFARBURST_LIBRARIES} ${GTEST_LIBRARIES})
add_test(gtest_udp gtest_udp --test_data "${CMAKE_CURRENT_LIST_DIR}/data")
