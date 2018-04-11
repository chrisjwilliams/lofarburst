SUBPACKAGE(udp)

set(module_source_lib_src_cpu
    src/Config.cpp
    src/Factory.cpp
    ${lib_src_cpu}
    PARENT_SCOPE
)

add_subdirectory(test)
