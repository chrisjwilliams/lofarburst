set(module_utils_lib_src_cpu
    src/ConfigModule.cpp
    PARENT_SCOPE
)

TEST_UTILS()

add_subdirectory(test)
