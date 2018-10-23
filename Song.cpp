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

string Song::getBand() const{
    return bandName;
}

string Song::getSong() const{
    return songTitle;
}

int Song::getFileSize() const{
    return fileSize;
}