#ifndef BOOKBORROW_H
#define BOOKBORROW_H

#include <QDialog>

namespace Ui {
class BookBorrow;
}

class BookBorrow : public QDialog
{
    Q_OBJECT

public:
    explicit BookBorrow(QWidget *parent = 0);
    ~BookBorrow();

private slots:
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::BookBorrow *ui;
};

#endif // BOOKBORROW_H
