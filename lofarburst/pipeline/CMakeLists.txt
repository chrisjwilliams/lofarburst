set(module_pipeline_lib_src_cpu
    src/EmptyPipeline.cpp
    src/FrbPipeline.cpp
    src/LofarburstConfiguration.cpp
    src/RfimPipeline.cpp
    src/PulsarPipeline.cpp
    PARENT_SCOPE
)


add_subdirectory(test)
