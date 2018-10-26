//
// Created by Zanel on 10/22/2018.
//

#include "UtPod.h"
UtPod::UtPod(){
    songs = NULL;
    memSize = 0;
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
    temp->s = s;

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
        memSize -= s.getFileSize();
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
            return SUCCESS;
        }

    }
}

void UtPod::shuffle(){
    unsigned int currentTime =  (unsigned)time(nullptr);

    srand(currentTime);  //seed the random number generator
    SongNode *curNode = songs;

    int numSongs = getNumSongs();
    while(curNode != NULL){
        //cout<<rand()<<endl; test if numbers are different each time
        int randIndex = rand()%numSongs;
        SongNode *temp = getSongNodeAtIndex(randIndex);
        swap(curNode, temp);
        curNode = curNode->next;
    }
}

void UtPod::showSongList() const{
    SongNode* head = songs;

    while(head != NULL){
        cout<<head->s.getSong()<<" by "<<head->s.getBand()<<endl;
        head = head->next;
    }

}

int UtPod::getNumSongs() const{
    int numSongs = 0;
    SongNode* head = songs;
    while(head !=NULL){
        numSongs++;
        head = head->next;
    }

    return numSongs;
}

void UtPod::swap(SongNode *s1, SongNode *s2){
    Song temp = s1->s;
    s1->s = s2->s;
    s2->s =temp;

}



//void UtPod::sortSongList(){}

int UtPod::getRemainingMemory() const{
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

void UtPod::MergeSort(SongNode **headRef){
    SongNode *head = *headRef;
    SongNode *a;
    SongNode *b;

    if((head ==NULL)|| (head->next == NULL))
        return;

    //split into two lists
    frontBackSplit(head, &a, &b);

    //recursively sort sublists
    MergeSort(&a);
    MergeSort(&b);

    //Merge two sorted lists together, and adjust the headpointer
    *headRef = sortedMerge(a,b);

}

void UtPod::frontBackSplit(SongNode *src, SongNode **frontRef, SongNode **backRef){
    SongNode *fast;
    SongNode *slow;

    slow = src;
    fast = src;

    //advance fast twice as fast as slow
    while(fast->next != NULL){
        fast = fast->next;
        if(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    *frontRef = src;
    *backRef = slow->next;
    slow->next = NULL;
}

UtPod::SongNode* UtPod::sortedMerge(SongNode *a, SongNode *b){
    SongNode* result = NULL;
    if(a == NULL)
        return b;
    if(b == NULL)
        return a;
    if(a->s < b->s){
        result = a;
        result->next = sortedMerge(a->next,b);
    }
    else{
        result = b;
        result->next = sortedMerge(b->next, a);
    }
    return result;
}