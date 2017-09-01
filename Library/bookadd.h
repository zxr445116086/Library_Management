#ifndef BOOKADD_H
#define BOOKADD_H

#include <QDialog>


namespace Ui {
class BookAdd;
}

class BookAdd : public QDialog
{
    Q_OBJECT

public:
    explicit BookAdd(QWidget *parent = 0);
    ~BookAdd();

private slots:
    void on_pushButton_clicked();

private:
    Ui::BookAdd *ui;
};

#endif // BOOKADD_H
