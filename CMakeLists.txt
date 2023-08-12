cmake_minimum_required(VERSION 3.21)

include(cmake/Version.cmake)

project(room-sketcher
  VERSION ${VERSION_SHORT}
  DESCRIPTION "Floor Plan Editor"
  HOMEPAGE_URL "https://giraffe360.com"
  LANGUAGES CXX C)

include(cmake/Options.cmake)
include(cmake/CompilationFlags.cmake)
include(cmake/SystemLink.cmake)

include(cmake/Dependencies.cmake)
setup_dependencies()

add_library(project_warnings INTERFACE)
add_library(project_options INTERFACE)

include(cmake/CompilerWarnings.cmake)
set_project_warnings(project_warnings ${WARNINGS_AS_ERRORS} "" "" "")

include(cmake/Sanitizers.cmake)
enable_sanitizers(project_options
        ${ENABLE_SANITIZER_ADDRESS}
        ${ENABLE_SANITIZER_LEAK}
        ${ENABLE_SANITIZER_UNDEFINED}
        ${ENABLE_SANITIZER_THREAD}
        ${ENABLE_SANITIZER_MEMORY})

if(ENABLE_PCH)
  target_precompile_headers(
    project_options
    INTERFACE
    <vector>
    <string>
    <utility>)
endif()

if(ENABLE_CACHE)
  include(cmake/Cache.cmake)
  enable_cache()
endif()

if(ENABLE_COVERAGE)
  include(cmake/CodeCoverage.cmake)
  enable_coverage(project_options)
endif()

target_compile_features(project_options INTERFACE cxx_std_${CMAKE_CXX_STANDARD})

add_library(rs::project_options ALIAS project_options)
add_library(rs::project_warnings ALIAS project_warnings)

add_subdirectory(src)

include(cmake/CPack.cmake)

if(COMPILE_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()

if (ENABLE_DOCS)
  include(cmake/Doxygen.cmake)
  enable_doxygen("")
endif()

message(STATUS "Version: ${PROJECT_VERSION}")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Release cxx: ${CMAKE_CXX_FLAGS_RELEASE}")
message(STATUS "Debug cxx: ${CMAKE_CXX_FLAGS_DEBUG}")
message(STATUS " ")

if(BUILD_TYPE STREQUAL "release")
  message(STATUS "Complete cxx: ${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE}")
  message(STATUS "Complete ld: ${CMAKE_EXE_LINKER_FLAGS} ${CMAKE_EXE_LINKER_FLAGS_RELEASE}")
else()
  message(STATUS "Complete cxx: ${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG}")
  message(STATUS "Complete ld: ${CMAKE_EXE_LINKER_FLAGS} ${CMAKE_EXE_LINKER_FLAGS_DEBUG}")
endif()
