find_program(sphinx_PROG sphinx-build)
if (NOT sphinx_PROG)
    message(FATAL_ERROR "Cannot find sphinx-build")
endif ()
find_package(Doxygen REQUIRED)

get_target_property(qsettingscontainer_SOURCES QSettingsContainer INTERFACE_SOURCES)
get_target_property(qsettingscontainer_INCLUDES QSettingsContainer INTERFACE_INCLUDE_DIRECTORIES)
set(DOXYGEN_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/api")
set(DOXYGEN_JAVADOC_AUTOBRIEF YES)
set(DOXYGEN_SORT_BRIEF_DOCS NO)
set(DOXYGEN_SORT_MEMBER_DOCS NO)
set(DOXYGEN_EXTRACT_ALL YES)
set(DOXYGEN_GENERATE_XML YES)
doxygen_add_docs(qsettingscontainer_api
    ${qsettingscontainer_INCLUDES}
    ${qsettingscontainer_SOURCES})

add_custom_target(qsettingscontainer_doc
    COMMENT "Building HTML documentation"
    COMMAND ${sphinx_PROG} -b=html "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_BINARY_DIR}/html" "-Dbreathe_projects.QSettingsContainer=${DOXYGEN_OUTPUT_DIRECTORY}/xml"
    BYPRODUCTS "${PROJECT_BINARY_DIR}/doc/html"
    DEPENDS qsettingscontainer_api
    )
