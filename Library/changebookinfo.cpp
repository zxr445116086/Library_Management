#include "changebookinfo.h"
#include "ui_changebookinfo.h"
#include <QSqlQuery>
#include <QMessageBox>

ChangeBookInfo::ChangeBookInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeBookInfo)
{
    ui->setupUi(this);
}

ChangeBookInfo::~ChangeBookInfo()
{
    delete ui;
}

void ChangeBookInfo::on_pushButton_clicked()
{
    QString num,booknum,booktype,bookname,author,press;
    QSqlQuery qry;
    int count = 0;
    num = ui->lineEdit->text();
    booknum = ui->lineEdit_6->text();
    booktype = ui->lineEdit_2->text();
    bookname = ui->lineEdit_3->text();
    author = ui->lineEdit_4->text();
    press = ui->lineEdit_5->text();
    if(qry.exec("select * from 图书信息 where 书号='"+booknum+"'")){
        while(qry.next()){
            count++;
        }
    }
    if(count == 1){
        if(num == NULL){
            QMessageBox::warning(this,"请填写编号","请填写正确的编号");
            return;
        }
        qry.prepare("update 图书信息 set 编号='"+num+"', 类型='"+booktype+"', 书名='"\
                    +bookname+"',作者='"+author+"',出版社='"+press+"' where 书号='"+booknum+"'");
        if(qry.exec()){
            hide();
            QMessageBox::information(this,"修改成功","修改图书信息成功");
            return;
        }
    }
    else{
        hide();
        QMessageBox::warning(this,"修改失败","未找到图书，请重试");
        return;
    }
}
