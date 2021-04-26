Usage
=====

Conan
-----

See available packages `here <https://dragoonboots.jfrog.io/ui/packages>`_.

1. Setup the Conan remote:

.. code-block:: bash

   conan remote add <REMOTE> https://dragoonboots.jfrog.io/artifactory/api/conan/conan-packages

2. Install the package:

.. code-block:: bash
   :substitutions:

   conan install "QSettingsContainer/|version|@dragoonboots/stable" --remote <REMOTE>

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
