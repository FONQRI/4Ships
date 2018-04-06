INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

# Enable very detailed debug messages when compiling the debug version
CONFIG(debug, debug|release) {
    DEFINES += SUPERVERBOSE
}
HEADERS += $$_PRO_FILE_PWD_/src/FEngine/Graphics/fanimationpng.h

SOURCES += $$_PRO_FILE_PWD_/src/FEngine/Graphics/fanimationpng.cpp
