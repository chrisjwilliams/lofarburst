# Profile Guided Optimization

if(CMAKE_BUILD_TYPE MATCHES pgotrain)

    if (CMAKE_COMPILER_IS_GNUCXX)
        SET(PGO_COMPILE_FLAGS "-fprofile-generate=${CMAKE_BINARY_DIR}/profile-data")
    endif()
    if (CMAKE_CXX_COMPILER_ID MATCHES Clang)
        SET(PGO_COMPILE_FLAGS "-fprofile-instr-generate -g -O0  -fprofile-arcs -ftest-coverage")
    endif()

    # Add the CMAKE_CXX_FLAGS_RELEASE so that a PGO optimized build also includes release flags
    SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE} ${PGO_COMPILE_FLAGS}" )

endif()

if(CMAKE_BUILD_TYPE MATCHES pgobuild)

    # Where to find the profiling data from the training run
    if(NOT PGO_TRAINING_DIR)
        SET(PGO_TRAINING_DIR ../training)
    endif()
    SET(PGO_TRAINING_DATA ${CMAKE_BINARY_DIR}/${PGO_TRAINING_DIR}/profile-data)

    if(NOT EXISTS ${PGO_TRAINING_DATA})
        message(FATAL_ERROR "No profiling Data Found so can't Build. Ensure that the training run was executed in the training build directory. Training data expected in Directory: " ${PGO_TRAINING_DATA})
    endif()

    if (CMAKE_COMPILER_IS_GNUCXX)
        SET(PGO_COMPILE_FLAGS "-fprofile-use=${PGO_TRAINING_DATA} -fprofile-correction")
    endif()
    if (CMAKE_CXX_COMPILER_ID MATCHES Clang)
        SET(PGO_COMPILE_FLAGS "-fprofile-instr-use -g -O0  -fprofile-arcs -ftest-coverage")
    endif()

    # This custom target always runs.
    # It launches 2 commands which will run in the directory specified by PGO_TRAINING_DIR.
    # First, it runs 'make all' in the Profile instrumented build area
    # Next it runs 'make test' to ensure that the profiling information is generated.
    # In this way, running 'make all' in the final build area guarantees that the Profile
    # instrumented training files will be re-compiled, then the test suite will be run
    # to generate new profiling files, before the final build version is compiled using
    # this profiling information.
    add_custom_target(run_training
        ALL
        WORKING_DIRECTORY ${PGO_TRAINING_DIR}
        COMMAND ${CMAKE_BUILD_TOOL} all
        COMMAND ${CMAKE_BUILD_TOOL} test
        VERBATIM)

    # Add the CMAKE_CXX_FLAGS_RELEASE so that a PGO optimized build also includes release flags
    SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE} ${PGO_COMPILE_FLAGS}" )

endif()
