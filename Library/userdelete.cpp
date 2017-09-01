#include "userdelete.h"
#include "ui_userdelete.h"
#include <QSqlTableModel>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>

UserDelete::UserDelete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserDelete)
{
    ui->setupUi(this);
}

UserDelete::~UserDelete()
{
    delete ui;
}

void UserDelete::on_pushButton_clicked()
{
    QString username=NULL;
    QString password=NULL;
    username = ui->lineEdit->text();
    password = ui->lineEdit_2->text();
    QSqlQuery qry;
    if(qry.exec("select * from UserInfoTable where 用户名='"+username +"' and 用户密码='"+password+"'"))
    {
        int count = 0;
        while(qry.next()){
            count++;
        }
        if(count == 1){
            qry.exec("delete from UserInfoTable where 用户名='"+username+"'");
            hide();
            QMessageBox::information(this,"删除成功","成功从数据库中删除用户");
            return;
        }
        if(count > 1){
            hide();
            QMessageBox::critical(this,"删除失败","数据库中此用户名重复");
            return;
        }
        if(count < 1){
            hide();
            QMessageBox::critical(this,"删除失败","未发现此用户，删除失败，请重试");
            return;
        }
    }

}
