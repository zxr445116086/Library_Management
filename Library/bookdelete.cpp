#include "bookdelete.h"
#include "ui_bookdelete.h"
#include <QSqlTableModel>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>

BookDelete::BookDelete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BookDelete)
{
    ui->setupUi(this);
}

BookDelete::~BookDelete()
{
    delete ui;
}

void BookDelete::on_pushButton_clicked()
{
    QString booknum,bookname;
    QSqlQuery qry;
    int count = 0;
    booknum = ui->lineEdit->text();
    bookname = ui->lineEdit_2->text();
    if(ui->radioButton->isChecked()){
        ui->lineEdit->setEnabled(true);
        ui->lineEdit_2->setDisabled(true);

        if(qry.exec("select * from 图书信息 where 书号='"+booknum+"'"))
        {
            while(qry.next()){
                count++;
            }
            if(count == 1){
                qry.exec("delete from 图书信息 where 书号='"+booknum+"'");
                hide();
                QMessageBox::information(this,"删除成功","成功从数据库中删除图书");
                return;
            }
            if(count > 1){
                hide();
                QMessageBox::critical(this,"删除失败","数据库中此书名重复");
                return;
            }
            if(count < 1){
                hide();
                QMessageBox::critical(this,"删除失败","未发现图书，删除失败，请重试");
                return;
            }
         }
    }

    if(ui->radioButton_2->isChecked()){
        ui->lineEdit->setDisabled(true);
        ui->lineEdit_2->setEnabled(true);

        if(qry.exec("select * from 图书信息 where 书名='"+bookname+"'"))
        {
            while(qry.next()){
                count++;
            }
            if(count == 1){
                qry.exec("delete from 图书信息 where 书名='"+bookname+"'");
                hide();
                QMessageBox::information(this,"删除成功","成功从数据库中删除图书");
                return;
            }
            if(count > 1){
                hide();
                QMessageBox::critical(this,"删除失败","数据库中此书名重复");
                return;
            }
            if(count < 1){
                hide();
                QMessageBox::critical(this,"删除失败","未发现图书，删除失败，请重试");
                return;
            }
         }
    }



}
