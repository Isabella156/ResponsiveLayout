QT += core gui widgets

CONFIG += c++11

SOURCES += \
        folder_compressor.cpp \
        main.cpp \
        responsive_label.cpp \
        responsive_layout.cpp \
        responsive_window.cpp \
        screenshot.cpp \
        scroll_layout.cpp \
        searchresultswidget.cpp

HEADERS += \
    folder_compressor.h \
    responsive_label.h \
    responsive_layout.h \
    responsive_window.h \
    screenshot.h \
    scroll_layout.h \
    searchresultswidget.h

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

