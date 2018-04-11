# thirdparty dependencies
include(cmake/googletest.cmake)
include(compiler_settings)

include(cmake/boost.cmake)
find_package(Panda REQUIRED)
find_package(Cheetah REQUIRED)
find_package(AstroAccelerate)
include(cmake/hiredis.cmake)

include_directories(SYSTEM ${Boost_INCLUDE_DIR} ${CHEETAH_INCLUDE_DIR} ${PANDA_INCLUDE_DIR})
if(ASTROACCELERATE_FOUND)
    include_directories(SYSTEM ${ASTROACCELERATE_INCLUDE_DIR})
endif(ASTROACCELERATE_FOUND)
set(DEPENDENCY_LIBRARIES
    ${CHEETAH_LIBRARIES}
    ${ASTROACCELERATE_LIBRARIES}
    ${PANDA_LIBRARIES}
    ${Boost_LIBRARIES}
    ${HIREDIS_LIBRARIES}
)

include(cmake/cuda.cmake)

