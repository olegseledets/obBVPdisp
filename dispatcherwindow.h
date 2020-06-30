#ifndef DISPATCHERWINDOW_H
#define DISPATCHERWINDOW_H

#include "datafromfile.h"

#include <QMainWindow>
#include <QCloseEvent>
#include <QSystemTrayIcon>
#include <QAction>
#include <QLabel>
#include <QStyle>
#include <QDateTime>
#include "filterwindow.h"


#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class DispatcherWindow; }
QT_END_NAMESPACE

class DispatcherWindow : public QMainWindow
{
    Q_OBJECT

public:
    DispatcherWindow(QWidget *parent = nullptr);                            // конструктор класса
    ~DispatcherWindow();                                                    // деструктор класса

    void showEvent(QShowEvent *);                                           // открытие формы ( изменение статус бара)

protected:
    template<typename T>
    void ColumnHeadersCargo(T &model);

    template<typename T>
    void ColumnTaskHeaders(T &model);

    template<typename T>
    void ColumnCatalogHeaders(T &model, QString c1,QString c2,QString c3);

    template<typename T>
    void selectCatalogTable(T &model, QString nameCatalogTable);

    void showMainTable(QString nameMainTable);

    void elementsStatusBar();

    void elementsMenuSwitchTable();

    void showTaskTable();

    void showCatalogTable(QString nameDirectoryTable);

    void setFormCatalog(QString tableName, QString c1, QString c2, QString c3);

    void controlPanelElementActive(bool a, bool e, bool d, bool s, QString acceptName);

    void findParamRowToContentTable(QString currentTable, QString currentParam);

    void addRowToContentTable(QString currentTable, QString cn1, QString cn2, QString cn3, QString c1, QString c2, QString c3);

    void searchRowInContentTable(QString currentTable, QString cn1, QString cn2, QString cn3, QString c1, QString c2, QString c3);

    void editRowContentTable(QString currentTable, QString key, QString cn1, QString cn2, QString cn3, QString c1, QString c2, QString c3);

    void deleteRowContentTable(QString currentTable, QString key);

    QString getKeysTable(QString currentTable);

    void cboxTaskSetValueFromDB();

    template<typename T>
    void ColumnHeadersPassengers(T &model);

    template<typename T>
    void ColumnMainMinimumHeaders(T &model);

    void showMiniMainTable(QString mainTableName,QString prefix);

    void showMaximumMainTable(QString mainTableName);

signals:
    void openLoginWindow();  // Сигнал для первого окна на открытие

private slots:
    void iconActivated(QSystemTrayIcon::ActivationReason reason);           // нажатие на иконку в трее

    void on_butt_tray_clicked();                                            // сворачивание в трей

    void on_butt_exit_clicked();

    void on_butt_tableChange_clicked();

    void on_butt_filter_clicked();

    void on_tab_menu_tabBarClicked(int index);

    void on_butt_table_point_clicked();

    void on_butt_table_direction_clicked();

    void on_butt_table_vessel_clicked();

    void on_butt_table_cargo_clicked();

    void on_butt_table_region_clicked();

    void on_butt_table_dimensions_clicked();

    void on_butt_table_pool_clicked();

    void on_butt_table_northDelivery_clicked();

    void on_butt_table_cargoPassenger_clicked();

    void on_butt_typeTransportation_clicked();

    void on_butt_controlAdd_clicked();

    void on_butt_controlDelete_clicked();

    void on_butt_controlEdit_clicked();

    void on_butt_cancelContent_clicked();

    void on_butt_acceptContent_clicked();

    void on_butt_controlSearch_clicked();

    void on_butt_task_add_clicked();

    void on_butt_task_edit_clicked();

    void on_butt_taskAdd_clicked();

    void on_butt_taskClear_clicked();

    void on_butt_taskEditStatus_clicked();

    void on_butt_taskCancel_clicked();

    void on_butt_task_delete_clicked();

    void on_butt_task_status_clicked();

    void on_butt_task_view_clicked();

    void on_butt_showMainColumns_clicked();

    void on_butt_showAllColumns_clicked();

    void on_butt_today_clicked();

    void on_butt_deleteNote_clicked();

    void on_butt_thisWeek_clicked();

    void on_butt_thisMonth_clicked();

    void on_butt_lastMonth_clicked();

private:
    Ui::DispatcherWindow *ui;                                               // текущее окно
    QSystemTrayIcon      * trayIcon;                                        // иконка трея
    filterWindow         * filterWind;                                      // окно фильтра
};
#endif // DISPATCHERWINDOW_H
