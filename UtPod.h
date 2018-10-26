/* utPod_driver.h
Demo Driver for the UtPod.

Ahmad Shafaat Ahsen
EE 312 10/16/18

These are functions for the UtPod.

You will want to do more complete testing.

*/
#ifndef UTPOD_H
#define UTPOD_H
#include "Song.h"
#include <ctime>
#include <cstdlib>

//UtPod class declaration
class UtPod
{
   private:
      static const int MAX_MEMORY = 512;
      static const int SUCCESS = 0;
      static const int NO_MEMORY = -1;
      static const int NOT_FOUND = -2;

      struct SongNode
      {
         Song s;
         SongNode *next;
      };

      SongNode *songs;  //the head pointer

      int memSize;

      void swap(SongNode *s1, SongNode *s2);

      //returns pointer to SongNode with indexing starting from one
      //Precondition: index has to be a valid index, else NULL ptr is returned
      SongNode* getSongNodeAtIndex (int _index) const{
          SongNode* rVal = songs;
          int index = 0;
          while(index !=_index && rVal != NULL){
              index++;
              rVal = rVal->next;
          }
          return rVal;  //NULL or pointer to index
      }
      int getNumSongs() const;

   public:
      UtPod();
      UtPod(int size);

      int addSong(Song const &s);
      int removeSong(Song const &s);
      void shuffle();
      void showSongList() const;
      void sortSongList(){
          MergeSort(&songs);
      }
      void MergeSort(SongNode **headRef);
      void frontBackSplit(SongNode *src, SongNode **frontRef, SongNode **backRef);
      SongNode* sortedMerge(SongNode *a, SongNode *b);

      int getTotalMemory() const{
         return memSize;
      }

      int getRemainingMemory() const;

      ~UtPod();

};



#endif