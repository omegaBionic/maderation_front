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
    api_get_request.cpp \
    Init.cpp \
    bdd_address_client.cpp \
    bdd_address_supplier.cpp \
    bdd_category.cpp \
    bdd_chat.cpp \
    bdd_client.cpp \
    bdd_component.cpp \
    bdd_gamme.cpp \
    bdd_invoice_quotation.cpp \
    bdd_message.cpp \
    bdd_product.cpp \
    bdd_project.cpp \
    bdd_promotion_cat.cpp \
    bdd_promotion_comp.cpp \
    bdd_quotation.cpp \
    bdd_role.cpp \
    bdd_shop.cpp \
    bdd_status.cpp \
    bdd_stock.cpp \
    bdd_supplier.cpp \
    bdd_user.cpp \
    dialog_critical.cpp \
    encryption.cpp \
    main.cpp \
    main_login.cpp \
    menu_toolbar.cpp \
    uicontroller.cpp

HEADERS += \
    api_get_request.h \
    Init.h \
    bdd_address_client.h \
    bdd_address_supplier.h \
    bdd_category.h \
    bdd_chat.h \
    bdd_client.h \
    bdd_component.h \
    bdd_gamme.h \
    bdd_invoice_quotation.h \
    bdd_message.h \
    bdd_product.h \
    bdd_project.h \
    bdd_promotion_cat.h \
    bdd_promotion_comp.h \
    bdd_quotation.h \
    bdd_role.h \
    bdd_shop.h \
    bdd_status.h \
    bdd_stock.h \
    bdd_supplier.h \
    bdd_user.h \
    dialog_critical.h \
    encryption.h \
    menu_toolbar.h \
    uicontroller.h \
    main_login.h

FORMS += \
    dialog_critical.ui \
    main_login.ui \
    menu_toolbar.ui

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
