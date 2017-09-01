#ifndef USERREGISTER_H
#define USERREGISTER_H

#include <QDialog>

namespace Ui {
class UserRegister;
}

class UserRegister : public QDialog
{
    Q_OBJECT

public:
    explicit UserRegister(QWidget *parent = 0);
    ~UserRegister();

private slots:
    void on_pushButton_clicked();

private:
    Ui::UserRegister *ui;
};

#endif // USERREGISTER_H
