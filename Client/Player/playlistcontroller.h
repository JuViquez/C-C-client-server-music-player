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
    void SetSockets();
    int GetSongsList();
    int GetSong();
    void RemoveSongFromPlaylist(string songTitle);
    void AddSongToPlaylist(string songTitle);
    string currentSong;
    int sockfd = 0;
    char recvBuff[1024];
    struct sockaddr_in serv_addr;
    vector<string> queueplayList;
    vector<string> songsList;
};

#endif // PLAYLISTCONTROLLER_H
