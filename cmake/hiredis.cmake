# == hiredis build

set(HIREDIS_BINARY_DIR ${CMAKE_BINARY_DIR}/thirdparty/hiredis)
set(HIREDIS_SRC_DIR ${CMAKE_SOURCE_DIR}/thirdparty/hiredis)
file(MAKE_DIRECTORY ${HIREDIS_BINARY_DIR})

set(HIREDIS_LIB_SRC 
    ${HIREDIS_SRC_DIR}/async.c
    ${HIREDIS_SRC_DIR}/dict.c
    ${HIREDIS_SRC_DIR}/hiredis.c
    ${HIREDIS_SRC_DIR}/net.c
    ${HIREDIS_SRC_DIR}/read.c
    ${HIREDIS_SRC_DIR}/sds.c)
enable_language(C)
add_library(hiredis STATIC ${HIREDIS_LIB_SRC})
set_target_properties(hiredis PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${HIREDIS_BINARY_DIR})

set(HIREDIS_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/thirdparty/hiredis)
set(HIREDIS_LIBRARIES ${HIREDIS_BINARY_DIR}/libhiredis.a)
