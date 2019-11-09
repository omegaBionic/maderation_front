QT       += testlib
QT       += gui
QT       += network
QT       += core
CONFIG += qt warn_on depend_includepath testcase
CONFIG += qtc_runnable


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TEMPLATE = app


SOURCES +=  tst_test_app.cpp \
            ../app/database_classes/*.cpp \
            ../app/menu_toolbar.cpp \
            ../app/main_login.cpp \
            ../app/main_menu.cpp \
            ../app/api_get_request.cpp \
            ../app/Init.cpp \
            ../app/dialog_critical.cpp \
            ../app/encryption.cpp \
            ../app/controller.cpp

HEADERS += \
    ../app/database_classes/*.h \
    ../app/api_get_request.h \
    ../app/menu_toolbar.h \
    ../app/Init.h \
    ../app/dialog_critical.h \
    ../app/encryption.h \
    ../app/controller.h \
    ../app/main_menu.h \
    ../app/main_login.h

FORMS += \
    ../app/main_login.ui \
    ../app/main_menu.ui \
    ../app/dialog_critical.ui


qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


