#include "dispatcherwindow.h"
#include "loginwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DispatcherWindow w;
    LoginWindow lw;
    //w.showMaximized();
    lw.show();
    return a.exec();
}

