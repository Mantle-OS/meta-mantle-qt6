python() {
    if d.getVar('QT_EDITION') != 'commercial':
        raise bb.parse.SkipRecipe('Available only with Commercial Qt')
}

QT6_GIT = "${QT_COMMERCIAL_GIT}"
QT6_GIT_PROTOCOL = "${QT_COMMERCIAL_GIT_PROTOCOL}"
QT_MODULE = "tqtc-${BPN}"
