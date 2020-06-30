#ifndef FILTERWINDOW_H
#define FILTERWINDOW_H

#include <QDialog>

namespace Ui {
class filterWindow;
}

class filterWindow : public QDialog
{
    Q_OBJECT

public:
    explicit filterWindow(QWidget *parent = nullptr);
    ~filterWindow();

signals:
    void openFilterWindow();                                // Сигнал для первого окна на открытие

protected:
    void clearFilterElement();
private slots:
    void on_butt_cancel_clicked();

    void on_butt_clearFilter_clicked();

    void on_butt_accept_clicked();

private:
    Ui::filterWindow *ui;
};

#endif // FILTERWINDOW_H
