API
===

Configuring the code style
--------------------------

QSettingsContainer supports three popular naming conventions. Control which
naming convention is used by defining the matching preprocessor macro either
in your buildsystem or before including the QSettingsContainer.h header file.

The default is lowerCamelCase.

.. csv-table::
   :header: "Style", "Macro"
   :widths: auto

   "lowerCamelCase", ``DGSETTINGS_CODESTYLE_LOWER_CAMEL_CASE``
   "UpperCamelCase", ``DGSETTINGS_CODESTYLE_UPPER_CAMEL_CASE``
   "lower_snake_case", ``DGSETTINGS_CODESTYLE_LOWER_SNAKE_CASE``

Usage
-----

.. doxygenclass:: qsettingscontainer::QSettingsContainer

.. doxygendefine:: DGSETTINGS_SETTING

.. doxygendefine:: DGSETTINGS_SETTING_CAST

.. doxygendefine:: DGSETTINGS_STATE

.. doxygendefine:: DGSETTINGS_STATE_CAST
