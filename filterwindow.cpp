#include "dispatcherwindow.h"
#include "filterwindow.h"
#include "ui_filterwindow.h"

filterWindow::filterWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::filterWindow)
{
    ui->setupUi(this);
}

filterWindow::~filterWindow()
{
    delete ui;
}

void filterWindow::on_butt_cancel_clicked()
{
    // выход из окна
    clearFilterElement();
    this->close();
}

void filterWindow::clearFilterElement()
{
    ui->cbox_shipName->setCurrentIndex(-1);
    ui->cbox_cargo->setCurrentIndex(-1);
    ui->cbox_pointExit->setCurrentIndex(-1);
    ui->cbox_shipowner->setCurrentIndex(-1);
    ui->cbox_pointEnter->setCurrentIndex(-1);
    QDate dateFrom;
    dateFrom.setDate(2000,01,01);
    ui->date_exitFrom->setDate(dateFrom);
    ui->date_enterFrom->setDate(dateFrom);
    QDate dateBefore;
    dateBefore.setDate(2030,01,01);
    ui->date_exitBefore->setDate(dateBefore);
    ui->date_enterBefore->setDate(dateBefore);
}

void filterWindow::on_butt_clearFilter_clicked()
{
    clearFilterElement();
}

void filterWindow::on_butt_accept_clicked()
{
    // применить фильтр

}
