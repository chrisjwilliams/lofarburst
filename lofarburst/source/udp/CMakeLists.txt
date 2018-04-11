set(module_udp_lib_src_cpu
    src/Config.cpp
#    src/UdpStream.cpp
    PARENT_SCOPE
)

TEST_UTILS()

add_subdirectory(test)
