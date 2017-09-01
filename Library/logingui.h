#ifndef LOGINGUI_H
#define LOGINGUI_H

#include <QMainWindow>

namespace Ui {
class LoginGUI;
}

class LoginGUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginGUI(QWidget *parent = 0);
    ~LoginGUI();

private:
    Ui::LoginGUI *ui;
};

#endif // LOGINGUI_H
