#include "bookreturn.h"
#include "ui_bookreturn.h"
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>

BookReturn::BookReturn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BookReturn)
{
    ui->setupUi(this);
}

BookReturn::~BookReturn()
{
    delete ui;
}

void BookReturn::on_radioButton_clicked()
{
    ui->lineEdit->setEnabled(true);
    ui->lineEdit_2->setDisabled(true);
}

void BookReturn::on_radioButton_2_clicked()
{
    ui->lineEdit->setDisabled(true);
    ui->lineEdit_2->setEnabled(true);
}

void BookReturn::on_pushButton_clicked()
{
    QString booknum,bookname,borrowperson;
    QSqlQuery qry1,qry2;
    int count1 = 0;
    int count2 = 0;


    if(ui->radioButton->isChecked()){
        booknum = ui->lineEdit->text();
        if(qry2.exec("select * from 图书信息 where 书号='"+booknum+"'"))
        {
            while(qry2.next()){
                count2++;
            }
        }
        if(count2 == 1){
            qry2.first();
            QString bookstatus = qry2.value(6).toString();
            bookname = qry2.value(3).toString();
            borrowperson = qry2.value(7).toString();
            if(bookstatus == "否"){
                if(qry1.exec("select * from UserInfoTable where 用户名='"+borrowperson+"'")){
                    while(qry1.next()){
                        count1++;
                    }
                }
                if(count1 == 1){
                    qry1.first();
                    QString status = qry1.value(4).toString();
                    if (status == bookname){
                        qry2.exec("select * from 图书信息 where 书号='"+booknum+"'");
                        qry2.first();
                        qry2.prepare("update 图书信息 set 是否在馆='是', 借书人='无' where 书号='"+booknum+"'");
                        qry1.exec("select * from UserInfoTable where 用户名='"+borrowperson+"'");
                        qry1.first();
                        qry1.prepare("update UserInfoTable set 借阅信息='无' where 用户名='"+borrowperson+"'");
                        if(qry1.exec() && qry2.exec()){
                            hide();
                            QMessageBox::information(this,"归还成功","图书归还成功");
                            return;
                        }
                    }else{
                        hide();
                        QMessageBox::warning(this,"归还失败","此用户并未借阅图书，请仔细检查");
                        return;
                    }
                }
            }else{
                hide();
                QMessageBox::warning(this,"归还失败","图书在馆，无法归还该图书");
                return;
            }
        }
        else{
            hide();
            QMessageBox::warning(this,"归还失败","书号有误，请重试");
            return;
        }

    }

    if(ui->radioButton_2->isChecked()){
        bookname = ui->lineEdit_2->text();
        if(qry2.exec("select * from 图书信息 where 书名='"+bookname+"'"))
        {
            while(qry2.next()){
                count2++;
            }
        }
        if(count2 == 1){
            qry2.first();
            QString bookstatus = qry2.value(6).toString();
            booknum = qry2.value(1).toString();
            borrowperson = qry2.value(7).toString();
            if(bookstatus == "否"){
                if(qry1.exec("select * from UserInfoTable where 用户名='"+borrowperson+"'")){
                    while(qry1.next()){
                        count1++;
                    }
                }
                if(count1 == 1){
                    qry1.first();
                    QString status = qry1.value(4).toString();
                    if (status == bookname){
                        qry2.exec("select * from 图书信息 where 书号='"+booknum+"'");
                        qry2.first();
                        qry2.prepare("update 图书信息 set 是否在馆='是', 借书人='无' where 书号='"+booknum+"'");
                        qry1.exec("select * from UserInfoTable where 用户名='"+borrowperson+"'");
                        qry1.first();
                        qry1.prepare("update UserInfoTable set 借阅信息='无' where 用户名='"+borrowperson+"'");
                        if(qry1.exec() && qry2.exec()){
                            hide();
                            QMessageBox::information(this,"归还成功","图书归还成功");
                            return;
                        }
                    }else{
                        hide();
                        QMessageBox::warning(this,"归还失败","此用户并未借阅图书，请仔细检查");
                        return;
                    }
                }
            }else{
                hide();
                QMessageBox::warning(this,"归还失败","图书在馆，无法归还该图书");
                return;
            }
        }
        else{
            hide();
            QMessageBox::warning(this,"归还失败","书名有误，请重试");
            return;
        }

    }
}
