QT += core gui
QT += qml quick
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14
CONFIG += qt

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
QT += network
QT +=sql
include($$PWD/qsyncable/qsyncable.pri)

CONFIG += qt thread
# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH += $$PWD/include
INCLUDEPATH += $$PWD/3dparty/mavlink_v2
INCLUDEPATH += $$PWD/3dparty/mavlink_v2ardupilotmega



FORMS += \
    drone_units.ui \
    dronelist.ui \
    dronewindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    3dparty/mavlink_v2/message_definitions/ASLUAV.xml \
    3dparty/mavlink_v2/message_definitions/all.xml \
    3dparty/mavlink_v2/message_definitions/ardupilotmega.xml \
    3dparty/mavlink_v2/message_definitions/autoquad.xml \
    3dparty/mavlink_v2/message_definitions/common.xml \
    3dparty/mavlink_v2/message_definitions/icarous.xml \
    3dparty/mavlink_v2/message_definitions/matrixpilot.xml \
    3dparty/mavlink_v2/message_definitions/minimal.xml \
    3dparty/mavlink_v2/message_definitions/paparazzi.xml \
    3dparty/mavlink_v2/message_definitions/python_array_test.xml \
    3dparty/mavlink_v2/message_definitions/standard.xml \
    3dparty/mavlink_v2/message_definitions/test.xml \
    3dparty/mavlink_v2/message_definitions/uAvionix.xml \
    3dparty/mavlink_v2/message_definitions/ualberta.xml \ \
    qsyncable-1.0.2/qsyncable-1.0.2/qsyncable.pri \
    setting.json

OTHER_FILES += $$PWD/qml/qml_mainwindow.qml





HEADERS += $$PWD/include/*.h \
    include/delegate.h \
    include/drone.h \
    include/drone_container.h


SOURCES += $$PWD/src/*.cpp \
    include/delegate.cpp \
    include/drone.cpp \
    include/drone_container.cpp \
    main.cpp

RESOURCES += \
    qml/res.qrc



