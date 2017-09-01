#include "secdialog.h"
#include "ui_secdialog.h"
#include <QSql>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>


SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);
}

SecDialog::~SecDialog()
{
    delete ui;
}

void SecDialog::on_pushButton_clicked()
{
    int usertype=-1;
    QString username,password;
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
            qry.first();
            QString type = qry.value(2).toString();
            //qDebug() << username;
            //qDebug() << qry.value(0)<<qry.value(1)<<qry.value(2)<<qry.value(3);
            if (type == "admin"){
                hide();
                QMessageBox::information(this,"登陆成功","管理员，欢迎你登陆图书馆");
                usertype = 1;
                emit SendUserType(usertype,username);
                return;
                }
            if (type == "client"){
                hide();
                QMessageBox::information(this,"登陆成功","读者，欢迎你登陆图书馆");
                usertype=0;
                emit SendUserType(usertype, username);
                return;
                }
        }
        if(count > 1){
            QMessageBox::critical(this,"登陆失败","数据库中此用户名重复");
            return;
        }
        if(count < 1){
            QMessageBox::critical(this,"登陆失败","账号密码错误");
            return;
        }


     }

}
