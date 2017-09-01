#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlError>
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mModel = new QSqlTableModel(this);

}

MainWindow::~MainWindow()
{
    delete ui;

}



void MainWindow::ReceiveUserType(int a, QString b){
    usertype = a;
    username = b;
    if(usertype == 0){
        ui->action_2->setEnabled(true);
        ui->action_6->setEnabled(true);
        ui->action_7->setEnabled(true);
        ui->action_8->setEnabled(true);
        ui->action_9->setEnabled(true);
        ui->action_15->setEnabled(true);

        mModel->setTable("图书信息");
        mModel->select();
        ui->tableView->setModel(mModel);
    }
    if(usertype == 1){
        ui->action_2->setEnabled(true);
        ui->action_3->setEnabled(true);
        ui->action_4->setEnabled(true);
        ui->action_5->setEnabled(true);
        ui->action_6->setEnabled(true);
        ui->action_7->setEnabled(true);
        ui->action_8->setEnabled(true);
        ui->action_9->setEnabled(true);
        ui->action_10->setEnabled(true);
        ui->action_11->setEnabled(true);
        ui->action_12->setEnabled(true);
        ui->action_13->setEnabled(true);
        ui->action_14->setEnabled(true);
        ui->action_15->setEnabled(true);
        ui->action_16->setEnabled(true);

        mModel->setTable("图书信息");
        mModel->select();
        ui->tableView->setModel(mModel);
    }
}

void MainWindow::on_action_triggered()
{
   //hide();
   login = new SecDialog(this);
   login->show();
   connect(login,&SecDialog::SendUserType,this,&MainWindow::ReceiveUserType);
}

void MainWindow::on_action_5_triggered()
{
    //userexit = new UserExit(this);\
    //userexit->show();
    QMessageBox::StandardButton reply = QMessageBox::question(this,"确认退出","你确定要退出吗？",
                                                              QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes){
        QApplication::quit();
    }
}

void MainWindow::on_action_6_triggered()
{
    booksearch = new BookSearch;
    booksearch->show();
}

void MainWindow::on_action_7_triggered()
{
    booksearchbyauthor = new BookSearchByAuthor;
    booksearchbyauthor->show();
}

void MainWindow::on_action_9_triggered()
{
    if(usertype == 0){
        int count = 0;
        QString yonghuleixing;
        QSqlQuery qry;
        if(qry.exec("select * from UserInfoTable where 用户名='"+username+"'"))
        {
            while(qry.next()){
                count++;
            }
        }
        if(count = 1){
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
            QMessageBox::information(this,"用户信息查询成功",result);
        }
    }
    if(usertype == 1){
        userinfosearch = new UserInfoSearch;
        userinfosearch->show();
    }
}

void MainWindow::on_action_3_triggered()
{
    bookborrow = new BookBorrow;
    bookborrow->show();
    return;
}

void MainWindow::on_action_4_triggered()
{
    bookreturn = new BookReturn;
    bookreturn->show();
}

void MainWindow::on_action_10_triggered()
{
    userregister = new UserRegister;
    userregister->show();
}

void MainWindow::on_action_11_triggered()
{
    userdelete = new UserDelete;
    userdelete->show();
}

void MainWindow::on_action_13_triggered()
{
    bookadd = new BookAdd;
    bookadd->show();
}

void MainWindow::on_action_14_triggered()
{
    bookdelete = new BookDelete;
    bookdelete->show();
}

void MainWindow::ReceivePassword(QString a, QString b){
    oldpassword = a;
    newpassword = b;
    QString password;
    QSqlQuery qry;
    int count=0;
    if(qry.exec("select * from UserInfoTable where 用户名='"+username+"'"))
    {
        while(qry.next()){
            count++;
        }
    }
    if(count == 1){
        qry.first();
        password = qry.value(3).toString();
        if(password == oldpassword){
            qry.prepare("update UserInfoTable set 用户密码='"+newpassword+"' where 用户名='"+username+"'");
            if(qry.exec()){
                QMessageBox::information(this,"修改密码成功","修改密码成功");
            }
        }else{
            QMessageBox::warning(this,"修改密码失败","原密码错误，请重试");
        }
    }else{
        QMessageBox::warning(this,"数据库出错","数据库出错：数据库中没有找到你的账号信息");
    }

}

void MainWindow::on_action_15_triggered()
{
    passwordchange = new PasswordChange;
    passwordchange->show();
    connect(passwordchange,&PasswordChange::SendPassword,this,&MainWindow::ReceivePassword);

}

void MainWindow::on_action_16_triggered()
{
    changebookinfo = new ChangeBookInfo;
    changebookinfo->show();
}

void MainWindow::on_action_2_triggered()
{
    ui->action_2->setDisabled(true);
    ui->action_3->setDisabled(true);
    ui->action_4->setDisabled(true);
    ui->action_5->setDisabled(true);
    ui->action_6->setDisabled(true);
    ui->action_7->setDisabled(true);
    ui->action_8->setDisabled(true);
    ui->action_9->setDisabled(true);
    ui->action_10->setDisabled(true);
    ui->action_11->setDisabled(true);
    ui->action_12->setDisabled(true);
    ui->action_13->setDisabled(true);
    ui->action_14->setDisabled(true);
    ui->action_15->setDisabled(true);
    ui->action_16->setDisabled(true);
    QMessageBox::information(this,"成功退出","成功退出，如要进入图书馆请登录");
}

void MainWindow::on_action_8_triggered()
{
    mModel->setTable("图书信息");
    mModel->select();
    ui->tableView->setModel(mModel);
}

void MainWindow::on_action_12_triggered()
{
    mModel->setTable("UserInfoTable");
    mModel->select();
    ui->tableView->setModel(mModel);
}

void MainWindow::on_action_17_triggered()
{
    QMessageBox::about(this,"关于本系统","      本系统是基于微软ACCESS数据库建立的动态管理系统，\
                                         所有的操作完成后，都可以通过相应的查询选项显示更新后\
                                         的信息，无需重启系统。");
}

void MainWindow::on_action_18_triggered()
{
    QMessageBox::about(this,"关于设计者"," 本系统设计者：周晓瑞\n       所属单位：北京理工大学BFS实验室\nGitHub用户名：zxr445116086");
}
