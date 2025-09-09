DESCRIPTION = "Qt6 essential modules"
LICENSE = "MIT"

PACKAGE_ARCH = "${MACHINE_ARCH}"

inherit packagegroup

PACKAGEGROUP_DISABLE_COMPLEMENTARY = "1"

RDEPENDS:${PN} += " \
    qtbase6 \
    qtdeclarative6 \
    qtdeclarative6-tools \
    qttools6 \
    qttools6-tools \
    qttranslations6-qtbase6 \
    qttranslations6-qtdeclarative6 \
"
