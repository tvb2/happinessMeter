QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        ltr.cpp \
        main.cpp \
        mainwindow.cpp \
        notbusy.cpp \
        professionallife.cpp \
        str.cpp \
        ztr.cpp

HEADERS += \
        ltr.h \
        notbusy.h \
        professionallife.h \
        mainwindow.h \
        str.h \
        ztr.h


FORMS += \
    ltr.ui \
        mainwindow.ui \
    notbusy.ui \
	professionallife.ui \
    str.ui \
    ztr.ui
DISTFILES += \
    android/AndroidManifest.xml \
    android/build.gradle \
    android/gradle.properties \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew \
    android/gradlew.bat \
    android/values/libs.xml

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

contains(ANDROID_TARGET_ARCH,arm64-v8a) {
    ANDROID_PACKAGE_SOURCE_DIR = \
        $$PWD/android
}