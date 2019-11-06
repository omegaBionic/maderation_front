TEMPLATE = subdirs

SUBDIRS += \
    app \
    tests

CONFIG += qtc_runnable


ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android-sources
