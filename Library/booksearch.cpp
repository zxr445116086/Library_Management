#include "booksearch.h"
#include "ui_booksearch.h"
#include <QSqlTableModel>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>

BookSearch::BookSearch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BookSearch)
{
    ui->setupUi(this);
}

BookSearch::~BookSearch()
{
    delete ui;
}

void BookSearch::on_radioButton_clicked()
{
    ui->lineEdit->setEnabled(true);
    ui->lineEdit_2->setDisabled(true);
}

void BookSearch::on_radioButton_2_clicked()
{
    ui->lineEdit->setDisabled(true);
    ui->lineEdit_2->setEnabled(true);
}

void BookSearch::on_pushButton_clicked()
{
    QString bookname,booknum;
    QSqlQuery qry;
    int count = 0;
    if(ui->radioButton->isChecked()){
        booknum = ui->lineEdit->text();
        if(qry.exec("select * from 图书信息 where 书号='"+booknum+"'"))
        {
            while(qry.next()){
                count++;
            }
        }
        if(count == 1){
            qry.first();
            QString result = "编号:"+qry.value(0).toString()+"  "
                    +"书号："+qry.value(1).toString()+"  "
                    +"类型："+qry.value(2).toString()+"  "
                    +"书名："+qry.value(3).toString()+"  "
                    +"作者:"+qry.value(4).toString()+"  "
                    +"出版社："+qry.value(5).toString()+"  "
                    +"是否在馆："+qry.value(6).toString()+"  "
                    +"借书人："+qry.value(7).toString();
            QMessageBox::information(this,"查询成功",result);
            return;
        }
        if(count > 1){
            QMessageBox::critical(this,"查询失败","图书馆中此书号重复");
            return;
        }
        if(count < 1){
            QMessageBox::critical(this,"查询失败","图书馆中无此藏书");
            return;
        }
    }

    if(ui->radioButton_2->isChecked()){
        bookname = ui->lineEdit_2->text();
        if( qry.exec("select * from 图书信息 where 书名='"+bookname+"'")){
            while(qry.next()){
                count++;
            }
        }
        if(count == 1){
            qry.first();
            QString result = "编号:"+qry.value(0).toString()+"  "
                    +"书号："+qry.value(1).toString()+"  "
                    +"类型："+qry.value(2).toString()+"  "
                    +"书名："+qry.value(3).toString()+"  "
                    +"作者:"+qry.value(4).toString()+"  "
                    +"出版社："+qry.value(5).toString()+"  "
                    +"是否在馆："+qry.value(6).toString()+"  "
                    +"借书人："+qry.value(7).toString();
            QMessageBox::information(this,"查询成功",result);
            return;
        }
        if(count > 1){
            QMessageBox::critical(this,"查询失败","图书馆中此书名重复");
            return;
        }
        if(count < 1){
            QMessageBox::critical(this,"查询失败","图书馆中无此藏书");
            return;
        }
    }












}
