#include "dispatcherwindow.h"
#include "dispatcherwindow.h"
#include "ui_dispatcherwindow.h"


DispatcherWindow::DispatcherWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DispatcherWindow)
{
    ui->setupUi(this);

        trayIcon = new QSystemTrayIcon(this);                                                                           // Начало действия трея
        trayIcon->setIcon(QIcon(":/i_Logo/icons8-грузовое-судно-50.png"));
        trayIcon->setToolTip("Диспетчерский отдел 1.0");

        QMenu * menu = new QMenu(this);
        QAction * viewWindow = new QAction("Развернуть окно", this);
        QAction * quitAction = new QAction("Выход", this);

        connect(viewWindow, SIGNAL(triggered()), this, SLOT(show()));
        connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));

        menu->addAction(viewWindow);
        menu->addAction(quitAction);

        trayIcon->setContextMenu(menu);
        trayIcon->show();

        connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
                this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));                                          // конец действия трея

        filterWind = new filterWindow();
        connect(filterWind, &filterWindow::openFilterWindow, this, &DispatcherWindow::show);

}

template<typename T>
void DispatcherWindow::ColumnHeadersPassengers(T &model)
{
    model.setHeaderData(0, Qt::Horizontal, "Первичный\nКлюч");
    model.setHeaderData(1, Qt::Horizontal, "№ \nсудо-потока");
    model.setHeaderData(2, Qt::Horizontal, "Наименование\n судна");
    model.setHeaderData(3, Qt::Horizontal, "Флаг");
    model.setHeaderData(4, Qt::Horizontal, "Проект\n судна");
    model.setHeaderData(5, Qt::Horizontal, "Состав\n судна");
    model.setHeaderData(6, Qt::Horizontal, "Проект\n состава");
    model.setHeaderData(7, Qt::Horizontal, "Судовладелец");
    model.setHeaderData(8, Qt::Horizontal, "Груз \n(пассажиры)");
    model.setHeaderData(9, Qt::Horizontal, "Тоннаж \n(балласт)");
    model.setHeaderData(10, Qt::Horizontal, "Осадка \n(см)");
    model.setHeaderData(11, Qt::Horizontal, "Пункт \nотправления");
    model.setHeaderData(12, Qt::Horizontal, "Местополож.\n(река, \nкм с.х.)");
    model.setHeaderData(13, Qt::Horizontal, "Дата выхода\n из пункта \nотправления");
    model.setHeaderData(14, Qt::Horizontal, "Пункт \nназначения");
    model.setHeaderData(15, Qt::Horizontal, "Местополож.\n(река, \nкм с.х.)2");
    model.setHeaderData(16, Qt::Horizontal, "Дата прибытия\n в пункт \nназначения");
    model.setHeaderData(17, Qt::Horizontal, "Дата отметки\n судна при \nпересечении\n границы бассейна");
    model.setHeaderData(18, Qt::Horizontal, "Наименование \nбассейна");
    model.setHeaderData(19, Qt::Horizontal, "Диспетчер ");
    model.setHeaderData(20, Qt::Horizontal, "Алтай");
    model.setHeaderData(21, Qt::Horizontal, "НСО");
    model.setHeaderData(22, Qt::Horizontal, "Томск");
    model.setHeaderData(23, Qt::Horizontal, "Виды\nперевозок");

    model.setHeaderData(24, Qt::Horizontal, "о. Талецкое");
    model.setHeaderData(25, Qt::Horizontal, "1 2 \nСлияние -\nБарнаул");
    model.setHeaderData(26, Qt::Horizontal, "3 \nБарнаул -\nКамень");
    model.setHeaderData(27, Qt::Horizontal, "Камень -\nМалетино");
    model.setHeaderData(28, Qt::Horizontal, "4 \nКамень -\nНПК");
    model.setHeaderData(29, Qt::Horizontal, "Малетино -\nНПК");
    model.setHeaderData(30, Qt::Horizontal, "Аванпорт -\nНПК");
    model.setHeaderData(31, Qt::Horizontal, "6\nНПК -\nТомь");
    model.setHeaderData(32, Qt::Horizontal, "7\nТомь -\nНерга");
    model.setHeaderData(33, Qt::Horizontal, "8\nНерга -\nСоснино");
    model.setHeaderData(34, Qt::Horizontal, "Устье Томи -\nСоснино");
    model.setHeaderData(35, Qt::Horizontal, "Бердь");
    model.setHeaderData(36, Qt::Horizontal, "1 7\nНовокузнецк -\nТомск");
    model.setHeaderData(37, Qt::Horizontal, "1 8\nТомск -\nУстье");
    model.setHeaderData(38, Qt::Horizontal, "Васюган");
    model.setHeaderData(39, Qt::Horizontal, "Нюролька");
    model.setHeaderData(40, Qt::Horizontal, "Чулым");
    model.setHeaderData(41, Qt::Horizontal, "Кеть");
    model.setHeaderData(42, Qt::Horizontal, "Прочие");
    model.setHeaderData(43, Qt::Horizontal, "Грузооборот");
    model.setHeaderData(44, Qt::Horizontal, "Габариты\nСудна");
    model.setHeaderData(45, Qt::Horizontal, "Габариты\nСостава");
    model.setHeaderData(46, Qt::Horizontal, "Габариты\nСудопотока");
    model.setHeaderData(47, Qt::Horizontal, "Среднее\nРасстояние");
    model.setHeaderData(48, Qt::Horizontal, "Сумма\nРасстояний\nПо плесам");
    model.setHeaderData(49, Qt::Horizontal, "Истина\nЛожь\nКМ");
    model.setHeaderData(50, Qt::Horizontal, "Оборот\nМодуля\nСудопотока");
    model.setHeaderData(51, Qt::Horizontal, "ОМ по\nплесам");
    model.setHeaderData(52, Qt::Horizontal, "Истина\nЛожь\nОМ");

    model.setHeaderData(53, Qt::Horizontal, "Слияние -\nБарнаул\nКМ");
    model.setHeaderData(54, Qt::Horizontal, "Барнаул -\nКамень\nКМ");
    model.setHeaderData(55, Qt::Horizontal, "Камень -\nШлюз\nКМ");
    model.setHeaderData(56, Qt::Horizontal, "Малетино -\nШлюз\nКМ");
    model.setHeaderData(57, Qt::Horizontal, "Шлюз -\nНПК\nКМ");
    model.setHeaderData(58, Qt::Horizontal, "НПК -\nУстье\nТоми\nКМ");
    model.setHeaderData(59, Qt::Horizontal, "Устье Томи -\nУстье Нерги\nКМ");
    model.setHeaderData(60, Qt::Horizontal, "Устье Нерги -\nСоснино\nКМ");
    model.setHeaderData(61, Qt::Horizontal, "Устье Томи -\nСоснино\nКМ");

    model.setHeaderData(62, Qt::Horizontal, "Слияние -\nБарнаул\nУМ");
    model.setHeaderData(63, Qt::Horizontal, "Барнаул -\nКамень\nУМ");
    model.setHeaderData(64, Qt::Horizontal, "Камень -\nШлюз\nУМ");
    model.setHeaderData(65, Qt::Horizontal, "Малетино -\nШлюз\nУМ");
    model.setHeaderData(66, Qt::Horizontal, "Шлюз -\nНПК\nУМ");
    model.setHeaderData(67, Qt::Horizontal, "НПК -\nУстье\nТоми\nУМ");
    model.setHeaderData(68, Qt::Horizontal, "Устье Томи -\nУстье Нерги\nУМ");
    model.setHeaderData(69, Qt::Horizontal, "Устье Нерги -\nСоснино\nУМ");
    model.setHeaderData(70, Qt::Horizontal, "Устье Томи -\nСоснино\nУМ");

    model.setHeaderData(71, Qt::Horizontal, "Стоимость по\n1 участку");

    model.setHeaderData(72, Qt::Horizontal, "р. Бердь\nКМ");
    model.setHeaderData(73, Qt::Horizontal, "Кемерово-\nТомск\nКМ");
    model.setHeaderData(74, Qt::Horizontal, "Томск-\nУстье\nКМ");
    model.setHeaderData(75, Qt::Horizontal, "р. Чулым\nКМ");
    model.setHeaderData(76, Qt::Horizontal, "р. Кеть\nКМ");
    model.setHeaderData(77, Qt::Horizontal, "р. Васюган\nКМ");
    model.setHeaderData(78, Qt::Horizontal, "р. Нюролька\nКМ");
    model.setHeaderData(79, Qt::Horizontal, "Прочие\nПритоки\nКМ");

    model.setHeaderData(80, Qt::Horizontal, "р. Бердь\nОМ");
    model.setHeaderData(81, Qt::Horizontal, "Кемерово-\nТомск\nОМ");
    model.setHeaderData(82, Qt::Horizontal, "Томск-\nУстье\nОМ");
    model.setHeaderData(83, Qt::Horizontal, "р. Чулым\nОМ");
    model.setHeaderData(84, Qt::Horizontal, "р. Кеть\nОМ");
    model.setHeaderData(85, Qt::Horizontal, "р. Васюган\nОМ");
    model.setHeaderData(86, Qt::Horizontal, "р. Нюролька\nОМ");
    model.setHeaderData(87, Qt::Horizontal, "Прочие\nПритоки\nОМ");

    model.setHeaderData(88, Qt::Horizontal, "Стоимость по\n2 участку");

    model.setHeaderData(89, Qt::Horizontal, "Общее");
}

template<typename T>
void DispatcherWindow::ColumnMainMinimumHeaders(T &model)
{
    model.setHeaderData(0, Qt::Horizontal, "Первичный\nКлюч");
    model.setHeaderData(1, Qt::Horizontal, "№ \nсудо-потока");
    model.setHeaderData(2, Qt::Horizontal, "Наименование\n судна");
    model.setHeaderData(3, Qt::Horizontal, "Флаг");
    model.setHeaderData(4, Qt::Horizontal, "Проект\n судна");
    model.setHeaderData(5, Qt::Horizontal, "Состав\n судна");
    model.setHeaderData(6, Qt::Horizontal, "Проект\n состава");
    model.setHeaderData(7, Qt::Horizontal, "Судовладелец");
    model.setHeaderData(8, Qt::Horizontal, "Груз \n(пассажиры)");
    model.setHeaderData(9, Qt::Horizontal, "Тоннаж \n(балласт)");
    model.setHeaderData(10, Qt::Horizontal, "Осадка \n(см)");
    model.setHeaderData(11, Qt::Horizontal, "Пункт \nотправления");
    model.setHeaderData(12, Qt::Horizontal, "Местополож.\n(река, \nкм с.х.)");
    model.setHeaderData(13, Qt::Horizontal, "Дата выхода\n из пункта \nотправления");
    model.setHeaderData(14, Qt::Horizontal, "Пункт \nназначения");
    model.setHeaderData(15, Qt::Horizontal, "Местополож.\n(река, \nкм с.х.)2");
    model.setHeaderData(16, Qt::Horizontal, "Дата прибытия\n в пункт \nназначения");
    model.setHeaderData(17, Qt::Horizontal, "Дата отметки\n судна при \nпересечении\n границы бассейна");
    model.setHeaderData(18, Qt::Horizontal, "Наименование \nбассейна");
    model.setHeaderData(19, Qt::Horizontal, "Диспетчер ");
}

template<typename T>
void DispatcherWindow::ColumnHeadersCargo(T &model)
{
    model.setHeaderData(0, Qt::Horizontal, "Первичный\nКлюч");
    model.setHeaderData(1, Qt::Horizontal, "№ \nсудо-потока");
    model.setHeaderData(2, Qt::Horizontal, "Наименование\n судна");
    model.setHeaderData(3, Qt::Horizontal, "Флаг");
    model.setHeaderData(4, Qt::Horizontal, "Проект\n судна");
    model.setHeaderData(5, Qt::Horizontal, "Состав\n судна");
    model.setHeaderData(6, Qt::Horizontal, "Проект\n состава");
    model.setHeaderData(7, Qt::Horizontal, "Судовладелец");
    model.setHeaderData(8, Qt::Horizontal, "Груз \n(пассажиры)");
    model.setHeaderData(9, Qt::Horizontal, "Тоннаж \n(балласт)");
    model.setHeaderData(10, Qt::Horizontal, "Осадка \n(см)");
    model.setHeaderData(11, Qt::Horizontal, "Пункт \nотправления");
    model.setHeaderData(12, Qt::Horizontal, "Местополож.\n(река, \nкм с.х.)");
    model.setHeaderData(13, Qt::Horizontal, "Дата выхода\n из пункта \nотправления");
    model.setHeaderData(14, Qt::Horizontal, "Пункт \nназначения");
    model.setHeaderData(15, Qt::Horizontal, "Местополож.\n(река, \nкм с.х.)2");
    model.setHeaderData(16, Qt::Horizontal, "Дата прибытия\n в пункт \nназначения");
    model.setHeaderData(17, Qt::Horizontal, "Дата отметки\n судна при \nпересечении\n границы бассейна");
    model.setHeaderData(18, Qt::Horizontal, "Наименование \nбассейна");
    model.setHeaderData(19, Qt::Horizontal, "Диспетчер ");

    model.setHeaderData(20, Qt::Horizontal, "По \nотправлению");
    model.setHeaderData(21, Qt::Horizontal, "Подсчитано");
    model.setHeaderData(22, Qt::Horizontal, "Б");
    model.setHeaderData(23, Qt::Horizontal, "Н");
    model.setHeaderData(24, Qt::Horizontal, "Т");
    model.setHeaderData(25, Qt::Horizontal, "К");
    model.setHeaderData(26, Qt::Horizontal, "По \nприбытию");
    model.setHeaderData(27, Qt::Horizontal, "Северный \nзавоз");
    model.setHeaderData(28, Qt::Horizontal, "Отметка");
    model.setHeaderData(29, Qt::Horizontal, "Алтай");
    model.setHeaderData(30, Qt::Horizontal, "НСО");
    model.setHeaderData(31, Qt::Horizontal, "Томск");
    model.setHeaderData(32, Qt::Horizontal, "Состав");
    model.setHeaderData(33, Qt::Horizontal, "Баржи");
    model.setHeaderData(34, Qt::Horizontal, "р. Бия");
    model.setHeaderData(35, Qt::Horizontal, "р. Катунь");
    model.setHeaderData(36, Qt::Horizontal, "Чарыш");

    model.setHeaderData(37, Qt::Horizontal, "1 2 Слияние-\nБарнаул");
    model.setHeaderData(38, Qt::Horizontal, "3 Барнаул-\n Малетино");
    model.setHeaderData(39, Qt::Horizontal, "Камень-\nМалетино");
    model.setHeaderData(40, Qt::Horizontal, "4 Камень-\n НПК");
    model.setHeaderData(41, Qt::Horizontal, "Малетино- \nНПК");
    model.setHeaderData(42, Qt::Horizontal, "Аванпорт-\n НПК");
    model.setHeaderData(43, Qt::Horizontal, "6 НПК-\nТомь");
    model.setHeaderData(44, Qt::Horizontal, "7 Томь-\nНерга");
    model.setHeaderData(45, Qt::Horizontal, "8 Нерга-\nСоснино");
    model.setHeaderData(46, Qt::Horizontal, "Устье Томи-\nСоснино");
    model.setHeaderData(47, Qt::Horizontal, "1 7 Новокузнецк-\nТомск");
    model.setHeaderData(48, Qt::Horizontal, "1 8 Томск-\nУстье");
    model.setHeaderData(49, Qt::Horizontal, "Васюган");
    model.setHeaderData(50, Qt::Horizontal, "Нюролька");
    model.setHeaderData(51, Qt::Horizontal, "Чулым");
    model.setHeaderData(52, Qt::Horizontal, "Кеть");
    model.setHeaderData(53, Qt::Horizontal, "Прочие");
    model.setHeaderData(54, Qt::Horizontal, "Грузооборот");
    model.setHeaderData(55, Qt::Horizontal, "Габариты\nСУДНА,\nм3");
    model.setHeaderData(56, Qt::Horizontal, "Габариты\nСОСТАВА,\nм3");
    model.setHeaderData(57, Qt::Horizontal, "Габариты\nсудопотока");
    model.setHeaderData(58, Qt::Horizontal, "Среднее\nрасстояние");
    model.setHeaderData(59, Qt::Horizontal, "Сумма\nрасстояний\nпо плесам");
    model.setHeaderData(60, Qt::Horizontal, "Истина\n Ложь КМ");
    model.setHeaderData(61, Qt::Horizontal, "Оборот\nмодуля\nсудопотока");
    model.setHeaderData(62, Qt::Horizontal, "ОМ по\nплесам");
    model.setHeaderData(63, Qt::Horizontal, "Истина\n Ложь ОМ");

    model.setHeaderData(64, Qt::Horizontal, "Слияние-\nБарнаул\nкм");
    model.setHeaderData(65, Qt::Horizontal, "Барнаул-\nКамень\nкм");
    model.setHeaderData(66, Qt::Horizontal, "Камень-\nШлюз\nкм");
    model.setHeaderData(67, Qt::Horizontal, "Шлюз-\nНПК\nкм");
    model.setHeaderData(68, Qt::Horizontal, "НПК-\nУстье\nТоми км");
    model.setHeaderData(69, Qt::Horizontal, "Устье Томи-\nУстье\nНерги км");
    model.setHeaderData(70, Qt::Horizontal, "Устье\nНерги-\nСоснино км");
    model.setHeaderData(71, Qt::Horizontal, "Малетино-\nШлюз км");
    model.setHeaderData(72, Qt::Horizontal, "Устье Томи-\nСоснино км");

    model.setHeaderData(73, Qt::Horizontal, "ОМ Слияние-\nБарнаул");
    model.setHeaderData(74, Qt::Horizontal, "ОМ Барнаул-\nКамень");
    model.setHeaderData(75, Qt::Horizontal, "ОМ Камень-\nШлюз");
    model.setHeaderData(76, Qt::Horizontal, "ОМ Шлюз-\nНПК");
    model.setHeaderData(77, Qt::Horizontal, "ОМ НПК-\nУстье Томи");
    model.setHeaderData(78, Qt::Horizontal, "ОМ Устье Томи-\nУстье Нерги");
    model.setHeaderData(79, Qt::Horizontal, "ОМ Устье Нерги-\nСоснино");
    model.setHeaderData(80, Qt::Horizontal, "ОМ Малетино-\nШлюз");
    model.setHeaderData(81, Qt::Horizontal, "ОМ Устье Томи-\nСоснино");

    model.setHeaderData(82, Qt::Horizontal, "Стоимость\nпо 1-му\nучастку");

    model.setHeaderData(83, Qt::Horizontal, "р. Бия\nкм");
    model.setHeaderData(84, Qt::Horizontal, "р. Катунь\nкм");
    model.setHeaderData(85, Qt::Horizontal, "р. Бердь\nкм");
    model.setHeaderData(86, Qt::Horizontal, "р. Томь\nкм");
    model.setHeaderData(87, Qt::Horizontal, "р. Чулым\nкм");
    model.setHeaderData(88, Qt::Horizontal, "р. Кеть\nкм");
    model.setHeaderData(89, Qt::Horizontal, "р. Парабель\nкм");
    model.setHeaderData(90, Qt::Horizontal, "р. Васюган\nкм");
    model.setHeaderData(91, Qt::Horizontal, "р. Нюролька\nкм");
    model.setHeaderData(92, Qt::Horizontal, "р. Тым\nкм");
    model.setHeaderData(93, Qt::Horizontal, "Прочие\nПритоки\nкм");

    model.setHeaderData(94, Qt::Horizontal, "р. Бия\nОМ");
    model.setHeaderData(95, Qt::Horizontal, "р. Катунь\nОМ");
    model.setHeaderData(96, Qt::Horizontal, "р. Бердь\nОМ");
    model.setHeaderData(97, Qt::Horizontal, "р. Томь\nОМ");
    model.setHeaderData(98, Qt::Horizontal, "р. Чулым\nОМ");
    model.setHeaderData(99, Qt::Horizontal, "р. Кеть\nОМ");
    model.setHeaderData(100, Qt::Horizontal, "р. Парабель\nОМ");
    model.setHeaderData(101, Qt::Horizontal, "р. Васюган\nОМ");
    model.setHeaderData(102, Qt::Horizontal, "р. Нюролька\nОМ");
    model.setHeaderData(103, Qt::Horizontal, "р. Тым\nОМ");
    model.setHeaderData(104, Qt::Horizontal, "Прочие\nПритоки\nОМ");

    model.setHeaderData(105, Qt::Horizontal, "Стоимость\nпо 2-му\nучастку");

    model.setHeaderData(106, Qt::Horizontal, "Общее");
}

template<typename T>
void DispatcherWindow::ColumnTaskHeaders(T &model)
{
    model.setHeaderData(0, Qt::Horizontal, "№ Задачи");
    model.setHeaderData(1, Qt::Horizontal, "Кому");
    model.setHeaderData(2, Qt::Horizontal, "От кого");
    model.setHeaderData(3, Qt::Horizontal, "Срок до");
    model.setHeaderData(4, Qt::Horizontal, "Приоритет");
    model.setHeaderData(5, Qt::Horizontal, "Задача");
    model.setHeaderData(6, Qt::Horizontal, "Статус\nвыполнения");
    model.setHeaderData(7, Qt::Horizontal, "Дата \nвыполнения");
    model.setHeaderData(8, Qt::Horizontal, "Комментарий");
}

template<typename T>
void DispatcherWindow::selectCatalogTable(T &model, QString nameCatalogTable)
{
    if (nameCatalogTable == "departurep")
        ColumnCatalogHeaders(model,"Пункт","Местоположение","");
    else if(nameCatalogTable == "directions")
        ColumnCatalogHeaders(model,"Направления","Расстояние","");
    else if(nameCatalogTable == "vessel")
        ColumnCatalogHeaders(model,"Наименование судна","Проект судна","Судовладелец");
    else if(nameCatalogTable == "cargo_t")
        ColumnCatalogHeaders(model,"Тип груза","","");
    else if(nameCatalogTable == "areas")
        ColumnCatalogHeaders(model,"Название","","");
    else if(nameCatalogTable == "dimensions")
        ColumnCatalogHeaders(model,"Название","Габариты","");
    else if(nameCatalogTable == "pool")
        ColumnCatalogHeaders(model,"Название","","");
    else if(nameCatalogTable == "northerndelivery")
        ColumnCatalogHeaders(model,"Название","","");
    else if(nameCatalogTable == "cargo_p")
        ColumnCatalogHeaders(model,"Тип груза","","");
    else if(nameCatalogTable == "typetransportation")
        ColumnCatalogHeaders(model,"Тип перевозки","","");
}

template<typename T>
void DispatcherWindow::ColumnCatalogHeaders(T &model, QString c1,QString c2,QString c3)
{
    model.setHeaderData(1, Qt::Horizontal, c1);
    model.setHeaderData(2, Qt::Horizontal, c2);
    model.setHeaderData(3, Qt::Horizontal, c3);
}

void DispatcherWindow::showMainTable(QString nameMainTable){
    QTableView view;
    QSqlTableModel *model = new QSqlTableModel;
    model->setTable(nameMainTable); //nameTable_c_f
    model->select();
    if (model->tableName() == nameTable_c_f)
    {
        ColumnHeadersCargo(*model);
        ui->label_mainTableName->setText("table_cargo");
    }
    else if (model->tableName() == nameTable_p_f)
    {
        ColumnHeadersPassengers(*model);
        ui->label_mainTableName->setText("table_passenger");
    }
    ui->tableDBView->setModel(model);
    ui->tableDBView->setColumnHidden(0, true);                                                        //убрать видимость первого столбца

}

void DispatcherWindow::showTaskTable(){
    QTableView view;
    QSqlTableModel *model = new QSqlTableModel;
    QSettings *uSett = new QSettings(UserSett, QSettings::IniFormat);
    QString currUserName;
    currUserName = (uSett->value("User_Settings/currentUser","").toString());
    model->setTable("usertask");
    model->setFilter("task_target='"+currUserName+"' OR task_from='"+currUserName+"'");
    model->select();
    ui->tableTaskView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QFont headerFont;
    headerFont.bold();
    headerFont.setPointSize(14);
    ColumnTaskHeaders(*model);
    ui->tableTaskView->setModel(model);
    //ui->tableTaskView->setColumnHidden(0, true);                                                        //убрать видимость первого столбца
}

void DispatcherWindow::showCatalogTable(QString nameCatalogTable){
    QTableView view;
    QSqlTableModel *model = new QSqlTableModel;
    model->setTable(nameCatalogTable);
    model->select();
    selectCatalogTable(*model, nameCatalogTable);
    ui->tableCatalogView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QFont headerFont;
    headerFont.bold();
    headerFont.setPointSize(14);

    ui->tableCatalogView->setModel(model);
    ui->tableCatalogView->setColumnHidden(0, true);                                                        //убрать видимость первого столбца

}

void DispatcherWindow::elementsStatusBar()
{
    QLabel *label_login;                                                                                                // Имя текущего пользователя
    label_login = new QLabel();
    QSettings *uSett = new QSettings(UserSett, QSettings::IniFormat);
    label_login->setText(uSett->value("User_Settings/currentUser","").toString());
    ui->statusbar->addWidget(label_login);


    QLabel *label_task;                                                                                                 // Количество моих задач
    label_task = new QLabel();
    ui->statusbar->addWidget(label_task); //
    label_task->setText("У вас нет входящих задач! 2 ваши задачи выполняются!");

    QLabel *currentDateTime;                                                                                            // Текущая дата
    currentDateTime = new QLabel();
    ui->statusbar->addWidget(currentDateTime); //
    currentDateTime->setText(QDate::currentDate().toString());
}

void DispatcherWindow::elementsMenuSwitchTable()
{
    QMenu *menu = new QMenu(tr("Menu"), this);                                                                          // Меню для основных таблиц
        menu->addAction(tr("Грузоперевозки"));
        menu->addAction(tr("Пассажироперевозки"));
    ui->butt_tableChange->setMenu(menu);
    ui->butt_tableChange->menu()->addAction("Грузоперевозки");
    ui->butt_tableChange->menu()->addAction("Пассажироперевозки");
}

void DispatcherWindow::showEvent(QShowEvent *)                                                                          // открытие формы
{
    elementsMenuSwitchTable();          //Элементы меню переключения таблицы
    elementsStatusBar();                //Элементы статус бара
    showMainTable(nameTable_c_f);       //отображение главной таблицы
    ui->label_RussianTableName->setText("Грузоперевозки");
    showTaskTable();                    //отображение таблицы заданий
    ui->label_currIndexContent->setVisible(false);
    ui->label_currIndexTask->setVisible(false);
    ui->label_mainTableName->setVisible(false);
    ui->label_mainTableType->setVisible(false);
    ui->label_mainTableType->setText("table_max");
}

DispatcherWindow::~DispatcherWindow()
{
    delete ui;
}

// Метод, который обрабатывает нажатие на иконку приложения в трее
void DispatcherWindow::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason){
    case QSystemTrayIcon::Trigger:
            if(!this->isVisible())
                this->show();
            else
                this->hide();
        break;
    default:
        break;
    }
}

void DispatcherWindow::on_butt_tray_clicked()
{
    if(this->isVisible())
    {
        this->hide();
        QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon(QSystemTrayIcon::Information);

        trayIcon->showMessage("Программа свернута в трей!",
                             ("Приложение свернуто в трей. Для того чтобы, "
                              "развернуть окно приложения, щелкните по иконке приложения в трее"),
                              icon,
                              2000);
    }
}

void DispatcherWindow::on_butt_exit_clicked()                                                                           //Выход в меню входа
{
    this->close();                                                                                                      // Закрываем окно
    emit openLoginWindow();                                                                                             // И вызываем сигнал на открытие главного окна
}

// Функция отвечающая за переключение таблицы (По возможности переделать)
void DispatcherWindow::on_butt_tableChange_clicked()
{
    if (ui->label_mainTableName->text() == "table_cargo")
    {
        showMainTable(nameTable_p_f);
        ui->label_mainTableName->setText("table_passenger");
        ui->label_RussianTableName->setText("Пассажироперевозки");
    }
    else if(ui->label_mainTableName->text() == "table_passenger")
    {
        showMainTable(nameTable_c_f);
        ui->label_mainTableName->setText("table_cargo");
        ui->label_RussianTableName->setText("Грузоперевозки");
    }
}

void DispatcherWindow::on_butt_filter_clicked()                                                                         // Фильтрация базы
{
    filterWind->show();
    // Запрос на фильтр
}

void DispatcherWindow::cboxTaskSetValueFromDB()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QString sql;
    sql = "SELECT UserLogin FROM users WHERE AccessLevel = 2";                     //***// можно загрузить из файла!
    QSqlQuery query;
    query.prepare(sql);
    query.exec();
    model->setQuery(query);
    ui->cbox_taskRecipient->setModel(model);
    ui->cbox_taskRecipient->addItem("");
    ui->cbox_taskRecipient->setCurrentIndex(-1);
}

void DispatcherWindow::on_tab_menu_tabBarClicked(int index)
{
    if (index==1){  //Администрирование
        ui->group_controlPanel->setVisible(0);  //делаем невидимую группу элементов
        ui->label_nameControlTable->setVisible(false);
    }
    if (index==2){
        ui->group_addTask->setVisible(0);
        ui->group_editStatus->setVisible(0);
        cboxTaskSetValueFromDB();
    }
}

void DispatcherWindow::setFormCatalog(QString tableName, QString c1, QString c2, QString c3)
{
    // Отобразить таблицу пункты
    showCatalogTable(tableName);

    // Сделать видимым группу элементов
    ui->group_controlPanel->setVisible(true);
    ui->label_nameControlTable->setText(tableName);
    ui->butt_controlAdd->setVisible(true);
    ui->butt_controlEdit->setVisible(true);
    ui->butt_controlDelete->setVisible(true);
    ui->butt_controlSearch->setVisible(true);

    // Установить текст в необходимые данные для таблицы
    ui->label_c1->setText(c1);
    ui->label_c2->setText(c2);
    ui->label_c3->setText(c3);
    ui->text_c1->setText("");
    ui->text_c2->setText("");
    ui->text_c3->setText("");

    //отобразить необходимые поля
    if(c2=="")  //если только один столбец
    {
        ui->label_c2->setVisible(false);
        ui->label_c3->setVisible(false);
        ui->text_c2->setVisible(false);
        ui->text_c3->setVisible(false);
    }
    else if(c3=="") //если два столбца
    {
        ui->label_c2->setVisible(true);
        ui->label_c3->setVisible(false);
        ui->text_c2->setVisible(true);
        ui->text_c3->setVisible(false);
    }
    else{           //если три столбца
        ui->label_c2->setVisible(true);
        ui->label_c3->setVisible(true);
        ui->text_c2->setVisible(true);
        ui->text_c3->setVisible(true);
    }
}

void DispatcherWindow::on_butt_table_point_clicked()                                                                    // Редактирование справочника Пункты
{
    setFormCatalog("departurep","Пункт","Местоположение","");
    ui->label_RussianControlTableName->setText("Пункты");
}

void DispatcherWindow::on_butt_table_direction_clicked()
{
    setFormCatalog("directions","Направление","Расстояние","");
    ui->label_RussianControlTableName->setText("Направления");
}

void DispatcherWindow::on_butt_table_vessel_clicked()
{
    setFormCatalog("vessel","Наименование судна","Проект судна","Судовладелец");
    ui->label_RussianControlTableName->setText("Суда");
}

void DispatcherWindow::on_butt_table_cargo_clicked()
{
    setFormCatalog("cargo_t","Тип груза","","");
    ui->label_RussianControlTableName->setText("Грузы");
}

void DispatcherWindow::on_butt_table_region_clicked()
{
    setFormCatalog("areas","Название","","");
    ui->label_RussianControlTableName->setText("Области");
}

void DispatcherWindow::on_butt_table_dimensions_clicked()
{
    setFormCatalog("dimensions","Название","Габариты","");
    ui->label_RussianControlTableName->setText("Габариты");
}

void DispatcherWindow::on_butt_table_pool_clicked()
{
    setFormCatalog("pool","Название","","");
    ui->label_RussianControlTableName->setText("Бассейны");
}

void DispatcherWindow::on_butt_table_northDelivery_clicked()
{
    setFormCatalog("northerndelivery","Название","","");
    ui->label_RussianControlTableName->setText("Северный завоз");
}

void DispatcherWindow::on_butt_table_cargoPassenger_clicked()
{
    setFormCatalog("cargo_p","Тип груза","","");
    ui->label_RussianControlTableName->setText("Груз пассажиры");
}

void DispatcherWindow::on_butt_typeTransportation_clicked()
{
    setFormCatalog("typetransportation","Тип перевозки","","");
    ui->label_RussianControlTableName->setText("Виды перевозок");
}

void DispatcherWindow::controlPanelElementActive(bool a, bool e, bool d, bool s, QString acceptName)
{
    ui->butt_controlAdd->setVisible(a);
    ui->butt_controlEdit->setVisible(e);
    ui->butt_controlDelete->setVisible(d);
    ui->butt_controlSearch->setVisible(s);

    ui->text_c1->setReadOnly(false);
    ui->text_c2->setReadOnly(false);
    ui->text_c3->setReadOnly(false);

    ui->text_c1->clear();
    ui->text_c2->clear();
    ui->text_c3->clear();

    ui->butt_acceptContent->setText(acceptName);
}
void DispatcherWindow::on_butt_controlAdd_clicked()
{
    controlPanelElementActive(1,0,0,0,"Добавить");
}

void DispatcherWindow::on_butt_controlDelete_clicked()
{
    controlPanelElementActive(0,0,1,0,"Удалить");
    ui->text_c1->setReadOnly(true);
    ui->text_c2->setReadOnly(true);
    ui->text_c3->setReadOnly(true);
}

void DispatcherWindow::on_butt_controlEdit_clicked()
{
    controlPanelElementActive(0,1,0,0,"Редактировать");
    if (ui->butt_acceptContent->text()=="Редактировать")
    {
        QString currentCommand = "Edt";
        // СЮДА ПЕРЕДАЧА ПАРАМЕТРОВ
        QItemSelectionModel *selectModel = ui->tableCatalogView->selectionModel();
        if(!selectModel->selectedRows().isEmpty())              //проверяем выделили ли строку
        {
            int nr = selectModel->selectedRows().first().row();  //вписываем номер строки
            QString indid = ui->tableCatalogView->model()->data(ui->tableCatalogView->model()->index(nr,0)).toString();
            ui->label_currIndexContent->setText(indid);
            ui->text_c1->setText(ui->tableCatalogView->model()->data(ui->tableCatalogView->model()->index(nr,1)).toString());
            ui->text_c2->setText(ui->tableCatalogView->model()->data(ui->tableCatalogView->model()->index(nr,2)).toString());
            ui->text_c3->setText(ui->tableCatalogView->model()->data(ui->tableCatalogView->model()->index(nr,3)).toString());

            ui->butt_acceptContent->setText("Сохранить");
        }
        else
        {
            QMessageBox::warning(nullptr, "Ошибка", "Строка не выделена.");
        }

    }
}

void DispatcherWindow::on_butt_cancelContent_clicked()
{
    controlPanelElementActive(1,1,1,1,"Применить");
    ui->text_c1->setReadOnly(true);
    ui->text_c2->setReadOnly(true);
    ui->text_c3->setReadOnly(true);
    QString currentTableName = ui->label_nameControlTable->text();
    showCatalogTable(currentTableName);
}

void DispatcherWindow::findParamRowToContentTable(QString currentTable, QString currentParam)
{
    //вводимые параметры для столбцов
    QString c1 = ui->text_c1->text();
    QString c2 = ui->text_c2->text();
    QString c3 = ui->text_c3->text();

    //получение названия столбцов и их передача в функцию добавлени
    if (currentTable == "areas"){
        if (currentParam == "Add")
            addRowToContentTable(currentTable,"NameArea","","",c1,c2,c3);
        else if (currentParam == "Srh")
            searchRowInContentTable(currentTable,"NameArea","","",c1,c2,c3);
        else if (currentParam == "Edt")
            editRowContentTable(currentTable,"KeyAreas","NameArea","","",c1,c2,c3);
    }
    else if(currentTable == "cargo_p"){
        if (currentParam == "Add")
            addRowToContentTable(currentTable,"TypeCargo","","",c1,c2,c3);
        else if (currentParam == "Srh")
            searchRowInContentTable(currentTable,"TypeCargo","","",c1,c2,c3);
        else if (currentParam == "Edt")
            editRowContentTable(currentTable,"KeyCargoP","TypeCargo","","",c1,c2,c3);
    }
    else if(currentTable == "cargo_t"){
        if (currentParam == "Add")
            addRowToContentTable(currentTable,"TypeCargo","","",c1,c2,c3);
        else if (currentParam == "Srh")
            searchRowInContentTable(currentTable,"TypeCargo","","",c1,c2,c3);
        else if (currentParam == "Edt")
            editRowContentTable(currentTable,"KeyCargo","TypeCargo","","",c1,c2,c3);
    }
    else if(currentTable == "departurep"){
        if (currentParam == "Add")
            addRowToContentTable(currentTable,"Point","Location","",c1,c2,c3);
        else if (currentParam == "Srh")
            searchRowInContentTable(currentTable,"Point","Location","",c1,c2,c3);
        else if (currentParam == "Edt")
            editRowContentTable(currentTable,"KeyDeparture","Point","Location","",c1,c2,c3);
    }
    else if(currentTable == "dimensions"){
        if (currentParam == "Add")
            addRowToContentTable(currentTable,"NameShip","ShipDimensions","",c1,c2,c3);
        else if (currentParam == "Srh")
            searchRowInContentTable(currentTable,"NameShip","ShipDimensions","",c1,c2,c3);
        else if (currentParam == "Edt")
            editRowContentTable(currentTable,"KeyDimensions","NameShip","ShipDimensions","",c1,c2,c3);
    }
    else if(currentTable == "directions"){
        if (currentParam == "Add")
            addRowToContentTable(currentTable,"Directions","Distance","",c1,c2,c3);
        else if (currentParam == "Srh")
            searchRowInContentTable(currentTable,"Directions","Distance","",c1,c2,c3);
        else if (currentParam == "Edt")
            editRowContentTable(currentTable,"KeyDirection","Directions","Distance","",c1,c2,c3);
    }
    else if(currentTable == "northerndelivery"){
        if (currentParam == "Add")
            addRowToContentTable(currentTable,"NameNorthD","","",c1,c2,c3);
        else if (currentParam == "Srh")
            searchRowInContentTable(currentTable,"NameNorthD","","",c1,c2,c3);
        else if (currentParam == "Edt")
            editRowContentTable(currentTable,"KeyNorthD","NameNorthD","","",c1,c2,c3);
    }
    else if(currentTable == "pool"){
        if (currentParam == "Add")
            addRowToContentTable(currentTable,"NamePool","","",c1,c2,c3);
        else if (currentParam == "Srh")
            searchRowInContentTable(currentTable,"NamePool","","",c1,c2,c3);
        else if (currentParam == "Edt")
            editRowContentTable(currentTable,"KeyPool","NamePool","","",c1,c2,c3);
    }
    else if(currentTable == "typetransportation"){
        if (currentParam == "Add")
            addRowToContentTable(currentTable,"TypeTransportation","","",c1,c2,c3);
        else if (currentParam == "Srh")
            searchRowInContentTable(currentTable,"TypeTransportation","","",c1,c2,c3);
        else if (currentParam == "Edt")
            editRowContentTable(currentTable,"KeyTypeT","TypeTransportation","","",c1,c2,c3);
    }
    else if(currentTable == "vessel"){
        if (currentParam == "Add")
            addRowToContentTable(currentTable,"ShipName","ShipDesign","Shipowner",c1,c2,c3);
        else if (currentParam == "Srh")
            searchRowInContentTable(currentTable,"ShipName","ShipDesign","Shipowner",c1,c2,c3);
        else if (currentParam == "Edt")
            editRowContentTable(currentTable,"KeyVessel","ShipName","ShipDesign","Shipowner",c1,c2,c3);
    }
}

void DispatcherWindow::searchRowInContentTable(QString currentTable, QString cn1, QString cn2, QString cn3, QString c1, QString c2, QString c3)
{
    QSqlTableModel *model = new QSqlTableModel;
    QSqlQueryModel *setquery1 = new QSqlQueryModel;                                                                //переменная для запроса
    if (cn2 == ""){
        setquery1->setQuery("SELECT * FROM "+currentTable+""
                            " WHERE "+cn1+" LIKE '%"+c1+"%'");
        if (setquery1->lastError().isValid()) {
            QMessageBox::critical(nullptr, "Ошибка Поиска", setquery1->lastError().text() );
        }
        model->select();
        ui->tableCatalogView->setModel(setquery1);
    }
    else if(cn3 == "" && cn2 != ""){
        setquery1->setQuery("SELECT * FROM "+currentTable+""
                            " WHERE "+cn1+" LIKE '%"+c1+"%' AND"
                            " "+cn2+" LIKE '%"+c2+"%'");
        if (setquery1->lastError().isValid()) {
            QMessageBox::critical(nullptr, "Ошибка Поиска", setquery1->lastError().text() );
        }
        model->select();
        ui->tableCatalogView->setModel(setquery1);
    }
    else if(cn3 != ""){
        setquery1->setQuery("SELECT * FROM "+currentTable+""
                            " WHERE "+cn1+" LIKE '%"+c1+"%' AND"
                            " "+cn2+" LIKE '%"+c2+"%' AND"
                            " "+cn3+" LIKE '%"+c3+"%'");
        if (setquery1->lastError().isValid()) {
            QMessageBox::critical(nullptr, "Ошибка Поиска", setquery1->lastError().text() );
        }
        model->select();
        ui->tableCatalogView->setModel(setquery1);
    }

}

void DispatcherWindow::editRowContentTable(QString currentTable, QString key, QString cn1, QString cn2, QString cn3, QString c1, QString c2, QString c3)
{

    QSqlQueryModel *setquery1 = new QSqlQueryModel;
    QSqlTableModel *model = new QSqlTableModel;

    QString indid = ui->label_currIndexContent->text();

    if (cn2 == "")
    {
        setquery1->setQuery("UPDATE "+currentTable+" SET "+cn1+" = '"+c1+"'"
                            " WHERE "+key+"="+indid+";");
    }
    else if (cn2 != "" && cn3 =="")
    {
        setquery1->setQuery("UPDATE "+currentTable+" SET "+cn1+" = '"+c1+"', "+cn2+" = '"+c2+"'"
                            " WHERE "+key+"="+indid+";");
    }
    else
    {
        setquery1->setQuery("UPDATE "+currentTable+" SET "+cn1+" = '"+c1+"', "+cn2+" = '"+c2+"', "+cn3+" = '"+c3+"'"
                            " WHERE "+key+"="+indid+";");
    }

    if (setquery1->lastError().isValid()) {
        QMessageBox::critical(nullptr, "Ошибка редактирования", setquery1->lastError().text() );
    }

    //tv->setModel(setquery1);
    //ui->tableCatalogView->setModel(setquery1);

    model->setTable(currentTable);
    model->select();
    showCatalogTable(currentTable);
}

void DispatcherWindow::deleteRowContentTable(QString currentTable, QString key)
{
    QSqlQueryModel *setquery1 = new QSqlQueryModel; //запрос
    QSqlTableModel *model = new QSqlTableModel; // отображение
    QTableView *tv = new QTableView(this);
    QItemSelectionModel *selectModel = ui->tableCatalogView->selectionModel();

    if(!selectModel->selectedRows().isEmpty())   //проверяем выделили ли строку (не пустая ли)
    {

        int nr = selectModel->selectedRows().first().row();  //вписываем номер строки
        if (QMessageBox::Yes == QMessageBox::question(nullptr, "Удалить?",
                                                      "Уверены?",
                                                      QMessageBox::Yes|QMessageBox::No))
        {
            QString indid = ui->tableCatalogView->model()->data(ui->tableCatalogView->model()->index(nr,0)).toString();

            setquery1->setQuery("DELETE FROM "+currentTable+" WHERE "+key+"="+indid+";");

            if (setquery1->lastError().isValid()) {
                QMessageBox::critical(nullptr, "Ошибка удаления", setquery1->lastError().text() );
            }
            QMessageBox::information(nullptr, "Удалено", "Строка успешно удалена!");

            tv->setModel(setquery1);
            ui->tableCatalogView->setModel(setquery1);

            model->setTable(currentTable);
            model->select();
            ui->tableCatalogView->setModel(model);
            ui->tableCatalogView->setColumnHidden(0, true);
        }
    }
    else
    {
        QMessageBox::warning(nullptr, "Ошибка", "Строка не выделена.");
    }
}

void DispatcherWindow::addRowToContentTable(QString currentTable, QString cn1, QString cn2, QString cn3, QString c1, QString c2, QString c3)
{
    QSqlQuery query;
    if (cn1 != "" && cn2 == "" && cn3 == ""){
        if(query.prepare("INSERT INTO "+currentTable+"("+cn1+")"
                         " VALUES (:c1)"))
        {
            query.bindValue(":c1", c1);
            query.exec();
            QMessageBox::information(nullptr, "Успех", "Запись добавлена.");
        }
        else
            QMessageBox::critical(nullptr, "Ошибка добавления", query.lastError().text() );
    }

    else if(cn3 == "" && cn2 != "" && cn1 != ""){

        if(query.prepare("INSERT INTO "+currentTable+"("+cn1+", "+cn2+")"
                         " VALUES (:c1, :c2)"))
        {
            query.bindValue(":c1", c1);
            query.bindValue(":c2", c2);

            query.exec();
        //сообщение о успехе или неудаче
            QMessageBox::information(nullptr, "Успех", "Запись добавлена.");
        }
        else{
            QMessageBox::critical(nullptr, "Ошибка добавления", query.lastError().text() );

        }
    }
    else if(cn3 != "" && cn2 != "" && cn1 != ""){

        if(query.prepare("INSERT INTO "+currentTable+"("+cn1+", "+cn2+", "+cn3+")"
                         " VALUES (:c1, :c2, :c3)"))
        {
            query.bindValue(":c1", c1);
            query.bindValue(":c2", c2);
            query.bindValue(":c3", c3);

            query.exec();
        //сообщение о успехе или неудаче
            QMessageBox::information(nullptr, "Успех", "Запись добавлена.");
        }
        else{
            QMessageBox::critical(nullptr, "Ошибка добавления", query.lastError().text() );

        }
    }

    showCatalogTable(currentTable);

}

QString DispatcherWindow::getKeysTable(QString currentTable)
{
    if (currentTable == "areas")
        return "KeyAreas";
    else if(currentTable == "cargo_p")
        return "KeyCargoP";
    else if(currentTable == "cargo_t")
        return "KeyCargo";
    else if(currentTable == "departurep")
        return "KeyDeparture";
    else if(currentTable == "dimensions")
        return "KeyDimensions";
    else if(currentTable == "directions")
        return "KeyDirection";
    else if(currentTable == "northerndelivery")
        return "KeyNorthD";
    else if(currentTable == "pool")
        return "KeyPool";
    else if(currentTable == "typetransportation")
        return "KeyTypeT";
    else if(currentTable == "vessel")
        return "KeyVessel";
    return "";
}

void DispatcherWindow::on_butt_acceptContent_clicked()
{
    //Какая таблица выбрана и нужные параметры
    QString currentTable = ui->label_nameControlTable->text();
    //какая команда выбрана сейчас
    QString currentCommand = "";
    if (ui->butt_acceptContent->text()=="Добавить"){
        currentCommand = "Add";
        findParamRowToContentTable(currentTable,currentCommand);
        currentCommand = "";
    }
    if (ui->butt_acceptContent->text()=="Удалить"){
        currentCommand = "Del";
        deleteRowContentTable(currentTable, getKeysTable(currentTable));
        currentCommand = "";
    }
    if (ui->butt_acceptContent->text()=="Сохранить"){
        currentCommand = "Edt";
        findParamRowToContentTable(currentTable,currentCommand);
        currentCommand = "";
    }
    if (ui->butt_acceptContent->text()=="Поиск"){
        currentCommand = "Srh";
        findParamRowToContentTable(currentTable,currentCommand);
        currentCommand = "";
    }

    controlPanelElementActive(1,1,1,1,"Применить");
    ui->text_c1->setReadOnly(true);
    ui->text_c2->setReadOnly(true);
    ui->text_c3->setReadOnly(true);

    ui->label_nameControlTable->setVisible(false);
}

void DispatcherWindow::on_butt_controlSearch_clicked()
{
    controlPanelElementActive(0,0,0,1,"Поиск");
}

void DispatcherWindow::on_butt_task_add_clicked()
{
    ui->group_addTask->setVisible(1);
    ui->group_editStatus->setVisible(0);
    ui->date_taskBefore->setDate(QDate::currentDate());

}

void DispatcherWindow::on_butt_task_edit_clicked()
{
    // Проверка выделена ли строка, если да
    QItemSelectionModel *selectModel = ui->tableTaskView->selectionModel();

    if(!selectModel->selectedRows().isEmpty())   //проверяем выделили ли строку (не пустая ли)
    {

        int nr = selectModel->selectedRows().first().row();  //вписываем номер строки
        QString indid = ui->tableTaskView->model()->data(ui->tableTaskView->model()->index(nr,0)).toString();
        ui->label_currIndexTask->setText(indid);

        //перемещаем данные в поле
        ui->cbox_taskStatus->setCurrentText(ui->tableTaskView->model()->data(ui->tableTaskView->model()->index(nr,6)).toString());
        ui->date_taskDecision->setDate(ui->tableTaskView->model()->data(ui->tableTaskView->model()->index(nr,7)).toDate());
        ui->text_taskComment->setText(ui->tableTaskView->model()->data(ui->tableTaskView->model()->index(nr,8)).toString());

        //делаем видимой область
        ui->group_addTask->setVisible(0);
        ui->group_editStatus->setVisible(1);
    }
    else
    {
        QMessageBox::warning(nullptr, "Ошибка", "Строка не выделена.");
    }

}

void DispatcherWindow::on_butt_taskAdd_clicked()
{
    QSqlQuery query;
    QSettings *uSett = new QSettings(UserSett, QSettings::IniFormat);
    //проверить на запонление
    //дата выполнения меньше текущей
    if(ui->date_taskBefore->date() < QDate::currentDate()){
        QMessageBox::critical(nullptr, "Ошибка", "Указанная дата меньше текущей" );     //сообщение о ошибке
    }
    //не выбрано кому
    else if(ui->cbox_taskRecipient->currentText()==""){
        QMessageBox::critical(nullptr, "Ошибка", "Не указан получатель" );     //сообщение о ошибке
    }
    //не выбран приоритет
    else if(ui->cbox_taskPriority->currentText()==""){
        QMessageBox::critical(nullptr, "Ошибка", "Не указан приоритет" );     //сообщение о ошибке
    }
    //не указана задача
    else if(ui->text_task->toPlainText()==""){
        QMessageBox::critical(nullptr, "Ошибка", "Не указана задача" );     //сообщение о ошибке
    }
    else{
        if(query.prepare("INSERT INTO usertask(task_target, task_from, task_date_deadline, task_priority, task_description)"
                         " VALUES (:c1, :c2, :c3, :c4, :c5)"))
        {
            query.bindValue(":c1", ui->cbox_taskRecipient->currentText());                      //Получатель
            query.bindValue(":c2", uSett->value("User_Settings/currentUser","").toString());    //Текущий пользователь
            query.bindValue(":c3", ui->date_taskBefore->date());                                //Дата до
            query.bindValue(":c4", ui->cbox_taskPriority->currentText());                       //Приоритет
            query.bindValue(":c5", ui->text_task->toPlainText());                               //Задача
            query.exec();                                                                       //выполнение запроса
            QMessageBox::information(nullptr, "Успех", "Задача добавлена.");                    //сообщение о успехе
        }
        else
            QMessageBox::critical(nullptr, "Ошибка добавления", query.lastError().text() );     //сообщение о ошибке
    }
    showTaskTable();
}

void DispatcherWindow::on_butt_taskClear_clicked()
{
    ui->cbox_taskRecipient->currentText()="";
    ui->cbox_taskPriority->currentText()="";
    ui->date_taskBefore->setDate(QDate::currentDate());
    ui->text_task->clear();
    ui->group_addTask->setVisible(false);
    showTaskTable();
}

void DispatcherWindow::on_butt_taskEditStatus_clicked()
{
    QSqlQueryModel *setquery1 = new QSqlQueryModel;
    QSqlTableModel *model = new QSqlTableModel;


    QString indid = ui->label_currIndexTask->text();


    QString c1 = ui->cbox_taskStatus->currentText();
    QString c2 = ui->date_taskDecision->date().toString(Qt::ISODate);
    QString c3 = ui->text_taskComment->toPlainText();

    setquery1->setQuery("UPDATE usertask SET task_status = '"+c1+"', task_date_performance = '"+c2+"', task_comment = '"+c3+"'"
                        " WHERE task_key="+indid+";");

    if (setquery1->lastError().isValid()) {
        QMessageBox::critical(nullptr, "Ошибка редактирования", setquery1->lastError().text() );
    }

    model->setTable("usertask");
    model->select();

    ui->cbox_taskStatus->currentText()="";
    ui->date_taskDecision->setDate(QDate::currentDate());
    ui->text_taskComment->setText("");

    showTaskTable();
}

void DispatcherWindow::on_butt_taskCancel_clicked()
{
    ui->cbox_taskStatus->currentText()="";
    ui->date_taskDecision->setDate(QDate::currentDate());
    ui->text_taskComment->clear();
    ui->group_editStatus->setVisible(false);
    showTaskTable();
}

void DispatcherWindow::on_butt_task_delete_clicked()
{
    QSqlQueryModel *setquery1 = new QSqlQueryModel; //запрос
    QSqlTableModel *model = new QSqlTableModel; // отображение
    QTableView *tv = new QTableView(this);
    QItemSelectionModel *selectModel = ui->tableTaskView->selectionModel();

    if(!selectModel->selectedRows().isEmpty())   //проверяем выделили ли строку (не пустая ли)
    {

        int nr = selectModel->selectedRows().first().row();  //вписываем номер строки
        if (QMessageBox::Yes == QMessageBox::question(nullptr, "Удалить?",
                                                      "Уверены?",
                                                      QMessageBox::Yes|QMessageBox::No))
        {
            QString indid = ui->tableTaskView->model()->data(ui->tableTaskView->model()->index(nr,0)).toString();

            setquery1->setQuery("DELETE FROM usertask WHERE task_key="+indid+";");

            if (setquery1->lastError().isValid()) {
                QMessageBox::critical(nullptr, "Ошибка удаления", setquery1->lastError().text() );
            }
            QMessageBox::information(nullptr, "Удалено", "Строка успешно удалена!");

            tv->setModel(setquery1);
            ui->tableTaskView->setModel(setquery1);
            ColumnTaskHeaders(*model);
            model->setTable("usertask");
            model->select();

            ui->tableTaskView->setModel(model);

        }
    }
    else
    {
        QMessageBox::warning(nullptr, "Ошибка", "Строка не выделена.");
    }
}

void DispatcherWindow::on_butt_task_status_clicked()
{
    // Все задания от меня
    QTableView view;
    QSqlTableModel *model = new QSqlTableModel;
    QSettings *uSett = new QSettings(UserSett, QSettings::IniFormat);
    QString currUserName;
    currUserName = (uSett->value("User_Settings/currentUser","").toString());
    model->setTable("usertask");
    model->setFilter("task_from='"+currUserName+"'");
    model->select();
    ui->tableTaskView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QFont headerFont;
    headerFont.bold();
    headerFont.setPointSize(14);
    ColumnTaskHeaders(*model);
    ui->tableTaskView->setModel(model);
}

void DispatcherWindow::on_butt_task_view_clicked()
{
    // Все задания для меня
    QTableView view;
    QSqlTableModel *model = new QSqlTableModel;
    QSettings *uSett = new QSettings(UserSett, QSettings::IniFormat);
    QString currUserName;
    currUserName = (uSett->value("User_Settings/currentUser","").toString());
    model->setTable("usertask");
    model->setFilter("task_target='"+currUserName+"'");
    model->select();
    ui->tableTaskView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QFont headerFont;
    headerFont.bold();
    headerFont.setPointSize(14);
    ColumnTaskHeaders(*model);
    ui->tableTaskView->setModel(model);
}

void DispatcherWindow::showMiniMainTable(QString mainTableName, QString prefix)
{

    QSqlQueryModel *setquery1 = new QSqlQueryModel;
    QSqlTableModel *model = new QSqlTableModel;
    setquery1->setQuery("SELECT "
                        ""+prefix+"KeyWay, "
                        ""+prefix+"NumberFlowShip, "
                        ""+prefix+"ShipName, "
                        ""+prefix+"Flag, "
                        ""+prefix+"ShipDesign, "
                        ""+prefix+"DraftDesign, "
                        ""+prefix+"Shipowner, "
                        ""+prefix+"CargoPassenger, "
                        ""+prefix+"Tonnage, "
                        ""+prefix+"Sedimit, "
                        ""+prefix+"Departure, "
                        ""+prefix+"Location, "
                        ""+prefix+"DepartureDate, "
                        ""+prefix+"Destination, "
                        ""+prefix+"Location_2, "
                        ""+prefix+"ArrivalDate, "
                        ""+prefix+"MarkDate, "
                        ""+prefix+"PoolName, "
                        ""+prefix+"Dispatcher "
                        "FROM "+mainTableName+"");
    if (setquery1->lastError().isValid()) {
        QMessageBox::critical(nullptr, "Ошибка данных", setquery1->lastError().text() );
    }

    model->select();

    ColumnMainMinimumHeaders(*setquery1);

    ui->tableDBView->setModel(setquery1);
    ui->tableDBView->setColumnHidden(0, true);
}

void DispatcherWindow::showMaximumMainTable(QString mainTableName)
{

    QSqlQueryModel *setquery1 = new QSqlQueryModel;
    QSqlTableModel *model = new QSqlTableModel;
    setquery1->setQuery("SELECT * "
                        "FROM "+mainTableName+"");
    if (setquery1->lastError().isValid()) {
        QMessageBox::critical(nullptr, "Ошибка данных", setquery1->lastError().text() );
    }

    model->select();

    if(mainTableName == "cargotransportation")
        ColumnHeadersCargo(*setquery1);
    else if(mainTableName == "cargopassenger")
        ColumnHeadersPassengers(*setquery1);

    ui->tableDBView->setModel(setquery1);
    ui->tableDBView->setColumnHidden(0, true);
}

void DispatcherWindow::on_butt_showMainColumns_clicked()
{
    // Показать основные столбцы
    if (ui->label_mainTableName->text() == "table_cargo"){
        //функция для установки столбцов в главной таблице грузоперевозок
        showMiniMainTable("cargotransportation", "");
    }
    else if (ui->label_mainTableName->text() == "table_passenger"){
        //функция для установки столбцов в главной таблице пассажироперевозки
        showMiniMainTable("cargopassenger", "P_");
    }
    ui->label_mainTableType->setText("table_min");
}

void DispatcherWindow::on_butt_showAllColumns_clicked()
{
    // Показать все столбцы
    if (ui->label_mainTableName->text() == "table_cargo"){
        showMaximumMainTable("cargotransportation");
    }
    else if (ui->label_mainTableName->text() == "table_passenger"){
        showMaximumMainTable("cargopassenger");
    }
    ui->label_mainTableType->setText("table_max");
}

void DispatcherWindow::on_butt_today_clicked()
{
    // Показать записи за сегодня (все)

}

void DispatcherWindow::on_butt_deleteNote_clicked()
{
    // текущая таблица
    QString mainTableName;
    QString key;
    if (ui->label_mainTableName->text() == "table_cargo"){
        mainTableName = "cargotransportation";
        key = "KeyWay";
    }
    else if (ui->label_mainTableName->text() == "table_passenger"){
        mainTableName = "cargopassenger";
        key = "P_KeyWay";
    }
    // Удалить строку
    QSqlQueryModel *setquery1 = new QSqlQueryModel; //запрос
    QSqlTableModel *model = new QSqlTableModel; // отображение
    QTableView *tv = new QTableView(this);
    QItemSelectionModel *selectModel = ui->tableDBView->selectionModel();

    if(!selectModel->selectedRows().isEmpty())   //проверяем выделили ли строку (не пустая ли)
    {

        int nr = selectModel->selectedRows().first().row();  //вписываем номер строки
        if (QMessageBox::Yes == QMessageBox::question(nullptr, "Удалить?",
                                                      "Уверены?",
                                                      QMessageBox::Yes|QMessageBox::No))
        {
            QString indid = ui->tableDBView->model()->data(ui->tableDBView->model()->index(nr,0)).toString();

            setquery1->setQuery("DELETE FROM "+mainTableName+" WHERE "+key+"="+indid+";");

            if (setquery1->lastError().isValid()) {
                QMessageBox::critical(nullptr, "Ошибка удаления", setquery1->lastError().text() );
            }
            QMessageBox::information(nullptr, "Удалено", "Строка успешно удалена!");

            tv->setModel(setquery1);
            ui->tableDBView->setModel(setquery1);
            if(mainTableName == "cargotransportation"){
                ColumnHeadersCargo(*model);
                model->setTable(mainTableName);
            }
            else if(mainTableName == "cargopassenger"){
                ColumnHeadersPassengers(*model);
                model->setTable(mainTableName);
            }
            model->select();

            ui->tableDBView->setModel(model);

        }
    }
    else
    {
        QMessageBox::warning(nullptr, "Ошибка", "Строка не выделена.");
    }
}

void DispatcherWindow::on_butt_thisWeek_clicked()
{
    // за текущую ндеелю
    QString mainTableName;
    QString key;
    QString prefix;
    if (ui->label_mainTableName->text() == "table_cargo"){
        mainTableName = "cargotransportation";
        key = "KeyWay";
        prefix = "";
    }
    else if (ui->label_mainTableName->text() == "table_passenger"){
        mainTableName = "cargopassenger";
        key = "P_KeyWay";
        prefix = "P_";
    }
    QSqlQueryModel *setquery1 = new QSqlQueryModel;
    QSqlTableModel *model = new QSqlTableModel;

    if (ui->label_mainTableType->text() == "type_max"){
        //полная
        setquery1->setQuery("SELECT * "
                            "FROM "+mainTableName+" "
                            "WHERE YEAR(`"+prefix+"ArrivalDate`) = YEAR(NOW()) AND WEEK(`"+prefix+"ArrivalDate`, 1) = WEEK(NOW(), 1)");
    }
    else if(ui->label_mainTableType->text() == "type_min"){
        //сокращеная
        setquery1->setQuery("SELECT "
                            ""+prefix+"KeyWay, "
                            ""+prefix+"NumberFlowShip, "
                            ""+prefix+"ShipName, "
                            ""+prefix+"Flag, "
                            ""+prefix+"ShipDesign, "
                            ""+prefix+"DraftDesign, "
                            ""+prefix+"Shipowner, "
                            ""+prefix+"CargoPassenger, "
                            ""+prefix+"Tonnage, "
                            ""+prefix+"Sedimit, "
                            ""+prefix+"Departure, "
                            ""+prefix+"Location, "
                            ""+prefix+"DepartureDate, "
                            ""+prefix+"Destination, "
                            ""+prefix+"Location_2, "
                            ""+prefix+"ArrivalDate, "
                            ""+prefix+"MarkDate, "
                            ""+prefix+"PoolName, "
                            ""+prefix+"Dispatcher "
                            "FROM "+mainTableName+" "
                            "WHERE YEAR(`"+prefix+"ArrivalDate`) = YEAR(NOW()) AND WEEK(`"+prefix+"ArrivalDate`, 1) = WEEK(NOW(), 1)");
    }

    if (setquery1->lastError().isValid()) {
        QMessageBox::critical(nullptr, "Ошибка данных", setquery1->lastError().text() );
    }

    model->select();

    if(ui->label_mainTableName->text() == "table_passenger"){
        if(ui->label_mainTableType->text() == "type_max"){
            ColumnHeadersPassengers(*setquery1);
        }
        else if(ui->label_mainTableType->text() == "type_min"){
            ColumnMainMinimumHeaders(*setquery1);
        }
    }
    else if(ui->label_mainTableName->text() == "table_cargo"){
        if(ui->label_mainTableType->text() == "type_max"){
            ColumnHeadersCargo(*setquery1);
        }
        else if(ui->label_mainTableType->text() == "type_min"){
            ColumnMainMinimumHeaders(*setquery1);
        }
    }

    ui->tableDBView->setModel(setquery1);
    ui->tableDBView->setColumnHidden(0, true);
}

void DispatcherWindow::on_butt_thisMonth_clicked()
{
    // за текущий месяц
    QString mainTableName;
    QString key;
    QString prefix;
    if (ui->label_mainTableName->text() == "table_cargo"){
        mainTableName = "cargotransportation";
        key = "KeyWay";
        prefix = "";
    }
    else if (ui->label_mainTableName->text() == "table_passenger"){
        mainTableName = "cargopassenger";
        key = "P_KeyWay";
        prefix = "P_";
    }
    QSqlQueryModel *setquery1 = new QSqlQueryModel;
    QSqlTableModel *model = new QSqlTableModel;

    if (ui->label_mainTableType->text() == "type_max"){
        //полная
        setquery1->setQuery("SELECT * "
                            "FROM "+mainTableName+" "
                            "WHERE MONTH(`"+prefix+"ArrivalDate`) = MONTH(NOW()) AND YEAR(`"+prefix+"ArrivalDate`) = YEAR(NOW())");
    }
    else if(ui->label_mainTableType->text() == "type_min"){
        //сокращеная
        setquery1->setQuery("SELECT "
                            ""+prefix+"KeyWay, "
                            ""+prefix+"NumberFlowShip, "
                            ""+prefix+"ShipName, "
                            ""+prefix+"Flag, "
                            ""+prefix+"ShipDesign, "
                            ""+prefix+"DraftDesign, "
                            ""+prefix+"Shipowner, "
                            ""+prefix+"CargoPassenger, "
                            ""+prefix+"Tonnage, "
                            ""+prefix+"Sedimit, "
                            ""+prefix+"Departure, "
                            ""+prefix+"Location, "
                            ""+prefix+"DepartureDate, "
                            ""+prefix+"Destination, "
                            ""+prefix+"Location_2, "
                            ""+prefix+"ArrivalDate, "
                            ""+prefix+"MarkDate, "
                            ""+prefix+"PoolName, "
                            ""+prefix+"Dispatcher "
                            "FROM "+mainTableName+" "
                            "WHERE MONTH(`"+prefix+"ArrivalDate`) = MONTH(NOW()) AND YEAR(`"+prefix+"ArrivalDate`) = YEAR(NOW())");
    }

    if (setquery1->lastError().isValid()) {
        QMessageBox::critical(nullptr, "Ошибка данных", setquery1->lastError().text() );
    }

    model->select();

    if(ui->label_mainTableName->text() == "table_passenger"){
        if(ui->label_mainTableType->text() == "type_max"){
            ColumnHeadersPassengers(*setquery1);
        }
        else if(ui->label_mainTableType->text() == "type_min"){
            ColumnMainMinimumHeaders(*setquery1);
        }
    }
    else if(ui->label_mainTableName->text() == "table_cargo"){
        if(ui->label_mainTableType->text() == "type_max"){
            ColumnHeadersCargo(*setquery1);
        }
        else if(ui->label_mainTableType->text() == "type_min"){
            ColumnMainMinimumHeaders(*setquery1);
        }
    }

    ui->tableDBView->setModel(setquery1);
    ui->tableDBView->setColumnHidden(0, true);
}


void DispatcherWindow::on_butt_lastMonth_clicked()
{
    // за прошлый месяц
    QString mainTableName;
    QString key;
    QString prefix;
    if (ui->label_mainTableName->text() == "table_cargo"){
        mainTableName = "cargotransportation";
        key = "KeyWay";
        prefix = "";
    }
    else if (ui->label_mainTableName->text() == "table_passenger"){
        mainTableName = "cargopassenger";
        key = "P_KeyWay";
        prefix = "P_";
    }
    QSqlQueryModel *setquery1 = new QSqlQueryModel;
    QSqlTableModel *model = new QSqlTableModel;

    if (ui->label_mainTableType->text() == "type_max"){
        //полная
        setquery1->setQuery("SELECT * "
                            "FROM "+mainTableName+" "
                            "WHERE MONTH(`"+prefix+"ArrivalDate`) = MONTH(DATE_ADD(NOW(), INTERVAL -1 MONTH)) AND YEAR(`"+prefix+"ArrivalDate`) = YEAR(NOW())");
    }
    else if(ui->label_mainTableType->text() == "type_min"){
        //сокращеная
        setquery1->setQuery("SELECT "
                            ""+prefix+"KeyWay, "
                            ""+prefix+"NumberFlowShip, "
                            ""+prefix+"ShipName, "
                            ""+prefix+"Flag, "
                            ""+prefix+"ShipDesign, "
                            ""+prefix+"DraftDesign, "
                            ""+prefix+"Shipowner, "
                            ""+prefix+"CargoPassenger, "
                            ""+prefix+"Tonnage, "
                            ""+prefix+"Sedimit, "
                            ""+prefix+"Departure, "
                            ""+prefix+"Location, "
                            ""+prefix+"DepartureDate, "
                            ""+prefix+"Destination, "
                            ""+prefix+"Location_2, "
                            ""+prefix+"ArrivalDate, "
                            ""+prefix+"MarkDate, "
                            ""+prefix+"PoolName, "
                            ""+prefix+"Dispatcher "
                            "FROM "+mainTableName+" "
                            "WHERE MONTH(`"+prefix+"ArrivalDate`) = MONTH(DATE_ADD(NOW(), INTERVAL -1 MONTH)) AND YEAR(`"+prefix+"ArrivalDate`) = YEAR(NOW())");
    }

    if (setquery1->lastError().isValid()) {
        QMessageBox::critical(nullptr, "Ошибка данных", setquery1->lastError().text() );
    }

    model->select();

    if(ui->label_mainTableName->text() == "table_passenger"){
        if(ui->label_mainTableType->text() == "type_max"){
            ColumnHeadersPassengers(*setquery1);
        }
        else if(ui->label_mainTableType->text() == "type_min"){
            ColumnMainMinimumHeaders(*setquery1);
        }
    }
    else if(ui->label_mainTableName->text() == "table_cargo"){
        if(ui->label_mainTableType->text() == "type_max"){
            ColumnHeadersCargo(*setquery1);
        }
        else if(ui->label_mainTableType->text() == "type_min"){
            ColumnMainMinimumHeaders(*setquery1);
        }
    }

    ui->tableDBView->setModel(setquery1);
    ui->tableDBView->setColumnHidden(0, true);
}
