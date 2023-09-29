set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

configure_file("config.h.in" "${CMAKE_BINARY_DIR}/configured_files/include/config.h" ESCAPE_QUOTES)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Gui Widgets)
qt_standard_project_setup()

set(SOURCE_FILES
    main.cpp
    core/application.cpp
    core/settings.cpp
    widgets/main_window.cpp
    widgets/settings_dialog.cpp)

qt_add_executable(${CMAKE_PROJECT_NAME}
        ${SOURCE_FILES})

set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
    rs::project_options
    rs::project_warnings
)

if (USE_OPENMP)
	find_package(OpenMP)
  if(OpenMP_CXX_FOUND)
    target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC OpenMP::OpenMP_CXX)
	else()
    message(${WARNING_MESSAGE} "OpenMP requested but library not found")
  endif()
endif()

target_link_system_libraries(${CMAKE_PROJECT_NAME} PRIVATE
    Qt::Core
    Qt::Gui
    Qt::Widgets)

if (USE_SPDLOG)
  target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE USE_SPDLOG)
  target_link_system_libraries(${CMAKE_PROJECT_NAME} PRIVATE spdlog::spdlog)
endif()

if (USE_SENTRY)
  target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE USE_SENTRY)
  target_link_system_libraries(${CMAKE_PROJECT_NAME} PRIVATE sentry::sentry)
endif()

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE "${CMAKE_BINARY_DIR}/configured_files/include")
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE QT_MESSAGELOGCONTEXT)

if(ENABLE_PCH AND NOT ENABLE_CLANG_TIDY)
  target_precompile_headers(${CMAKE_PROJECT_NAME} PUBLIC pch.h)
endif()

# Install the executable into "${CMAKE_INSTALL_PREFIX}/bin".
install(TARGETS ${CMAKE_PROJECT_NAME}
    BUNDLE DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

# Generate the deployment script for the target RoomSketcher.
qt_generate_deploy_app_script(
    TARGET ${CMAKE_PROJECT_NAME}
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR)

# Call the deployment script on "cmake --install".
install(SCRIPT ${deploy_script})
