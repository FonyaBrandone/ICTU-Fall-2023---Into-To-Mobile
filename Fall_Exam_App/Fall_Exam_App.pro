QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 3): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    source/database.cpp \
    source/main.cpp \
    source/mainwindow.cpp

HEADERS += \
    include/employee.h \
    include/mainwindow.h \
    include/Database.h \
    include/Database_Api.h

FORMS += \
    form_ui/mainwindow.ui
RESOURCES += \
    assets/Fall_exam.db

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
