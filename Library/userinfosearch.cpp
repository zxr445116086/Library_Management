#include "userinfosearch.h"
#include "ui_userinfosearch.h"
#include <QMessageBox>

#include <QSqlQuery>

UserInfoSearch::UserInfoSearch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserInfoSearch)
{
    ui->setupUi(this);
}

UserInfoSearch::~UserInfoSearch()
{
    delete ui;
}

void UserInfoSearch::on_pushButton_clicked()
{   QString yonghuleixing;
    int count = 0;
    QString username = ui->lineEdit->text();
    QSqlQuery qry;
    if(qry.exec("select * from UserInfoTable where 用户名='"+username+"'"))
    {
        while(qry.next()){
            count++;
        }
    }
    if(count == 0){
        QMessageBox::warning(this,"查询失败","未发现此用户，请仔细检查");
    }
    if(count == 1){
        qry.first();
        if(qry.value(2).toString() == "admin"){
            yonghuleixing = "管理员";
        }
        if(qry.value(2).toString() == "client"){
            yonghuleixing = "普通用户";
        }
        QString result = "编号:"+qry.value(0).toString()+"  "
                +"用户名："+qry.value(1).toString()+"  "
                +"用户类型："+yonghuleixing+"  "
                +"借阅信息:"+qry.value(4).toString();
        hide();
        QMessageBox::information(this,"用户信息查询成功",result);
    }
}
