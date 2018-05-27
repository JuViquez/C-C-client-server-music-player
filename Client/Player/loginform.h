#ifndef LOGINFORM_H
#define LOGINFORM_H
#include "playlistcontroller.h"
#include "dialog.h"

#include <QWidget>

namespace Ui {
class LoginForm;
}

class LoginForm : public QWidget
{
    Q_OBJECT
    PlaylistController *SocketObject;
public:
    explicit LoginForm(QWidget *parent = 0);
    ~LoginForm();

private slots:
    void on_BtnEnter_clicked();

private:
    Ui::LoginForm *ui;
    Dialog *DialogUI;
};

#endif // LOGINFORM_H
