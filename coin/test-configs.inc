# use systemd
INIT_MANAGER:forcevariable = "systemd"

INHERIT += "buildstats buildstats-summary"
INHERIT += "rm_work"

# default to commercial Qt
QT_EDITION = "commercial"

LICENSE_FLAGS_ACCEPTED = "commercial_ffmpeg"

# include commercial addons and enable Qt QML Compiler
QT_COMMERCIAL_MODULES = "1"

# fast compression of SDK tar package
SDK_XZ_COMPRESSION_LEVEL = "-1"

# be more strict with QA warnings, turn them all to errors:
EXTRA_QA = "\
    ldflags useless-rpaths rpaths staticdev libdir xorg-driver-abi \
    textrel already-stripped incompatible-license files-invalid \
    installed-vs-shipped compile-host-path install-host-path \
    pn-overrides infodir build-deps \
    unknown-configure-option symlink-to-sysroot multilib \
    invalid-packageconfig host-user-contaminated uppercase-pn \
"
ERROR_QA:append = "${EXTRA_QA}"
WARN_QA:remove = "${EXTRA_QA}"

# workaround for qemu
# nativesdk-qemu-user-mips rdepends on nativesdk-bash, but it isn't a build dependency
INSANE_SKIP:nativesdk-qemu-user-mips = "build-deps"

# workaround for clang
# nativesdk-liblldb contains reference to TMPDIR [buildpaths]
INSANE_SKIP:append:pn-nativesdk-clang = " buildpaths"

# enable thumb for broader test coverage (oe-core autobuilder doesn't have thumb enabled)
PREFERRED_ARM_INSTRUCTION_SET              ?= "thumb"
ARM_INSTRUCTION_SET = "${PREFERRED_ARM_INSTRUCTION_SET}"

# build squish
USE_SQUISH = "1"
SQUISH_MIRROR = "https://ci-files01-hki.ci.qt.io/input/squish/releasepackages"
SQUISH_LICENSE_KEY = "qt-srv-19.intra.qt.io:49345"

# enable webengine with commercial/proprietary features
DISTRO_FEATURES:append = " webengine"
PACKAGECONFIG:append:pn-qtwebengine6 = " proprietary-codecs"

PACKAGECONFIG:append:pn-qtbase6 = "\
    tslib kms gbm zstd libproxy gssapi vulkan mtdev cups \
    sql-mysql sql-odbc sql-psql sql-sqlite journald brotli \
    ${@bb.utils.contains('DISTRO_FEATURES', 'x11', 'gtk', '', d)} \
"

# imageformats mng FIXME
PACKAGECONFIG:append:pn-qtimageformats6 = " jasper"

# enable examples for all Qt modules
PACKAGECONFIG:append:pn-qmlcompilerplus = " examples"
PACKAGECONFIG:append:pn-qt3d6 = " examples"
PACKAGECONFIG:append:pn-qt5compat6 = " examples"
PACKAGECONFIG:append:pn-qtapplicationmanager6 = " examples"
PACKAGECONFIG:append:pn-qtbase6 = " examples"
PACKAGECONFIG:append:pn-qtcharts6 = " examples"
PACKAGECONFIG:append:pn-qtcoap6 = " examples"
PACKAGECONFIG:append:pn-qtconnectivity6 = " examples"
PACKAGECONFIG:append:pn-qtdatavis3d6 = " examples"
PACKAGECONFIG:append:pn-qtdeclarative6 = " examples"
PACKAGECONFIG:append:pn-qtdeviceutilities6 = " examples"
PACKAGECONFIG:append:pn-qtgraphs = " examples"
PACKAGECONFIG:append:pn-qtgrpc6 = " examples"
PACKAGECONFIG:append:pn-qthttpserver6 = " examples"
PACKAGECONFIG:append:pn-qtimageformats6 = " examples"
PACKAGECONFIG:append:pn-qtinsighttracker6 = " examples"
PACKAGECONFIG:append:pn-qtinterfaceframework6 = " examples"
PACKAGECONFIG:append:pn-qtlanguageserver6 = " examples"
PACKAGECONFIG:append:pn-qtlocation6 = " examples"
PACKAGECONFIG:append:pn-qtlottie6 = " examples"
PACKAGECONFIG:append:pn-qtmqtt6 = " examples"
PACKAGECONFIG:append:pn-qtmultimedia6 = " examples"
PACKAGECONFIG:append:pn-qtnetworkauth6 = " examples"
PACKAGECONFIG:append:pn-qtopcua6 = " examples"
PACKAGECONFIG:append:pn-qtpdf6 = " examples"
PACKAGECONFIG:append:pn-qtpositioning6 = " examples"
PACKAGECONFIG:append:pn-qtquick3d6 = " examples"
PACKAGECONFIG:append:pn-qtquick3d6physics = " examples"
PACKAGECONFIG:append:pn-qtquickdesigner-components6 = " examples"
PACKAGECONFIG:append:pn-qtquicktimeline6 = " examples"
PACKAGECONFIG:append:pn-qtremoteobjects6 = " examples"
PACKAGECONFIG:append:pn-qtscxml6 = " examples"
PACKAGECONFIG:append:pn-qtsensors6 = " examples"
PACKAGECONFIG:append:pn-qtserialbus6 = " examples"
PACKAGECONFIG:append:pn-qtserialport6 = " examples"
PACKAGECONFIG:append:pn-qtshadertools6 = " examples"
PACKAGECONFIG:append:pn-qtspeech6 = " examples"
PACKAGECONFIG:append:pn-qtsvg6 = " examples"
PACKAGECONFIG:append:pn-qttools6 = " examples"
PACKAGECONFIG:append:pn-qttranslations6 = " examples"
PACKAGECONFIG:append:pn-qtvirtualkeyboard6 = " examples"
PACKAGECONFIG:append:pn-qtvncserver6 = " examples"
PACKAGECONFIG:append:pn-qtwayland6 = " examples"
PACKAGECONFIG:append:pn-qtwebchannel6 = " examples"
PACKAGECONFIG:append:pn-qtwebengine6 = " examples"
PACKAGECONFIG:append:pn-qtwebsockets6 = " examples"
PACKAGECONFIG:append:pn-qtwebview6 = " examples"
