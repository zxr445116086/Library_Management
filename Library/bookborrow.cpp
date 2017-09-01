#include "bookborrow.h"
#include "ui_bookborrow.h"
#include <QSqlTableModel>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>

BookBorrow::BookBorrow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BookBorrow)
{
    ui->setupUi(this);
}

BookBorrow::~BookBorrow()
{
    delete ui;
}

void BookBorrow::on_radioButton_clicked()
{
    ui->lineEdit->setEnabled(true);
    ui->lineEdit_2->setDisabled(true);
}

void BookBorrow::on_radioButton_2_clicked()
{
    ui->lineEdit->setDisabled(true);
    ui->lineEdit_2->setEnabled(true);
}

void BookBorrow::on_pushButton_clicked()
{
    QString booknum,bookname,borrowperson;
    QSqlQuery qry1,qry2;
    int count1 = 0;
    int count2 = 0;
    booknum = ui->lineEdit->text();
    bookname = ui->lineEdit_2->text();
    borrowperson = ui->lineEdit_3->text();
    if(ui->radioButton->isChecked()){
        if(qry2.exec("select * from 图书信息 where 书号='"+booknum+"'"))
        {
            while(qry2.next()){
                count2++;
            }
        }
        if(count2 == 1){
            qry2.first();
            QString booktype = qry2.value(2).toString();
            if(booktype == "馆藏精品"){
                hide();
                QMessageBox::warning(this,"借阅失败","此图书属于馆藏精品，不可借阅");
                return;
            }
            bookname = qry2.value(3).toString();
            QString bookstatus = qry2.value(6).toString();
            if(bookstatus == "是"){
                if(qry1.exec("select * from UserInfoTable where 用户名='"+borrowperson+"'"))
                {
                    while(qry1.next()){
                        count1++;
                    }
                }
                if(count1 == 1){
                    qry1.first();
                    QString status = qry1.value(4).toString();
                    if (status == "无"){
                        qry2.exec("select * from 图书信息 where 书号='"+booknum+"'");
                        qry2.first();
                        qry2.prepare("update 图书信息 set 是否在馆='否', 借书人='"+borrowperson+"' where 书号='"+booknum+"'");
                        qry1.exec("select * from UserInfoTable where 用户名='"+borrowperson+"'");
                        qry1.first();
                        qry1.prepare("update UserInfoTable set 借阅信息='"+bookname+"' where 用户名='"+borrowperson+"'");
                        if(qry1.exec() && qry2.exec()){
                            hide();
                            QMessageBox::information(this,"借阅成功","图书借阅成功");
                            return;
                        }
                    }else{
                        hide();
                        QMessageBox::warning(this,"借阅失败","此用户已借阅图书，请仔细检查");
                        return;
                    }
                }
            }else{
                hide();
                QMessageBox::warning(this,"借阅失败","图书已被借阅，无法借阅该图书");
                return;
            }
        }
        else{
            hide();
            QMessageBox::warning(this,"借阅失败","未发现该图书，请重试");
            return;
        }
    }

    if(ui->radioButton_2->isChecked()){
        if(qry2.exec("select * from 图书信息 where 书名='"+bookname+"'"))
        {
            while(qry2.next()){
                count2++;
            }
        }
        if(count2 == 1){
            qry2.first();
            QString booktype = qry2.value(2).toString();
            if(booktype == "馆藏精品"){
                hide();
                QMessageBox::warning(this,"借阅失败","此图书属于馆藏精品，不可借阅");
                return;
            }
            QString bookstatus = qry2.value(6).toString();
            if(bookstatus == "是"){
                if(qry1.exec("select * from UserInfoTable where 用户名='"+borrowperson+"'"))
                {
                    while(qry1.next()){
                        count1++;
                    }
                }
                if(count1 == 1){
                    qry1.first();
                    QString status = qry1.value(4).toString();
                    if (status == "无"){
                        qry2.exec("select * from 图书信息 where 书名='"+bookname+"'");
                        qry2.first();
                        qry2.prepare("update 图书信息 set 是否在馆='否', 借书人='"+borrowperson+"' where 书名='"+bookname+"'");
                        qry1.exec("select * from UserInfoTable where 用户名='"+borrowperson+"'");
                        qry1.first();
                        qry1.prepare("update UserInfoTable set 借阅信息='"+bookname+"' where 用户名='"+borrowperson+"'");
                        if(qry1.exec() && qry2.exec()){
                            hide();
                            QMessageBox::information(this,"借阅成功","图书借阅成功");
                            return;
                        }
                    }else{
                        hide();
                        QMessageBox::warning(this,"借阅失败","此用户已借阅图书，请仔细检查");
                        return;
                    }
                }
            }else{
                hide();
                QMessageBox::warning(this,"借阅失败","图书已被借阅，无法借阅该图书");
                return;
            }
        }
        else{
            hide();
            QMessageBox::warning(this,"借阅失败","未发现该图书，请重试");
            return;
        }
    }


}
