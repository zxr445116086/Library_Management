#include "booksearchbyauthor.h"
#include "ui_booksearchbyauthor.h"
#include <QSqlTableModel>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>

BookSearchByAuthor::BookSearchByAuthor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BookSearchByAuthor)
{
    ui->setupUi(this);
}

BookSearchByAuthor::~BookSearchByAuthor()
{
    delete ui;
}

void BookSearchByAuthor::on_pushButton_clicked()
{
    QString authorname,result,result1;
    QSqlQuery qry;
    authorname = ui->lineEdit->text();
    if(qry.exec("select * from 图书信息 where 作者='"+authorname+"'")){
        while(qry.next()){
            result = "编号:"+qry.value(0).toString()+" "
                    +"书号："+qry.value(1).toString()+" "
                    +"类型："+qry.value(2).toString()+" "
                    +"书名："+qry.value(3).toString()+" "
                    +"作者:"+qry.value(4).toString()+" "
                    +"出版社："+qry.value(5).toString()+" "
                    +"是否在馆："+qry.value(6).toString()+" "
                    +"借书人："+qry.value(7).toString();
            result1 += (result + "\n");
        }
    QMessageBox::information(this,"查询成功",result1);
    return;
    }
}
