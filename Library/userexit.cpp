#include "userexit.h"
#include "ui_userexit.h"

#include <QSqlQuery>

UserExit::UserExit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserExit)
{
    ui->setupUi(this);
}

UserExit::~UserExit()
{
    delete ui;
}
