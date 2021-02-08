Usage
=====

Conan
-----

See available packages `here <https://bintray.com/dragoonboots/conan-packages/QSettingsContainer%3Adragoonboots>`_.

1. Setup the Conan remote:

.. code-block:: bash

   conan remote add "dragoonboots" "https://api.bintray.com/conan/dragoonboots/conan-packages"

2. Install the package:

.. code-block:: bash
   :substitutions:

   conan install "QSettingsContainer/|version|@dragoonboots/stable" --remote="dragoonboots"

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
