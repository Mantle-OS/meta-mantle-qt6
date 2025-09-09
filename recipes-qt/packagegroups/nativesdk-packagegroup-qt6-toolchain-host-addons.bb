DESCRIPTION = "Qt6 development host addon packages"
LICENSE = "MIT"

# disable sanity check for allarch packagegroup
PACKAGE_ARCH = ""

inherit packagegroup nativesdk

PACKAGEGROUP_DISABLE_COMPLEMENTARY = "1"

RDEPENDS:${PN} += " \
    nativesdk-qtapplicationmanager6-dev \
    nativesdk-qtapplicationmanager6-tools \
    nativesdk-qtgrpc6-dev \
    nativesdk-qtgrpc6-tools \
    nativesdk-qtquick3d6-dev \
    nativesdk-qtquick3d6-tools \
    nativesdk-qtopcua6-dev \
    nativesdk-qtopcua6-tools \
    nativesdk-qtremoteobjects6-dev \
    nativesdk-qtremoteobjects6-tools \
    nativesdk-qtscxml6-dev \
    nativesdk-qtscxml6-tools \
    nativesdk-qtshadertools6-dev \
    nativesdk-qtshadertools6-tools \
    ${@bb.utils.contains('DISTRO_FEATURES', 'wayland', 'nativesdk-qtwayland6-dev nativesdk-qtwayland6-tools', '', d)} \
    ${FORLINUXHOST} \
"

FORLINUXHOST:mingw32 = ""
FORLINUXHOST = " \
    nativesdk-qtinterfaceframework6-dev nativesdk-qtinterfaceframework6-tools \
"

