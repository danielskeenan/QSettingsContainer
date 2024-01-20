/**
 * @file QSettingsContainer.h
 *
 * @author Dan Keenan
 * @date 2020
 * @copyright Boost Software License, Version 1.0
 */

#ifndef QSETTINGSCONTAINER_INCLUDE_QSETTINGSCONTAINER_H_
#define QSETTINGSCONTAINER_INCLUDE_QSETTINGSCONTAINER_H_

#include <QSettings>
#include <QHash>

/**
 * Similar to @ref DGSETTINGS_SETTING, but uses different storage type and value types.
 *
 * @param val_T value type; must be castable using static_cast() to @p storage_t
 * @param storage_T storage type; must be storable in a [QVariant](https://doc.qt.io/qt-5/qvariant.html)
 * @param name Getter/setter name
 * @param default_val Default value to use if no value has previously been
 * stored; must be of type @p val_T
 *
 * @par Example
 * @code{.cpp}
 * DGSETTINGS_SETTING_CAST(Breed, unsigned int, PuppyBreed, Breed::Mix)
 * @endcode
 * results in the following method definitions:
 * @code{.cpp}
 * static Breed GetPuppyBreed();
 * static void SetPuppyBreed(Breed value);
 * static Breed GetDefaultPuppyBreed();
 * @endcode
 * casting the value to `unsigned int` when interfacing with QSettings.
 */
#define DGSETTINGS_SETTING_CAST(val_T, storage_T, name, default_val)          \
  static val_T Get##name() {                                                  \
    const QVariant val_variant = QSettings().value(#name);                    \
    if (!val_variant.isValid()) {                                             \
      return default_val;                                                     \
    }                                                                         \
    return static_cast<val_T>(val_variant.value<storage_T>());                \
  }                                                                           \
  /** Set @ref Get##name() */                                                 \
  static void Set##name(const val_T &val) {                                   \
    const auto val_storage = static_cast<storage_T>(val);                     \
    QSettings().setValue(#name, QVariant::fromValue<storage_T>(val_storage)); \
  }                                                                           \
  /** Default value for @ref Get##name() */                                   \
  static val_T GetDefault##name() {                                           \
    return default_val;                                                       \
  }                                                                           \

/**
 * Create a new setting that persists between executions.
 *
 * Defines three static methods: `Get<name>`, `Set<name>`, and `GetDefault<name>`.
 *
 * Settings are stored persistently using [QSettings](https://doc.qt.io/qt-5/qsettings.html);
 * for non-persistent state information, see @ref DGSETTINGS_STATE.
 *
 * For enum-type variables with a different storage type, see @ref DGSETTINGS_SETTING_CAST.
 *
 * @param T value type; must be storable in a [QVariant](https://doc.qt.io/qt-5/qvariant.html)
 * @param name Getter/setter name
 * @param default_val Default value to use if no value has previously been
 * stored; must be of type @p T
 *
 * @par Example
 * @code{.cpp}
 * DGSETTINGS_SETTING(int, Puppies, 0)
 * @endcode
 * results in the following method definitions:
 * @code{.cpp}
 * static int GetPuppies();
 * static void SetPuppies(int value);
 * static int GetDefaultPuppies();
 * @endcode
 */
#define DGSETTINGS_SETTING(T, name, default_val) DGSETTINGS_SETTING_CAST(T, T, name, default_val)

/**
 * Similar to @ref DGSETTINGS_STATE, but uses different storage type and value types.
 *
 * @param val_T value type; must be castable using static_cast() to @p storage_t
 * @param storage_T storage type; must be storable in a [QVariant](https://doc.qt.io/qt-5/qvariant.html)
 * @param name Getter/setter name
 * @param default_val Default value to use if no value has previously been
 * stored; must be of type @p val_T
 *
 * @par Example
 * @code{.cpp}
 * DGSETTINGS_STATE_CAST(LogLevel, unsigned int, Logging, LogLevel::Warn)
 * @endcode
 * results in the following method definitions:
 * @code{.cpp}
 * static LogLevel GetLogging();
 * static void SetLogging(LogLevel value);
 * static LogLevel GetDefaultLogging();
 * @endcode
 * casting the value to `unsigned int` so it may be stored in memory.
 */
#define DGSETTINGS_STATE_CAST(val_T, storage_T, name, default_val)       \
  static val_T Get##name() {                                             \
    if (!state_.contains(#name)) {                                       \
      return default_val;                                                \
    }                                                                    \
    return static_cast<val_T>(state_.value(#name).value<storage_T>());   \
  }                                                                      \
  /** Set @ref Get##name() */                                            \
  static void Set##name(const val_T &val) {                              \
    state_[#name] = static_cast<storage_T>(val);                         \
  }                                                                      \
   /** Get default for @ref Get##name() */                               \
  static val_T GetDefault##name() {                                      \
    return default_val;                                                  \
  }                                                                      \

/**
 * Create a new global state variable.
 *
 * State information does not persist between executions.
 * For persistent storage, see @ref DGSETTINGS_SETTING.
 *
 * For enum-type variables with a different storage type, see @ref DGSETTINGS_STATE_CAST.
 *
 * @param T value type; must be storable in a [QVariant](https://doc.qt.io/qt-5/qvariant.html)
 * @param name Getter/setter name
 * @param default_val Default value to use if no value has previously been
 * stored; must be of type @p T
 *
 * @par Example
 * @code{.cpp}
 * DGSETTINGS_STATE(bool, DebugMode, false)
 * @endcode
 * results in the following method definitions:
 * @code{.cpp}
 * static bool GetDebugMode();
 * static void SetDebugMode(bool value);
 * static bool GetDefaultDebugMode();
 * @endcode
 */
#define DGSETTINGS_STATE(T, name, default_val) DGSETTINGS_STATE_CAST(T, T, name, default_val)

namespace qsettingscontainer {

/**
 * Settings container
 *
 * Use @ref DGSETTINGS_SETTING, @ref DGSETTINGS_SETTING_CAST, @ref DGSETTINGS_STATE,
 * and @ref DGSETTINGS_STATE_CAST to define settings.
 *
 * Get/set settings using the static methods defined after using the above macros.
 */
class QSettingsContainer {
 public:
  QSettingsContainer() = delete;
  QSettingsContainer(const QSettingsContainer &) = delete;
  QSettingsContainer(QSettingsContainer &&) = delete;

  /** Clear all settings */
  static void Clear() { QSettings().clear(); }

  /** Sync settings to/from storage */
  static void Sync() { QSettings().sync(); }

 protected:
  static inline QHash<QString, QVariant> state_;
};

} // qsettingscontainer

#endif //QSETTINGSCONTAINER_INCLUDE_QSETTINGSCONTAINER_H_

