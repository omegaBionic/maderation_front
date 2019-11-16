QT       += testlib
QT       += gui
QT       += network
QT       += core
CONFIG += qt warn_on depend_includepath testcase
CONFIG += qtc_runnable


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TEMPLATE = app


SOURCES +=  \
            tst_test_app.cpp \
            ../app/DB_CLASSES/*.cpp \
            ../app/CORE/*.cpp \
            ../app/UI/*.cpp \
            ../app/CONTROLLER/*.cpp

HEADERS += \
            ../app/DB_CLASSES/*.h \
            ../app/CORE/*.h \
            ../app/UI/*.h \
            ../app/CONTROLLER/*.h


FORMS += \
            ../app/UI/*.ui


qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


