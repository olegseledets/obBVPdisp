#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include "connectionsettings.h"
#include "dispatcherwindow.h"
#include "datafromfile.h"

#include <QDialog>
#include <QtSql/QtSql>
#include <QMessageBox>
#include <QtSql/QSqlError>


namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);    // конструктор класса
    ~LoginWindow();                                     // деструктор класса

    void showEvent(QShowEvent *);                       // открытие формы ( подгрузка данных в логин из таблицы пользователи)
private slots:

    void on_butt_enter_clicked();                       // кнопка входа

    void on_butt_eyes_pressed();                        // показать пароль

    void on_butt_eyes_released();                       // скрыть пароль

    void on_butt_close_clicked();

signals:
    void sendData(QString str);

private:
    Ui::LoginWindow *ui;                                // текущее окно
    ConnectionSettings *adminWindow;                    // окно админа
    DispatcherWindow   *dispWindow;                     // окно диспетчера

};

#endif // LOGINWINDOW_H
