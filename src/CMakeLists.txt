add_library(QSettingsContainer INTERFACE
    ${PROJECT_SOURCE_DIR}/include/QSettingsContainer.h
)
target_include_directories(QSettingsContainer INTERFACE
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
)
set_target_properties(QSettingsContainer PROPERTIES PUBLIC_HEADER "${PROJECT_SOURCE_DIR}/include/QSettingsContainer.h")

install(
    TARGETS QSettingsContainer
)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)
configure_package_config_file(
    "${PROJECT_SOURCE_DIR}/cmake/QSettingsContainer-config.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/QSettingsContainer-config.cmake"
    INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/QSettingsContainer"
)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/QSettingsContainer-version.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
    ARCH_INDEPENDENT
)
install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/QSettingsContainer-config.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/QSettingsContainer-version.cmake"
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/QSettingsContainer"
)
