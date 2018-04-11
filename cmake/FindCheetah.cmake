# Find the native CHEETAH includes and library
#
#  Can request specific components (default is all components)
#  If all the requested components have been found, CHEETAH_FOUND will be set to true
#  Components:
#    cmake - Just the Cheetah cmake components. e.g. set CHEETAH_SOURCE_DIR to point to the source.
#            This will set the following variables:
#               CHEETAH_cmake_FOUND - true or false
#               CHEETAH_cmake_MODULE_PATH  - directory found containing the cheetah exported cmake modules
#                                   this could be used e.g.
#                                       list(APPEND cmake_MODULE_PATH ${CHEETAH_cmake_MODULE_PATH})
#    libs - The Cheetah libraries and header files
#            This will set the following variables:
#               CHEETAH_LIBRARIES      - List of libraries when using cheetah.
#               CHEETAH_TEST_LIBRARIES - List of cheetah test support libraries
#               CHEETAH_LIBRARY_DIR - directory where cheetah libraries were found
#               CHEETAH_INCLUDE_DIR - directory where cheetah includes were found
#
#    Example:   find_package(Cheetah REQUIRED cmake) - Would only require Cheetah Source directory to be present.
#
#
#  The following variables can be set to explicitly specify the locations of cheetah components in order of precedence
#  CHEETAH_LIBRARY_DIR - explicitly define directory where to find cheetah libraries
#  CHEETAH_INCLUDE_DIR - where to find cheetah includes
#  CHEETAH_MODULES_DIR - where to find cheetah modules
#  CHEETAH_SOURCE_DIR  - Top of the Cheetah source files directory
#  CHEETAH_INSTALL_DIR - Top where cheetah framwork has been installed (lib and include dirs included)

INCLUDE(FindPackageHandleCompat)

# If no component explicitly requested, then default to everything
IF (NOT CHEETAH_FIND_COMPONENTS)
    SET(CHEETAH_FIND_COMPONENTS libs cmake)
ENDIF (NOT CHEETAH_FIND_COMPONENTS)

# Spin through all components
FOREACH(component ${CHEETAH_FIND_COMPONENTS})
    string(TOLOWER ${component} component)
    IF(${component} MATCHES "cmake")
        # -- exported cmake modules
        IF (CHEETAH_MODULES_DIR)
            SET(CHEETAH_MOD_DIR ${CHEETAH_MODULES_DIR})
            UNSET(CHEETAH_MODULES_DIR)
        ENDIF (CHEETAH_MODULES_DIR)
        FIND_PATH(CHEETAH_MODULES_DIR cheetah/cmake/FindPanda.cmake
                "${CHEETAH_MOD_DIR}"
                "${CHEETAH_SOURCE_DIR}"
                "${CHEETAH_INSTALL_DIR}/share"
                /usr/local/share
                /usr/share )

        FIND_PACKAGE_HANDLE_STANDARD_ARGS(CHEETAH_MODULES DEFAULT_MSG CHEETAH_MODULES_DIR)

        # Append cmake path to CHEETAH_MODULE_PATH (It should be last)
        IF(CHEETAH_MODULES_FOUND)
            SET(CHEETAH_CMAKE_MODULE_PATH "${CHEETAH_MODULES_DIR}/cheetah/cmake")
            SET(CHEETAH_cmake_FOUND true) # - for dependency checking
        ELSE(CHEETAH_MODULES_FOUND)
            SET(CHEETAH_cmake_FOUND false)
        ENDIF(CHEETAH_MODULES_FOUND)

    ENDIF(${component} MATCHES "cmake")

    IF(${component} MATCHES "libs")
        # -- include files
        IF (CHEETAH_INCLUDE_DIR)
            SET(CHEETAH_INC_DIR ${CHEETAH_INCLUDE_DIR})
            UNSET(CHEETAH_INCLUDE_DIR)
        ENDIF (CHEETAH_INCLUDE_DIR)
        FIND_PATH(CHEETAH_INCLUDE_DIR cheetah/version.h
            PATHS ${CHEETAH_INC_DIR}
              ${CHEETAH_SOURCE_DIR}
              ${CHEETAH_INSTALL_DIR}/include
              /usr/local/include
              /usr/include )
        message("Found CHEETAH_INCLUDE_DIR : ${CHEETAH_INCLUDE_DIR}")

        # -- libraries
        SET(CHEETAH_NAMES cheetah)
        FOREACH( lib ${CHEETAH_NAMES} )
            FIND_LIBRARY(CHEETAH_LIBRARY_${lib}
        	NAMES ${lib}
        	PATHS ${CHEETAH_LIBRARY_DIR} ${CHEETAH_INSTALL_DIR} ${CHEETAH_INSTALL_DIR}/lib /usr/local/lib /usr/lib
            )
            LIST(APPEND CHEETAH_LIBRARIES ${CHEETAH_LIBRARY_${lib}})
        ENDFOREACH(lib)

        # -- test libraries
        SET(CHEETAH_TEST_NAMES cheetah_test_utils)
        FOREACH( lib ${CHEETAH_TEST_NAMES} )
            FIND_LIBRARY(CHEETAH_LIBRARY_${lib}
        	NAMES ${lib}
        	PATHS ${CHEETAH_LIBRARY_DIR} ${CHEETAH_LIBRARY_DIR}/test ${CHEETAH_INSTALL_DIR}/lib /usr/local/lib /usr/lib
            )
            LIST(APPEND CHEETAH_TEST_LIBRARIES ${CHEETAH_LIBRARY_${lib}})
        ENDFOREACH(lib)
	LIST(APPEND CHEETAH_TEST_LIBRARIES ${PANDA_TEST_LIBRARIES})

        # handle the QUIETLY and REQUIRED arguments and set CHEETAH_FOUND to TRUE if.
        # all listed variables are TRUE
        FIND_PACKAGE_HANDLE_STANDARD_ARGS(CHEETAH_LIBS DEFAULT_MSG CHEETAH_LIBRARIES CHEETAH_INCLUDE_DIR)

        SET( CHEETAH_libs_FOUND ${CHEETAH_LIBS_FOUND}) # required for component checking
        IF(NOT CHEETAH_LIBS_FOUND)
            SET( CHEETAH_LIBRARIES )
            SET( CHEETAH_TEST_LIBRARIES )
        ENDIF(NOT CHEETAH_LIBS_FOUND)

        MARK_AS_ADVANCED(CHEETAH_LIBRARIES CHEETAH_TEST_LIBRARIES CHEETAH_INCLUDE_DIR)

    ENDIF(${component} MATCHES "libs")

ENDFOREACH(component)

# Handle components
# I HAVE to supply a required variable - so give it one. All other required variables are dealt with above.
# This call to FPHSV is just to correctly handle the components
SET(CHEETAH_a_required_var 1)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(CHEETAH REQUIRED_VARS CHEETAH_a_required_var HANDLE_COMPONENTS)
UNSET(CHEETAH_a_required_var)
