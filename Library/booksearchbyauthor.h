#ifndef BOOKSEARCHBYAUTHOR_H
#define BOOKSEARCHBYAUTHOR_H

#include <QDialog>

namespace Ui {
class BookSearchByAuthor;
}

class BookSearchByAuthor : public QDialog
{
    Q_OBJECT

public:
    explicit BookSearchByAuthor(QWidget *parent = 0);
    ~BookSearchByAuthor();

private slots:
    void on_pushButton_clicked();

private:
    Ui::BookSearchByAuthor *ui;
};

#endif // BOOKSEARCHBYAUTHOR_H
