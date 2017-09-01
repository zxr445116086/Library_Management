#ifndef USEREXIT_H
#define USEREXIT_H

#include <QDialog>

namespace Ui {
class UserExit;
}

class UserExit : public QDialog
{
    Q_OBJECT

public:
    explicit UserExit(QWidget *parent = 0);
    ~UserExit();

private:
    Ui::UserExit *ui;
};

#endif // USEREXIT_H
