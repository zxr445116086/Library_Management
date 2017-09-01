#ifndef BOOKRETURN_H
#define BOOKRETURN_H

#include <QDialog>

namespace Ui {
class BookReturn;
}

class BookReturn : public QDialog
{
    Q_OBJECT

public:
    explicit BookReturn(QWidget *parent = 0);
    ~BookReturn();

private slots:
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::BookReturn *ui;
};

#endif // BOOKRETURN_H
