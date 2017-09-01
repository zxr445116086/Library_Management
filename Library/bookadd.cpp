#include "bookadd.h"
#include "ui_bookadd.h"
#include <QSqlTableModel>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>

BookAdd::BookAdd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BookAdd)
{
    ui->setupUi(this);
}

BookAdd::~BookAdd()
{
    delete ui;
}

void BookAdd::on_pushButton_clicked()
{
    QString num,booknum,booktype,bookname,author,press;
    num = ui->lineEdit->text();
    booknum = ui->lineEdit_2->text();
    booktype = ui->lineEdit_3->text();
    bookname = ui->lineEdit_4->text();
    author = ui->lineEdit_5->text();
    press = ui->lineEdit_6->text();
    if(num == NULL || booknum == NULL || booktype == NULL || bookname == NULL || author == NULL || press == NULL){
        QMessageBox::critical(this,"图书信息输入不全","图书信息输入不全，请重试");
        return;
        }
    QSqlQuery qry;
    int count = 0;
    if(qry.exec("select * from 图书信息 where 书号='"+booknum+"'"))
    {
        while(qry.next()){
            count++;
        }
    }
    if(qry.exec("select * from 图书信息 where 书名='"+bookname+"'"))
    {
        while(qry.next()){
            count++;
        }
    }
    if(count == 0){
        QString str = "insert into 图书信息 (编号,书号,类型,书名,作者,出版社,是否在馆,借书人) values ('"
             +num+"','"+booknum+"','"+booktype+"','"+bookname+"','"+author+"','"
             +press+"','"+"是"+"','"+"无"+"')";
        qry.prepare(str);
        if(qry.exec())
            hide();
            QMessageBox::information(this,"写入成功","图书成功写入数据库");
            return;
    }else{
        hide();
        QMessageBox::warning(this,"写入错误","编号，图书号，图书名重复，请仔细检查");
        return;
    }

}
