include(cmake/modules/CPM.cmake)

function(setup_dependencies)
    find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core)
    if(NOT TARGET sentry::sentry)
        CPMAddPackage(
          NAME sentry
          VERSION 0.6.2
          GITHUB_REPOSITORY getsentry/sentry-native
          GIT_TAG "0.6.2"
          OPTIONS "SENTRY_INTEGRATION_QT ON" "SENTRY_BUILD_TESTS OFF" "SENTRY_BUILD_EXAMPLES OFF"
          SYSTEM YES
        )
    endif()

    if(NOT TARGET spdlog::spdlog)
        CPMAddPackage(
            NAME spdlog
            VERSION 1.11.0
            GITHUB_REPOSITORY gabime/spdlog
            SYSTEM YES
        )
    endif()
endfunction()
