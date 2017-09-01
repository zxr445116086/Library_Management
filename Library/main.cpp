#include "mainwindow.h"
#include <QApplication>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QSqlTableModel>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>

#define ACCESS "DRIVER={Microsoft Access Driver (*.mdb)};"\
    "FIL={MS Access};DBQ=C:\\Users\\Jarvan\\Desktop\\Database2.mdb"





int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSqlDatabase mDatabase;

    mDatabase = QSqlDatabase::addDatabase("QODBC");
    mDatabase.setDatabaseName(ACCESS);

    if (!mDatabase.open()) {
        qDebug()<<"当前状态：未正常连接数据库";
    }
    else{
        qDebug()<<"当前状态：正常连接数据库";
    }
    MainWindow w;
    w.show();

    return a.exec();
}
