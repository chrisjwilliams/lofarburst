set(module_sink_lib_src_cpu
    src/Config.cpp
    src/Factory.cpp
    PARENT_SCOPE
)

TEST_UTILS()

add_subdirectory(test)
