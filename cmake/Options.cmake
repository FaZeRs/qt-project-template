option(ENABLE_COVERAGE "Enable coverage reporting" OFF)
option(WARNINGS_AS_ERRORS "Treat Warnings As Errors" OFF)
option(ENABLE_SANITIZER_ADDRESS "Enable address sanitizer" OFF)
option(ENABLE_SANITIZER_LEAK "Enable leak sanitizer" OFF)
option(ENABLE_SANITIZER_UNDEFINED "Enable undefined sanitizer" OFF)
option(ENABLE_SANITIZER_THREAD "Enable thread sanitizer" OFF)
option(ENABLE_SANITIZER_MEMORY "Enable memory sanitizer" OFF)
option(ENABLE_CLANG_TIDY "Enable clang-tidy analysis" ON)
option(ENABLE_CPPCHECK "Enable cppcheck analysis" ON)
option(ENABLE_INCLUDE_WHAT_YOU_USE "include-what-you-use messages" ON)
option(ENABLE_CACHE "Enable ccache" ON)
option(COMPILE_TESTS "Compile tests" ON)
option(ENABLE_DOCS "Compile documentation" ON)
option(ENABLE_PCH "Enable precompiled headers" OFF)
option(USE_OPENMP "Build with OpenMP support" OFF)