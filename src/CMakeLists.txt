add_library(QSettingsContainer INTERFACE)
target_include_directories(QSettingsContainer INTERFACE ${PROJECT_SOURCE_DIR}/include)

install(
    DIRECTORY ${PROJECT_SOURCE_DIR}/include/
    TYPE INCLUDE
)
