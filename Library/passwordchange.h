#ifndef PASSWORDCHANGE_H
#define PASSWORDCHANGE_H

#include <QDialog>

namespace Ui {
class PasswordChange;
}

class PasswordChange : public QDialog
{
    Q_OBJECT

public:
    explicit PasswordChange(QWidget *parent = 0);
    ~PasswordChange();

private slots:
    void on_pushButton_clicked();

private:
    Ui::PasswordChange *ui;

signals:
    void SendPassword(QString, QString);
};

#endif // PASSWORDCHANGE_H
