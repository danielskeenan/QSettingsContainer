Usage
=====

CMake FetchContent
------------------
.. code-block:: cmake
   :substitutions:

   include(FetchContent)
   FetchContent_Declare(
     QSettingsContainer
     GIT_REPOSITORY "https://github.com/danielskeenan/QSettingsContainer.git"
     GIT_TAG        v|version|
   )
   FetchContent_MakeAvailable(QSettingsContainer)
   target_link_libraries(<YOUR_TARGET> PRIVATE QSettingsContainer)
