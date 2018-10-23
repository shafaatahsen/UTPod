//
// Created by Zanel on 10/22/2018.
//

#include "UtPod.h"
UtPod::UtPod(){
    songs = NULL;
    memSize = NO_MEMORY;
}
UtPod::UtPod(int size){
    songs = NULL;
    if(size>512)
        memSize = MAX_MEMORY;
    else
        memSize = size;
}

int UtPod::addSong(Song const &s){
    //check if there's enough memory to add song, add if so
    int newSize = memSize + s.getFileSize();
    if(newSize>512){
        cout<<"Not enough memory, can't add song"<<endl;
        return NO_MEMORY;
    }
    else{
        memSize = newSize;
    }


    SongNode *temp = new SongNode;
    temp->s = Song(s.getBand(),s.getSong(), s.getFileSize());

    //Add at head
    if(songs == NULL){
        songs = temp;
        temp->next = NULL;

    }
    else{
        temp->next = songs;
        songs = temp;
    }


    return SUCCESS;
}
int UtPod::removeSong(Song const &s){
    if(songs->s.getSong() == s.getSong() && songs->s.getFileSize() == s.getFileSize() && songs->s.getBand() == s.getBand()){
        SongNode *temp = songs;
        songs = songs->next;
        delete(temp);
        return SUCCESS;
    }

    SongNode *leader = songs;
    SongNode *chaser;
    while(leader != NULL){
        chaser= leader;
        leader = leader->next;
        if(leader->s.getSong() == s.getSong() && leader->s.getFileSize() == s.getFileSize() && leader->s.getBand() == s.getBand()){
            chaser->next = leader->next;
            memSize -= s.getFileSize();
            delete(leader);
        }

    }
}

void UtPod::shuffle(){}

void UtPod::showSongList(){
    SongNode* head = songs;

    while(head != NULL){
        cout<<head->s.getSong()<<" by "<<head->s.getBand()<<endl;
        head = head->next;
    }

}



void UtPod::sortSongList(){}

int UtPod::getRemainingMemory(){
    return (512-memSize);
}

UtPod::~UtPod(){
    SongNode* head = songs;
    SongNode* trail = songs;
    while(trail != NULL){
        head = head->next;
        delete(trail);
        trail = head;
    }
}