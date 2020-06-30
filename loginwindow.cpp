#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    adminWindow = new ConnectionSettings();
    connect(adminWindow, &ConnectionSettings::openLoginWindow, this, &LoginWindow::show);

    dispWindow = new DispatcherWindow();
    connect(dispWindow, &DispatcherWindow::openLoginWindow, this, &LoginWindow::show);

    this->setWindowFlags(Qt::CustomizeWindowHint);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
}

bool ConnectionDB()                                                                     // подключение БД
{
    QSqlDatabase db = QSqlDatabase::addDatabase(driver_f);
    db.setHostName(ip_f);
    db.setPort(port_f.toInt());
    db.setDatabaseName(dbName_f);
    db.setUserName(userName_f);
    db.setPassword(userPass_f);
    return db.open();
}

void LoginWindow::showEvent(QShowEvent *)                                               // открытие формы
{
    if (ConnectionDB())                                                                 // подключение к бд
    {
        QSqlQueryModel *model = new QSqlQueryModel();
        QString sql;
        sql = "SELECT UserLogin FROM users";                     //***// можно загрузить из файла!
        QSqlQuery query;
        query.prepare(sql);
        query.exec();
        model->setQuery(query);
        ui->cbox_login->setModel(model);
        ui->cbox_login->addItem("");
        ui->cbox_login->setCurrentIndex(-1);
    }
}

LoginWindow::~LoginWindow()
{
    delete ui;                                                                          // деструктор класса
}

void LoginWindow::on_butt_enter_clicked()
{
    QSqlQuery query;                                                                    // Объект запроса
    QString login = ui->cbox_login->currentText();                                      // Логин из комбобокса
    QString password = ui->text_password->text();                                       // Введенный пароль

    query.exec("SELECT UserPassword FROM users WHERE UserLogin = '"+login+"'");         // Просим базу дать нам пароль под текущий логин
    query.first();
    QString verifyPass = query.value(0).toString();                                     // Получаем настоящий пароль от пользователя

    query.exec("SELECT AccessLevel FROM users WHERE UserLogin = '"+login+"'");          // Просим базу дать нам пароль под текущий логин
    query.first();
    QString userAccessLevel = query.value(0).toString();                                // Получаем настоящий пароль от пользователя

    if(verifyPass != password)
    {
        QMessageBox::critical(NULL,QObject::tr("Ошибка"),"Пароль не верен");            // Сообщение если логин не верен
    }
    else{
        QSettings *uSett = new QSettings(UserSett,QSettings::IniFormat);
        uSett->setValue("User_Settings/currentUser", ui->cbox_login->currentText());
        uSett->sync();
        ui->text_password->setText("");
        if (userAccessLevel == "1")
        {
            adminWindow->show();                                                        // Показываем окно админа
            this->close();                                                              // Закрываем основное окно
        }
        else if (userAccessLevel == "2")
        {
            dispWindow->show();                                                         // Показываем окно диспетчера
            this->close();                                                              // Закрываем основное окно

            QMessageBox msg;
            msg.setIconPixmap(QPixmap(":/i_Logo/icons8-грузовое-судно-50.png"));
            msg.setWindowTitle("Приветствие");
            msg.setText("Добро пожаловать: "+login+"!");
            msg.setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
            msg.exec();
        }
    }
}

void LoginWindow::on_butt_eyes_pressed()
{
    ui->text_password->setEchoMode(QLineEdit::Normal);                                  // показать пароль
}

void LoginWindow::on_butt_eyes_released()
{
    ui->text_password->setEchoMode(QLineEdit::Password);                                // скрыть пароль
}

void LoginWindow::on_butt_close_clicked()
{
    this->close();
}
