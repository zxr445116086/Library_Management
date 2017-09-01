#include "passwordchange.h"
#include "ui_passwordchange.h"
#include <QSqlQuery>
#include <QMessageBox>

PasswordChange::PasswordChange(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PasswordChange)
{
    ui->setupUi(this);
}

PasswordChange::~PasswordChange()
{
    delete ui;
}

void PasswordChange::on_pushButton_clicked()
{
    QString oldpw,newpw,repeatnewpw;
    oldpw = ui->lineEdit->text();
    newpw = ui->lineEdit_2->text();
    repeatnewpw = ui->lineEdit_3->text();
    if(newpw != repeatnewpw){
        QMessageBox::warning(this,"密码不一致","两次输入密码不一致，请重试");
    }
    if(oldpw==NULL || newpw == NULL || repeatnewpw == NULL){
        QMessageBox::warning(this,"有空白输入框","有空白输入框，请输入完整信息");
    }
    else {
        emit SendPassword(oldpw, newpw);
        hide();
    }

}
