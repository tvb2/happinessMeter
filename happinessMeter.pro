QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Hobby/hobbycrap.cpp \
        Hobby/hobbyno.cpp \
        Hobby/hobbywork.cpp \
        Hobby/hobbyyes.cpp \
        Personal/ltr.cpp \
        Personal/str.cpp \
        Personal/ztr.cpp \
        Professional/busy.cpp \
        Professional/notbusy.cpp \
        main.cpp \
        mainwindow.cpp \
        segment.cpp


HEADERS += \
        Hobby/hobbycrap.h \
        Hobby/hobbyno.h \
        Hobby/hobbywork.h \
        Hobby/hobbyyes.h \
        Personal/ltr.h \
        Personal/str.h \
        Personal/ztr.h \
        Professional/busy.h \
        Professional/notbusy.h \
        mainwindow.h \
        segment.h

FORMS += \
    Hobby/hobbycrap.ui \
    Hobby/hobbyno.ui \
    Hobby/hobbywork.ui \
    Hobby/hobbyyes.ui \
    Personal/ltr.ui \
    Personal/str.ui \
    Personal/ztr.ui \
    Professional/busy.ui \
    Professional/notbusy.ui \
    mainwindow.ui

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
