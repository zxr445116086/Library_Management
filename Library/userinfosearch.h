#ifndef USERINFOSEARCH_H
#define USERINFOSEARCH_H

#include <QDialog>

namespace Ui {
class UserInfoSearch;
}

class UserInfoSearch : public QDialog
{
    Q_OBJECT

public:
    explicit UserInfoSearch(QWidget *parent = 0);
    ~UserInfoSearch();

private slots:
    void on_pushButton_clicked();

private:
    Ui::UserInfoSearch *ui;
};

#endif // USERINFOSEARCH_H
