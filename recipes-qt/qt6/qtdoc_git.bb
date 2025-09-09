LICENSE = "(The-Qt-Company-Commercial | GPL-3.0-only & GFDL-1.3-no-invariants-only & BSD-3-Clause) & Apache-2.0 & CC-BY-4.0 & CC-BY-SA-4.0 & ISC"
LIC_FILES_CHKSUM = " \
    file://LICENSES/Apache-2.0.txt;md5=b4c615f64dff32f71eeed614d13dfd4c \
    file://LICENSES/BSD-3-Clause.txt;md5=cb40fa7520502d8c7a3aea47cae1316c \
    file://LICENSES/CC-BY-4.0.txt;md5=ed88d31cea57b15030a1f58ceb04e0d5 \
    file://LICENSES/CC-BY-SA-4.0.txt;md5=7130783469368ceb248a4f03e89ea4b8 \
    file://LICENSES/GFDL-1.3-no-invariants-only.txt;md5=a22d0be1ce2284b67950a4d1673dd1b0 \
    file://LICENSES/GPL-3.0-only.txt;md5=d32239bcb673463ab874e80d47fae504 \
    file://LICENSES/ISC.txt;md5=2494cdbaca137fd93842fe9702e9bc4d \
    file://LICENSES/LicenseRef-Qt-Commercial.txt;md5=caa060942f6b722bc4329d4195584c38 \
"

inherit qt6-cmake

include recipes-qt/qt6/qt6-git.inc
include recipes-qt/qt6/qt6.inc

DEPENDS += "\
    qtbase6 \
    qtcharts6 \
    qtdeclarative6 qtdeclarative6-native \
    qtgraphs \
    qtlocation6 \
    qtmultimedia6 \
    qtpositioning6 \
    qtquick3d6 qtquick3d6-native \
    qtsensors6 \
    qtshadertools6-native \
    qtsvg6 \
    qtwebsockets6 \
"
DEPENDS:append:aarch64 = " ${@bb.utils.contains('DISTRO_FEATURES', 'opengl', 'qtpdf6', '', d)} qtquick3d6physics"
DEPENDS:append:arm = " qtquick3d6physics"
DEPENDS:append:armv6 = " ${@bb.utils.contains('DISTRO_FEATURES', 'opengl', 'qtpdf6', '', d)}"
DEPENDS:append:armv7a = " ${@bb.utils.contains('DISTRO_FEATURES', 'opengl', 'qtpdf6', '', d)}"
DEPENDS:append:armv7ve = " ${@bb.utils.contains('DISTRO_FEATURES', 'opengl', 'qtpdf6', '', d)}"
DEPENDS:append:x86 = " qtquick3d6physics"
DEPENDS:append:x86-64 = " ${@bb.utils.contains('DISTRO_FEATURES', 'opengl', 'qtpdf6', '', d)} qtquick3d6physics"

PACKAGECONFIG ?= "examples"

INSANE_SKIP:${PN}-ptest += "buildpaths"
