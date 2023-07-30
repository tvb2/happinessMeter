QT       += core gui testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Hobby/hobbycrap.cpp \
        Hobby/hobbyno.cpp \
        Hobby/hobbyyes.cpp \
        Personal/ltr.cpp \
        Personal/str.cpp \
        Professional/busy.cpp \
        Health/healthexc.cpp \
        disclaimer.cpp \
        health.cpp \
        hobby.cpp \
        main.cpp \
        mainwindow.cpp \
        personal.cpp \
        professional.cpp \
        segment.cpp


HEADERS += \
        Hobby/hobbycrap.h \
        Hobby/hobbyno.h \
        Hobby/hobbyyes.h \
        Personal/ltr.h \
        Personal/str.h \
        Professional/busy.h \
        Health/healthexc.h \
        disclaimer.h \
        health.h \
        hobby.h \
        mainwindow.h \
        personal.h \
        professional.h \
        segment.h

FORMS += \
    Hobby/hobbycrap.ui \
    Hobby/hobbyno.ui \
    Hobby/hobbyyes.ui \
    Personal/ltr.ui \
    Personal/str.ui \
    Professional/busy.ui \
    Health/healthexc.ui \
    disclaimer.ui \
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
