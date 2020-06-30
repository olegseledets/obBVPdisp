QT       += core
QT       += gui
QT       += sql

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
    adduser.cpp \
    connectionsettings.cpp \
    filterwindow.cpp \
    loginwindow.cpp \
    main.cpp \
    dispatcherwindow.cpp \
    searchwindow.cpp

HEADERS += \
    adduser.h \
    connectionsettings.h \
    datafromfile.h \
    dispatcherwindow.h \
    filterwindow.h \
    loginwindow.h \
    searchwindow.h

FORMS += \
    adduser.ui \
    connectionsettings.ui \
    dispatcherwindow.ui \
    filterwindow.ui \
    loginwindow.ui \
    searchwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    res/icon/i_About/icons8-о-нас-50.png \
    res/icon/i_About/icons8-обратная-связь-50.png \
    res/icon/i_About/icons8-помощь-50.png \
    res/icon/i_Administation/icons8-бассейн-50.png \
    res/icon/i_Administation/icons8-грузовое-судно-50-2.png \
    res/icon/i_Administation/icons8-грузовое-судно-50.png \
    res/icon/i_Administation/icons8-изменить-пользователя-50.png \
    res/icon/i_Administation/icons8-карта-россии-50.png \
    res/icon/i_Administation/icons8-компас-50.png \
    res/icon/i_Administation/icons8-отмеченный-грузовик-50.png \
    res/icon/i_Administation/icons8-пассажир-с-багажом-50.png \
    res/icon/i_Administation/icons8-поверхность-50.png \
    res/icon/i_Administation/icons8-пункт-самовывоза-50.png \
    res/icon/i_Administation/icons8-редактировать-свойство-50.png \
    res/icon/i_Administation/icons8-свернуть-окно-50.png \
    res/icon/i_Administation/icons8-север-50.png \
    res/icon/i_Logo/icons8-грузовое-судно-50.png \
    res/icon/i_Report/icons8-бизнес-отчет-50.png \
    res/icon/i_Tasc/icons8-галочка-50.png \
    res/icon/i_Tasc/icons8-добавить-50.png \
    res/icon/i_Tasc/icons8-задание-выполнено-50.png \
    res/icon/i_Tasc/icons8-редактировать-50.png \
    res/icon/i_Tasc/icons8-удалить-50.png \
    res/icon/i_Transportation/icons8-cегодня-50.png \
    res/icon/i_Transportation/icons8-все -таблицы.png \
    res/icon/i_Transportation/icons8-добавить-50.png \
    res/icon/i_Transportation/icons8-звездочка-50.png \
    res/icon/i_Transportation/icons8-ок-50.png \
    res/icon/i_Transportation/icons8-основные-таблицы.png \
    res/icon/i_Transportation/icons8-поиск-50.png \
    res/icon/i_Transportation/icons8-редактировать-50.png \
    res/icon/i_Transportation/icons8-удалить-50.png

RESOURCES += \
    res/icon/icon.qrc
