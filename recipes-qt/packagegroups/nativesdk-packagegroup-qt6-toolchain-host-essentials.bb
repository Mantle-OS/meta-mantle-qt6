DESCRIPTION = "Qt6 development host essential packages"
LICENSE = "MIT"

# disable sanity check for allarch packagegroup
PACKAGE_ARCH = ""

inherit packagegroup nativesdk

PACKAGEGROUP_DISABLE_COMPLEMENTARY = "1"

RDEPENDS:${PN} += " \
    nativesdk-qtbase6-dev \
    nativesdk-qtbase6-tools \
    nativesdk-qtdeclarative6-dev \
    nativesdk-qtdeclarative6-tools \
    nativesdk-qttools6-dev \
    nativesdk-qttools6-tools \
"
