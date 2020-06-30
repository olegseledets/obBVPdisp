#ifndef CONNECTIONSETTINGS_H
#define CONNECTIONSETTINGS_H

#include <QDialog>
#include <QFileInfo>
#include <QMessageBox>
#include <QFileDialog>

namespace Ui {
class ConnectionSettings;
}

class ConnectionSettings : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectionSettings(QWidget *parent = nullptr);
    ~ConnectionSettings();

signals:
    void openLoginWindow();  // Сигнал для первого окна на открытие

protected:
    void clearConnectionSet();

private slots:

    void on_butt_exit_clicked();

    void on_butt_baseCheck_clicked();

    void on_butt_saveSettFile_clicked();

    void on_butt_loadSettFile_clicked();

private:
    Ui::ConnectionSettings *ui;
};

#endif // CONNECTIONSETTINGS_H
