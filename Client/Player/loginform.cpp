#include "playlistcontroller.h"
#include "loginform.h"
#include "ui_loginform.h"

LoginForm::LoginForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginForm)
{
    ui->setupUi(this);
}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::on_BtnEnter_clicked()
{
    //SocketObject
    SocketObject = new PlaylistController();
    if(SocketObject->Login(ui->userBox->text().toLatin1().data(),ui->passwordBox->text().toLatin1().data())){
        ui->label_3->setText("Ingrese sus credenciales");
        DialogUI = new Dialog(this,SocketObject);
        DialogUI->exec();
    }else{
        ui->label_3->setText("ERROR: Datos invalidos");
    };

    //this->();
}
