#include "userregister.h"
#include "ui_userregister.h"
#include <QSqlTableModel>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>

UserRegister::UserRegister(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserRegister)
{
    ui->setupUi(this);
}

UserRegister::~UserRegister()
{
    delete ui;
}

void UserRegister::on_pushButton_clicked()
{
    QString num=NULL;
    QString username=NULL;
    QString usertype=NULL;
    QString password=NULL;
    QString passwordrepeat=NULL;
    QSqlQuery qry;
    int count = 0;
    num = ui->lineEdit->text();
    username = ui->lineEdit_2->text();
    if(ui->radioButton->isChecked()){
        usertype = "admin";
    }
    if(ui->radioButton_2->isChecked()){
        usertype = "client";
    }
    password = ui->lineEdit_3->text();
    passwordrepeat = ui->lineEdit_4->text();
    if(num == NULL || username == NULL || usertype == NULL || password == NULL || passwordrepeat == NULL){
        QMessageBox::critical(this,"注册信息输入不全","注册信息输入不全，请重试");
        return;
        }
    if(password != passwordrepeat){
        QMessageBox::critical(this,"重复密码不同","两次密码输入不同，请重试");
    }
    if(qry.exec("select * from UserInfoTable where 用户名='"+username+"'"))
    {
        while(qry.next()){
            count++;
        }
    }
    if(count == 0){
        QString str = "insert into UserInfoTable (编号,用户名,用户类型,用户密码,借阅信息) values ('"
             +num+"','"+username+"','"+usertype+"','"+password+"','"+"无"+"')";
        qry.prepare(str);
        if(qry.exec())
            hide();
            QMessageBox::information(this,"注册成功","用户成功注册");
            return;
    }else{
        hide();
        QMessageBox::warning(this,"注册失败","编号或用户名重复，请仔细检查");
        return;
    }

}
