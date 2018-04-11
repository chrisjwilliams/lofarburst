# Find the native PANDA includes and library
#
#  Can request specific components (default is all components)
#  If all the requested components have been found, PANDA_FOUND will be set to true
#  Components:
#    cmake - Just the Panda cmake components. e.g. set PANDA_SOURCE_DIR to point to the source.
#            This will set the following variables:
#               PANDA_cmake_FOUND - true or false
#               PANDA_cmake_MODULE_PATH  - directory found containing the panda exported cmake modules
#                                   this could be used e.g.
#                                       list(APPEND cmake_MODULE_PATH ${PANDA_cmake_MODULE_PATH})
#    libs - The Panda libraries and header files
#            This will set the following variables:
#               PANDA_LIBRARIES      - List of libraries when using panda.
#               PANDA_TEST_LIBRARIES - List of panda test support libraries
#               PANDA_LIBRARY_DIR - directory where panda libraries were found
#               PANDA_INCLUDE_DIR - directory where panda includes were found
#
#    Example:   find_package(Panda REQUIRED cmake) - Would only require Panda Source directory to be present.
#
#
#  The following variables can be set to explicitly specify the locations of panda components in order of precedence
#  PANDA_LIBRARY_DIR - explicitly define directory where to find panda libraries
#  PANDA_INCLUDE_DIR - where to find panda includes
#  PANDA_MODULES_DIR - where to find panda modules
#  PANDA_SOURCE_DIR  - Top of the Panda source files directory
#  PANDA_INSTALL_DIR - Top where panda framwork has been installed (lib and include dirs included)

INCLUDE(FindPackageHandleCompat)

# If no component explicitly requested, then default to everything
IF (NOT PANDA_FIND_COMPONENTS)
    SET(PANDA_FIND_COMPONENTS libs cmake)
ENDIF (NOT PANDA_FIND_COMPONENTS)

# Spin through all components
FOREACH(component ${PANDA_FIND_COMPONENTS})
    string(TOLOWER ${component} component)
    IF(${component} MATCHES "cmake")
        # -- exported cmake modules
        IF (PANDA_MODULES_DIR)
            SET(PANDA_MOD_DIR ${PANDA_MODULES_DIR})
            UNSET(PANDA_MODULES_DIR)
        ENDIF (PANDA_MODULES_DIR)
        FIND_PATH(PANDA_MODULES_DIR panda/cmake/git_version.cmake
                "${PANDA_MOD_DIR}"
                "${PANDA_SOURCE_DIR}"
                "${PANDA_INSTALL_DIR}/share"
                /usr/local/share
                /usr/share )

        FIND_PACKAGE_HANDLE_STANDARD_ARGS(PANDA_MODULES DEFAULT_MSG PANDA_MODULES_DIR)

        # Append cmake path to PANDA_MODULE_PATH (It should be last)
        IF(PANDA_MODULES_FOUND)
            SET(PANDA_CMAKE_MODULE_PATH "${PANDA_MODULES_DIR}/panda/cmake")
            SET(PANDA_cmake_FOUND true) # - for dependency checking
        ELSE(PANDA_MODULES_FOUND)
            SET(PANDA_cmake_FOUND false)
        ENDIF(PANDA_MODULES_FOUND)

    ENDIF(${component} MATCHES "cmake")

    IF(${component} MATCHES "libs")
        # -- include files
        IF (PANDA_INCLUDE_DIR)
            SET(PANDA_INC_DIR ${PANDA_INCLUDE_DIR})
            UNSET(PANDA_INCLUDE_DIR)
        ENDIF (PANDA_INCLUDE_DIR)
        FIND_PATH(PANDA_INCLUDE_DIR panda/Version.h
            PATHS ${PANDA_INC_DIR}
              ${PANDA_SOURCE_DIR}
              ${PANDA_INSTALL_DIR}/include
              /usr/local/include
              /usr/include )
        message("Found PANDA_INCLUDE_DIR : ${PANDA_INCLUDE_DIR}")

        # -- libraries
        SET(PANDA_NAMES panda)
        FOREACH( lib ${PANDA_NAMES} )
            FIND_LIBRARY(PANDA_LIBRARY_${lib}
        	NAMES ${lib}
        	PATHS ${PANDA_LIBRARY_DIR} ${PANDA_INSTALL_DIR} ${PANDA_INSTALL_DIR}/lib /usr/local/lib /usr/lib
            )
            LIST(APPEND PANDA_LIBRARIES ${PANDA_LIBRARY_${lib}})
        ENDFOREACH(lib)

        # -- test libraries
        SET(PANDA_TEST_NAMES panda_testutils)
        FOREACH( lib ${PANDA_TEST_NAMES} )
            FIND_LIBRARY(PANDA_LIBRARY_${lib}
        	NAMES ${lib}
        	PATHS ${PANDA_LIBRARY_DIR} ${PANDA_LIBRARY_DIR}/test ${PANDA_INSTALL_DIR}/lib /usr/local/lib /usr/lib
            )
            LIST(APPEND PANDA_TEST_LIBRARIES ${PANDA_LIBRARY_${lib}})
        ENDFOREACH(lib)

        # handle the QUIETLY and REQUIRED arguments and set PANDA_FOUND to TRUE if.
        # all listed variables are TRUE
        FIND_PACKAGE_HANDLE_STANDARD_ARGS(PANDA_LIBS DEFAULT_MSG PANDA_LIBRARIES PANDA_INCLUDE_DIR)

        SET( PANDA_libs_FOUND ${PANDA_LIBS_FOUND}) # required for component checking
        IF(NOT PANDA_LIBS_FOUND)
            SET( PANDA_LIBRARIES )
            SET( PANDA_TEST_LIBRARIES )
        ENDIF(NOT PANDA_LIBS_FOUND)

        MARK_AS_ADVANCED(PANDA_LIBRARIES PANDA_TEST_LIBRARIES PANDA_INCLUDE_DIR)

    ENDIF(${component} MATCHES "libs")

ENDFOREACH(component)

# Handle components
# I HAVE to supply a required variable - so give it one. All other required variables are dealt with above.
# This call to FPHSV is just to correctly handle the components
SET(PANDA_a_required_var 1)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(PANDA REQUIRED_VARS PANDA_a_required_var HANDLE_COMPONENTS)
UNSET(PANDA_a_required_var)
