cmake_minimum_required(VERSION 3.21)

project(QSettingsContainer
    VERSION 2.0.0
    DESCRIPTION "A header-only library designed to simplify interacting with QSettings storage"
    HOMEPAGE_URL "https://github.com/danielskeenan/QSettingsContainer"
)
set(PROJECT_AUTHOR "Dan Keenan")

add_subdirectory(src)

option(QSETTINGSCONTAINER_BUILD_DOC "Build documentation" Off)
if (QSETTINGSCONTAINER_BUILD_DOC)
    add_subdirectory(doc)
endif ()
