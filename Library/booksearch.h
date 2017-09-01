#ifndef BOOKSEARCH_H
#define BOOKSEARCH_H

#include <QDialog>

namespace Ui {
class BookSearch;
}

class BookSearch : public QDialog
{
    Q_OBJECT

public:
    explicit BookSearch(QWidget *parent = 0);
    ~BookSearch();

private slots:
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::BookSearch *ui;
};

#endif // BOOKSEARCH_H
