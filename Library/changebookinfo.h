#ifndef CHANGEBOOKINFO_H
#define CHANGEBOOKINFO_H

#include <QDialog>

namespace Ui {
class ChangeBookInfo;
}

class ChangeBookInfo : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeBookInfo(QWidget *parent = 0);
    ~ChangeBookInfo();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ChangeBookInfo *ui;
};

#endif // CHANGEBOOKINFO_H
