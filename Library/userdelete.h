#ifndef USERDELETE_H
#define USERDELETE_H

#include <QDialog>


namespace Ui {
class UserDelete;
}

class UserDelete : public QDialog
{
    Q_OBJECT

public:
    explicit UserDelete(QWidget *parent = 0);
    ~UserDelete();

private slots:
    void on_pushButton_clicked();

private:
    Ui::UserDelete *ui;
};

#endif // USERDELETE_H
