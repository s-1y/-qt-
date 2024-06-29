QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cl.cpp \
    dialog.cpp \
    ds.cpp \
    lv.cpp \
    main.cpp \
    gamepage.cpp \
    tm.cpp

HEADERS += \
    cl.h \
    dialog.h \
    ds.h \
    gamepage.h \
    lv.h \
    tm.h

FORMS += \
    cl.ui \
    dialog.ui \
    gamepage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image/image.qrc
