#include "dialog.h"
#include "ui_dialog.h"
#include "playlistcontroller.h"
#include <vector>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);
    PLCObject.SetSockets();
    connect(player, &QMediaPlayer::positionChanged, this, &Dialog::on_positionChanged);
    connect(player, &QMediaPlayer::durationChanged, this, &Dialog::on_durationChanged);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_sliderProgress_sliderMoved(int position)
{
    player->setPosition(position);
}

void Dialog::on_sliderVolume_sliderMoved(int position)
{
    player->setVolume(position);
}

void Dialog::on_pushButton_clicked()
{
    //Load the file
    printf("Empieza a reproducirse");
    player->setMedia(QUrl::fromLocalFile("/home/jose/Documentos/Qt-129-ffa29ce767bc6928dec2e7f3b197ab52951b8a6d/MyPlayer/queen.mp3"));
    player->play();
    qDebug() << player->errorString();
}

void Dialog::on_pushButton_2_clicked()
{
    player->stop();
}

void Dialog::on_positionChanged(qint64 position)
{
    ui->sliderProgress->setValue(position);
}

void Dialog::on_durationChanged(qint64 position)
{
    ui->sliderProgress->setMaximum(position);
}

void Dialog::on_BtnAdd_clicked()
{
    if(PLCObject.GetSongsList()>0){
        for(std::string &s : PLCObject.queueplayList) {
            ui->panel->addItem(s.c_str());
        }
    }else{
        ui->panel->addItem("ERROR");
    }
}
