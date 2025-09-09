DESCRIPTION = "Qt6 addon modules"
LICENSE = "MIT"

PACKAGE_ARCH = "${MACHINE_ARCH}"

inherit packagegroup

PACKAGEGROUP_DISABLE_COMPLEMENTARY = "1"

RDEPENDS:${PN} += " \
    ${@'python3-pyside6' if bb.utils.to_boolean(d.getVar('CAN_USE_PYSIDE6')) else ''} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'opengl', 'qt3d6', '', d)} \
    qt5compat6 \
    qtapplicationmanager6 \
    qtcharts6 \
    qtcoap6 \
    qtconnectivity6 \
    ${@bb.utils.contains('DISTRO_FEATURES', 'opengl', 'qtdatavis3d6', '', d)} \
    qtdeviceutilities6 \
    qtdoc \
    qtgraphs \
    qtgrpc6 \
    qthttpserver6 \
    qtimageformats6 \
    qtinterfaceframework6 \
    qtlocation6 \
    qtlottie6 \
    qtmqtt6 \
    qtmultimedia6 \
    qtnetworkauth6 \
    qtopcua6 \
    qtpositioning6 \
    qtquick3d6 \
    qtquickdesigner-components6 \
    qtquicktimeline6 \
    qtremoteobjects6 \
    qtscxml6 \
    qtsensors6 \
    qtserialbus6 \
    qtserialbus6-tools \
    qtserialport6 \
    qtshadertools6 \
    qtspeech6 \
    qtsvg6 \
    qttranslations6 \
    qtvirtualkeyboard6 \
    ${@bb.utils.contains('DISTRO_FEATURES', 'wayland', 'qtwayland6', '', d)} \
    qtwebchannel6 \
    qtwebsockets6 \
"

RDEPENDS:${PN}:append:aarch64 = "\
    qtquick3d6physics \
    ${@bb.utils.contains('DISTRO_FEATURES', 'opengl', 'qtpdf6', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'webengine', 'qtwebengine6 qtwebview6', '', d)} \
"
RDEPENDS:${PN}:append:arm = " qtquick3d6physics"
RDEPENDS:${PN}:append:armv6 = "\
    ${@bb.utils.contains('DISTRO_FEATURES', 'opengl', 'qtpdf6', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'webengine', 'qtwebengine6 qtwebview6', '', d)} \
"
RDEPENDS:${PN}:append:armv7a = "\
    ${@bb.utils.contains('DISTRO_FEATURES', 'opengl', 'qtpdf6', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'webengine', 'qtwebengine6 qtwebview6', '', d)} \
"
RDEPENDS:${PN}:append:armv7ve = "\
    ${@bb.utils.contains('DISTRO_FEATURES', 'opengl', 'qtpdf6', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'webengine', 'qtwebengine6 qtwebview6', '', d)} \
"
RDEPENDS:${PN}:append:x86 = " qtquick3d6physics"
RDEPENDS:${PN}:append:x86-64 = "\
    qtquick3d6physics \
    ${@bb.utils.contains('DISTRO_FEATURES', 'opengl', 'qtpdf6', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'webengine', 'qtwebengine6 qtwebview6', '', d)} \
"
