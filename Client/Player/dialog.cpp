#include "dialog.h"
#include "ui_dialog.h"
#include "playlistcontroller.h"
#include <vector>
#include <unistd.h>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    player = new QMediaPlayer(this);
    PLCObject.SetSockets();
    connect(player, &QMediaPlayer::positionChanged, this, &Dialog::on_positionChanged);
    connect(player, &QMediaPlayer::durationChanged, this, &Dialog::on_durationChanged);
    connect(player,SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)),this,SLOT(mediaStatusChanged(QMediaPlayer::MediaStatus)));

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
    char cwd[1024];
       if (getcwd(cwd, sizeof(cwd)) != NULL){
           fprintf(stdout, "Current 2working dir: %s\n", cwd);}
    //Load the file

    QString applicationPath = QCoreApplication::applicationDirPath();

    player->setMedia(QUrl::fromLocalFile(applicationPath+"/queen.mp3"));
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
    if(ui->panel->count()){
        ui->playlist->addItem(ui->panel->currentItem()->text());
        //PLCObject.GetSong(ui->panel->currentItem()->text().toLatin1().data());
    }
}

void Dialog::mediaStatusChanged(QMediaPlayer::MediaStatus state)
{
    if(state==QMediaPlayer::EndOfMedia)
    {
       ui->panel->addItem("Termino cancion");
    }
}

void Dialog::on_Remove_clicked()
{
    if(ui->playlist->count()){
        PLCObject.RemoveSongFromPlaylist(ui->playlist->currentItem()->text().toUtf8().constData());
        ui->playlist->clear();
        for(std::string &s : PLCObject.queueplayList) {
            ui->playlist->addItem(s.c_str());
        }
    }
}

void Dialog::on_BtnRefresh_clicked()
{
    if(PLCObject.GetSongsList()>0){
        ui->panel->clear();
        for(std::string &s : PLCObject.songsList) {
            ui->panel->addItem(s.c_str());
        }
    }else{
        //ui->StatusLabel->setText("Error: Listing files failed");
    }
}
