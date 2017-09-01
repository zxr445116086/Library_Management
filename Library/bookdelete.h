#ifndef BOOKDELETE_H
#define BOOKDELETE_H

#include <QDialog>


namespace Ui {
class BookDelete;
}

class BookDelete : public QDialog
{
    Q_OBJECT

public:
    explicit BookDelete(QWidget *parent = 0);
    ~BookDelete();

private slots:
    void on_pushButton_clicked();

private:
    Ui::BookDelete *ui;
};

#endif // BOOKDELETE_H
