#include "playlistcontroller.h"
#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMediaPlayer>
#include <QDebug>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    PlaylistController PLCObject;
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_sliderProgress_sliderMoved(int position);

    void on_sliderVolume_sliderMoved(int position);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_positionChanged(qint64 position);

    void on_durationChanged(qint64 position);

    void on_pushButton_3_clicked();

    void on_addPlaylist_clicked();

    void on_BtnAdd_clicked();

    void on_Remove_clicked();

    void mediaStatusChanged(QMediaPlayer::MediaStatus state);

    void on_BtnRefresh_clicked();

    void on_BtnShuffle_clicked();

    void on_BtnPause_clicked();

    void on_BtnNext_clicked();

    void on_BtnPrevious_clicked();

private:
    Ui::Dialog *ui;
    QMediaPlayer* player;
    void LoadSong();
    int seconds;
    int minutes;
    int hours;
    QTime* timeDuration;
};

#endif // DIALOG_H
