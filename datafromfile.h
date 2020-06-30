#ifndef DATAFROMFILE_H
#define DATAFROMFILE_H

#include <qsettings.h>
#include <QString>
#include <QSqlDatabase>

static QString pathDateBaseFileSettings = "C:\\dbpool_sett\\";
static QString pathDateBaseSett = "C:\\dbpool_sett\\db_sett.ini";
static QString UserSett = "user_sett\\user_sett.ini";
static QString pathLogs = "user_logs\\";

static QSettings *dbpollSett = new QSettings(pathDateBaseSett,QSettings::IniFormat);                     //файл с настройками для чтения
static QSettings *userSett = new QSettings(UserSett, QSettings::IniFormat);

static QString driver_f = dbpollSett->value("database_connection/driver","").toString();                  //драйвер
static QString ip_f = dbpollSett->value("database_connection/ip","").toString();                          //айпишник
static QString port_f = dbpollSett->value("database_connection/port","").toString();                      //порт
static QString dbName_f = dbpollSett->value("database_connection/database_n","").toString();              //имя бд
static QString nameTable_c_f = dbpollSett->value("database_connection/table_cargo","").toString();        //имя таблицы грузоперевозок
static QString nameTable_p_f = dbpollSett->value("database_connection/table_passenger","").toString();    //имя таблицы пассажироперевозки
static QString userName_f = dbpollSett->value("database_connection/user_n","").toString();                //имя пользователя
static QString userPass_f = dbpollSett->value("database_connection/password","").toString();              //пароль

static QSqlDatabase db = QSqlDatabase::addDatabase(driver_f);

static QString nameCurrentUser = userSett->value("User_Settings/currentUser","").toString();

#endif // DATAFROMFILE_H
