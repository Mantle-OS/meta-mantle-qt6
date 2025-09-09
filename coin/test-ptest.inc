IMAGE_CLASSES += "testimage"
QB_MEM = "-m 8192"
TEST_SUITES = "ssh ping parselogs ptest"
IMAGE_FEATURES += "ssh-server-dropbear"
IMAGE_INSTALL:append = "\
    ${@bb.utils.contains('DISTRO_FEATURES', 'opengl', 'qt3d6-ptest', '', d)} \
    qt5compat6-ptest \
    qtbase6-ptest \
    qtcharts6-ptest \
    qtcoap6-ptest \
    qtconnectivity6-ptest \
    ${@bb.utils.contains('DISTRO_FEATURES', 'opengl', 'qtdatavis3d6-ptest', '', d)} \
    qtdeclarative6-ptest \
    qtdeviceutilities6-ptest \
    qtgraphs-ptest \
    qtgrpc6-ptest \
    qthttpserver6-ptest \
    qtimageformats6-ptest \
    qtinterfaceframework6-ptest \
    qtlocation6-ptest \
    qtlottie6-ptest \
    qtmqtt6-ptest \
    qtmultimedia6-ptest \
    qtnetworkauth6-ptest \
    qtopcua6-ptest \
    qtpositioning6-ptest \
    qtquick3d6-ptest \
    qtquickdesigner-components6-ptest \
    qtquicktimeline6-ptest \
    qtremoteobjects6-ptest \
    qtscxml6-ptest \
    qtsensors6-ptest \
    qtserialbus6-ptest \
    qtserialport6-ptest \
    qtshadertools6-ptest \
    qtspeech6-ptest \
    qtsvg6-ptest \
    qttools6-ptest \
    qtvirtualkeyboard6-ptest \
    ${@bb.utils.contains('DISTRO_FEATURES', 'wayland', 'qtwayland6-ptest', '', d)} \
    qtwebchannel6-ptest \
    qtwebsockets6-ptest \
    ${@bb.utils.contains('DISTRO_FEATURES', 'webengine', 'qtpdf6-ptest', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'webengine', 'qtwebengine6-ptest', '', d)} \
    ${@bb.utils.contains('DISTRO_FEATURES', 'webengine', 'qtwebview6-ptest', '', d)} \
    ${@bb.utils.contains('QT_COMMERCIAL_MODULES', '1', '\
        qmlcompilerplus-ptest \
        qtinsighttracker6-ptest \
        qtvncserver6-ptest \
        ', '', d)} \
"
