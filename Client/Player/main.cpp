#include "dialog.h"
#include "loginform.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginForm l;
    l.show();
    //w.show();

    return a.exec();
}
