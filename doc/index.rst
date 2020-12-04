Welcome to QSettingsContainer's documentation!
==============================================

.. toctree::
   :maxdepth: 2
   :caption: Contents:

**QSettingsContainer** is designed to simplify interacting with `QSettings <https://doc.qt.io/qt-5/qsettings.html>`_
storage.  Instead of using error-prone string constants and casting the result,
a specific API is defined for stored settings.

Example
-------

.. code-block:: c++
   :caption: Before

   #include <QSettings>

   QSettings settings;
   settings.setValue("interval", 30);
   settings.value("interval").toInt();     // returns 30

.. code-block:: c++
   :caption: After

   #include <dragoonboots/qsettingscontainer/QSettingsContainer.h>

   class Settings : public dragoonboots::qsettingscontainer::QSettingsContainer {
    public:
     DGSETTINGS_SETTING(int, Interval, 0)
   };

   // ---Snip---

   Settings::GetInterval();     // returns 0
   Settings::SetInterval(30);
   Settings::GetInterval();     // returns 30

Indices and tables
==================

* :ref:`genindex`
* :ref:`modindex`
* :ref:`search`