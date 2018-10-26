//
// Created by Zanel on 10/23/2018.
//




#ifndef UTPOD_SONG_H
#define UTPOD_SONG_H

#include <string>
#include <iostream>
using namespace std;

//For each song we will store the title (string), artist (string),  and size (int) in MB
//Preconditions: the title and artist cannot be blank
//               the size must be greater than zero
class Song {
    private:
        string bandName;
        string songTitle;
        int fileSize;

    public:
        Song();
        Song(string _bandName, string _songTitle, int _fileSize);
        string getBand() const{
            return bandName;
        }
        string getSong() const{
            return songTitle;
        }
        int getFileSize() const{
            return fileSize;
        }

        bool operator >(Song const &rhs);
        bool operator ==(Song const &rhs);
        bool operator <(Song const &rhs);



};

#endif //UTPOD_SONG_H
