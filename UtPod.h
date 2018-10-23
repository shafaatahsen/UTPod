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

   public:
      UtPod();
      UtPod(int size);

      int addSong(Song const &s);
      int removeSong(Song const &s);
      void shuffle();
      void showSongList();
      void sortSongList();

      int getTotalMemory() {
         return memSize;
      }

      int getRemainingMemory();

      ~UtPod();

};



#endif