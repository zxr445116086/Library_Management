#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include "secdialog.h"
#include "userexit.h"
#include "booksearch.h"
#include "booksearchbyauthor.h"
#include "userinfosearch.h"
#include "bookborrow.h"
#include "bookreturn.h"
#include "userregister.h"
#include "userdelete.h"
#include "bookadd.h"
#include "bookdelete.h"
#include "passwordchange.h"
#include "changebookinfo.h"
#include <QtSql>

namespace Ui {
class MainWindow;
}

class QSqlTableModel;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    friend class SecDialog;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int usertype;
    QString username;
    QString oldpassword;
    QString newpassword;

private slots:
    void on_action_triggered();

    void on_action_5_triggered();

    void on_action_6_triggered();

    void on_action_7_triggered();

    void on_action_9_triggered();

    void on_action_3_triggered();

    void on_action_4_triggered();

    void on_action_10_triggered();

    void on_action_11_triggered();

    void on_action_13_triggered();

    void on_action_14_triggered();

    void on_action_15_triggered();

    void on_action_16_triggered();

    void ReceiveUserType(int a, QString b);

    void ReceivePassword(QString a, QString b);

    void on_action_2_triggered();

    void on_action_8_triggered();

    void on_action_12_triggered();

    void on_action_17_triggered();

    void on_action_18_triggered();

private:
    Ui::MainWindow *ui;
    QSqlTableModel *mModel;
    SecDialog *login;
    UserExit *userexit;
    BookSearch *booksearch;
    BookSearchByAuthor *booksearchbyauthor;
    UserInfoSearch *userinfosearch;
    BookBorrow *bookborrow;
    BookReturn *bookreturn;
    UserRegister *userregister;
    UserDelete *userdelete;
    BookAdd *bookadd;
    BookDelete *bookdelete;
    PasswordChange *passwordchange;
    ChangeBookInfo *changebookinfo;
};
#endif // MAINWINDOW_H
