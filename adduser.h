#ifndef ADDUSER_H
#define ADDUSER_H

#include <QDialog>

namespace Ui {
class addUser;
}

class addUser : public QDialog
{
    Q_OBJECT

public:
    explicit addUser(QWidget *parent = nullptr);
    ~addUser();

private:
    Ui::addUser *ui;
};

#endif // ADDUSER_H
