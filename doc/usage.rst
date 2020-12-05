Usage
=====

Conan
-----

See available packages `here <https://gitlab.com/dragoonboots-packages/qsettingscontainer/-/packages>`_.

1. Setup the Conan remote:

.. code-block:: bash

   conan remote add "qsettingscontainer" "https://gitlab.com/api/v4/projects/22902505/packages/conan"

2. Install the package:

.. code-block:: bash
   :substitutions:

   conan install "QSettingsContainer/|version|@dragoonboots-packages+qsettingscontainer/stable" --remote="qsettingscontainer"

CMake FetchContent
------------------
.. code-block:: cmake
   :substitutions:

   include(FetchContent)
   FetchContent_Declare(
     QSettingsContainer
     GIT_REPOSITORY "git@gitlab.com:dragoonboots-packages/qsettingscontainer.git"
     GIT_TAG        1.0.0
   )
   FetchContent_MakeAvailable(QSettingsContainer)
   target_link_libraries(<YOUR_TARGET> PRIVATE QSettingsContainer)
