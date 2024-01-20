from conans import ConanFile, CMake


class QSettingsContainerConan(ConanFile):
    name = "QSettingsContainer"
    version = "1.0.0"
    license = "BSL-1.0"
    author = "Dan Keenan <dk@dankeenan.org>"
    url = "https://github.com/danielskeenan/QSettingsContainer"
    description = "A header-only library designed to simplify interacting with QSettings storage"
    topics = ("Qt",)
    exports_sources = "include/*", "src/*", "CMakeLists.txt"
    # no_copy_source = True

    # No settings/options are necessary, this is header only

    def _configure_cmake(self):
        cmake = CMake(self)
        cmake.configure()
        return cmake

    def package(self):
        cmake = self._configure_cmake()
        cmake.install()

    def package_id(self):
        self.info.header_only()
