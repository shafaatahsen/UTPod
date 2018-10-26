//
// Created by Zanel on 10/23/2018.
//

#include "Song.h"
Song::Song(string _bandName, string _songTitle, int _fileSize){
    if(_bandName != "")
        bandName = _bandName;
    else{
        cout<<"band name not valid"<<endl;
        return;
    }
    if(_songTitle != "")
        songTitle = _songTitle;
    else{
        cout<<"song title not valid"<<endl;
        return;
    }
    if(_fileSize > 0)
        fileSize = _fileSize;
    else{
        cout<<"file size not valid"<<endl;
        return;

    }

}
Song::Song(){
    bandName = "";
    songTitle = "";
    fileSize = 0;
}


bool Song::operator ==(Song const &rhs){
    if(fileSize == rhs.fileSize && songTitle == rhs.songTitle && bandName == rhs.bandName)
        return true;
    return false;
}
bool Song::operator <(Song const &rhs){
    if(bandName<rhs.bandName)
        return true;
    else if(songTitle<rhs.songTitle)
        return true;
    else if(fileSize<rhs.fileSize)
        return true;

    return false;
}
bool Song::operator >(Song const &rhs){
    if(bandName>rhs.bandName)
        return true;
    else if(songTitle>rhs.songTitle)
        return true;
    else if(fileSize>rhs.fileSize)
        return true;

    return false;
}