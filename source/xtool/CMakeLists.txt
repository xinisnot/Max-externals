cmake_minimum_required(VERSION 3.10)
project(xtool)

if (${CMAKE_GENERATOR} MATCHES "Xcode")
    if (${XCODE_VERSION} VERSION_LESS 10)
        message(STATUS "Xcode 10 is required. Please install from the Mac App Store.")
            return ()
    endif ()
endif ()

file(GLOB_RECURSE XTOOL_HEADERS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)
add_custom_target(XTOOL ALL SOURCES ${XTOOL_HEADERS})