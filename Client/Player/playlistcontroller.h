#include <netinet/in.h>
#include <iostream>
#include <string>
#include <vector>
#ifndef PLAYLISTCONTROLLER_H
#define PLAYLISTCONTROLLER_H

using namespace std;
class PlaylistController
{

public:
    PlaylistController();
    //Methods
    int Login(string UserName, string Password);
    int GetSongsList();
    int GetSong();
    void RemoveSongFromPlaylist(int songIndex);
    void AddSongToPlaylist(string songTitle);
    void ShufflePLaylist();
    void RemoveSongFile();
    int PlayNextSong();
    int PlayPreviousSong();
    //Control Variables
    string currentSong;
    int currentIndexSong;
    string currentImage;
    //Sockets attributes
    int sockfd = 0;
    char recvBuff[32768];
    struct sockaddr_in serv_addr;
    //QListWidget vector
    vector<string> queueplayList; //Playlist
    vector<string> songsList; //Panel
};

#endif // PLAYLISTCONTROLLER_H
