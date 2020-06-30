#include "connectionsettings.h"
#include "ui_connectionsettings.h"
#include "datafromfile.h"

ConnectionSettings::ConnectionSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectionSettings)
{
    ui->setupUi(this);
    ui->date_log->setDate(QDate::currentDate());
}

ConnectionSettings::~ConnectionSettings()
{
    delete ui;
}

void ConnectionSettings::on_butt_exit_clicked()
{
    clearConnectionSet();
    this->close();                                                                                                      // Закрываем окно
    emit openLoginWindow();                                                                                             // И вызываем сигнал на открытие главного окна
}

void ConnectionSettings::on_butt_baseCheck_clicked()
{
    if (ui->text_checkDBName->text().isEmpty())
    {
        QMessageBox::warning(this,
                            ("Ошибка"),
                            ("Не указано имя БД"));
    }
    else
    {
       // if (db.open())
    }
}

void ConnectionSettings::clearConnectionSet()
{
    ui->cbox_driver->currentText() = "";
    ui->text_ip->setText("");
    ui->text_port->setText("");
    ui->text_DBname->setText("");
    ui->text_userName->setText("");
    ui->text_userPass->setText("");
    ui->text_nameTablePass->setText("");
    ui->text_nameTableCargo->setText("");

    ui->text_checkDBName->setText("");
    ui->cbox_checkTableName->setCurrentIndex(-1);
    ui->text_loadLogName->setText("");
    ui->text_saveLogName->setText("");
}

void ConnectionSettings::on_butt_saveSettFile_clicked()
{
    if (ui->text_saveLogName->text() == "")
    {
        QMessageBox::critical(NULL,QObject::tr("Ошибка"),"Имя не введено");                                            // Сообщение если логин не верен
    }
    else
    {
        QString pathNewSettFile = pathDateBaseFileSettings+ui->text_saveLogName->text()+".ini";                         // Имя файла сохранения                                                     // Путь к сохранению + имя
        QFileInfo infoPath(pathNewSettFile);
        QString fullPath2 = infoPath.absoluteFilePath();
        QSettings *dbsett = new QSettings(pathNewSettFile,QSettings::IniFormat);

        dbsett->setValue("database_connection/driver", ui->cbox_driver->currentText());
        dbsett->setValue("database_connection/ip", ui->text_ip->text());
        dbsett->setValue("database_connection/port", ui->text_port->text());
        dbsett->setValue("database_connection/database_n", ui->text_DBname->text());
        dbsett->setValue("database_connection/table_cargo", ui->text_nameTableCargo->text());
        dbsett->setValue("database_connection/table_passenger", ui->text_nameTablePass->text());
        dbsett->setValue("database_connection/user_n", ui->text_userName->text());
        dbsett->setValue("database_connection/password", ui->text_userPass->text());

        dbsett->sync();


        QMessageBox *msgBox = new QMessageBox(QMessageBox::Information,"Exit","Установить эти настройки по умолчанию?",
        QMessageBox::Yes| QMessageBox::Cancel);

           if(msgBox->exec() == QMessageBox::Yes)
           {
               // удаление староко
               // переименовка нового
           }

          delete msgBox;
        clearConnectionSet();
        QMessageBox::information(this,
                                 ("Сохранение настроек"),
                                 ("Сохранение настроек выполнено успешно"));
        delete dbsett;
    }
}

void ConnectionSettings::on_butt_loadSettFile_clicked()
{
    QString loadPathSettFile = QFileDialog::getOpenFileName(this,
                                                        tr("Открыть файл настроек"),pathDateBaseFileSettings,
                                                        tr("Настройки проекта (*.ini)"));

    QFile f(loadPathSettFile);                                              //создаем объект с адресом файла и его именем
    QString filename(QFileInfo(f.fileName()).fileName());                                  //переводим в строковый формат

    QSettings *nSett = new QSettings(loadPathSettFile,QSettings::IniFormat);
    ui->text_loadLogName->setText(filename);

    ui->text_ip->setText(nSett->value("database_connection/ip","").toString());
    ui->text_port->setText(nSett->value("database_connection/port","").toString());
    ui->text_DBname->setText(nSett->value("database_connection/database_n","").toString());
    ui->text_nameTableCargo->setText(nSett->value("database_connection/table_cargo","").toString());
    ui->text_userName->setText(nSett->value("database_connection/user_n","").toString());
    ui->text_nameTablePass->setText(nSett->value("database_connection/table_passenger","").toString());
    ui->text_userPass->setText(nSett->value("database_connection/password","").toString());
    ui->cbox_driver->setCurrentText(nSett->value("database_connection/driver","").toString());
}
