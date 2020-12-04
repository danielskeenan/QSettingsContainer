from conans import ConanFile


class QSettingsContainerConan(ConanFile):
    name = "QSettingsContainer"
    version = "1.0.0"
    license = "BSL-1.0"
    author = "Dan Keenan <dk@dankeenan.org>"
    url = "<Package recipe repository url here, for issues about the package>"
    description = "Manage QSettings"
    topics = ("Qt",)
    exports_sources = "include/*"
    no_copy_source = True

    # No settings/options are necessary, this is header only

    def package(self):
        self.copy("*.h", keep_path=False, dst="include/dragoonboots/qsettingscontainer")

    def package_id(self):
        self.info.header_only()
