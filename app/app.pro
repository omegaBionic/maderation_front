QT       += core gui
QT       += network
CONFIG += qt warn_on depend_includepath testcase
CONFIG += qtc_runnable

TEMPLATE = app

RC_ICONS = icon/logo.ico


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ./DB_CLASSES/*.cpp \
    ./CONTROLLER/*.cpp \
    ./CORE/*.cpp \
    ./UI/*.cpp \
    CORE/core_quotation.cpp \
    main.cpp


HEADERS += \
    ./DB_CLASSES/*.h \
    ./CONTROLLER/*.h \
    ./CORE/*.h \
    ./UI/*.h \
    CORE/core_quotation.h


FORMS += \
    ./UI/*.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    data_picture.qrc


DISTFILES += \
    android-sources/AndroidManifest.xml \
    android-sources/build.gradle \
    android-sources/gradle/wrapper/gradle-wrapper.jar \
    android-sources/gradle/wrapper/gradle-wrapper.properties \
    android-sources/gradlew \
    android-sources/gradlew.bat \
    android-sources/res/values/libs.xml
