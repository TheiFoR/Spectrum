QT += quick widgets quickcontrols2 qml printsupport opengl gui openglwidgets charts core

include($$PWD/libqnanopainter/include.pri)

SOURCES += \
        main.cpp \
        spectrum/painter/universalchartpainter.cpp \
        spectrum/painter/universalpainter.cpp \
        spectrum/universalchart.cpp

resources.files = main.qml 
resources.prefix = /$${TARGET}
RESOURCES += resources

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    spectrum/painter/universalchartpainter.h \
    spectrum/painter/universalpainter.h \
    spectrum/universalchart.h
