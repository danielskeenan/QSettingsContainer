cmake_minimum_required(VERSION 3.16)

project(QSettingsContainer
    VERSION 1.0.0)

add_subdirectory(src)

option(QSETTINGSCONTAINER_BUILD_DOC "Build documentation" Off)
if (QSETTINGSCONTAINER_BUILD_DOC)
    add_subdirectory(doc)
endif ()
