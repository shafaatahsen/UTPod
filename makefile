final: UtPodDriver.o UtPod.o song.o
	g++ -otest  UtPodDriver.o UtPod.o song.o
driver: UtPodDriver.cpp UtPod.h song.h
	g++ UtPod_Driver.cpp
UtPod.o: UtPod.cpp UtPod.h song.h
	g++ tPod.cpp
song.o: song.cpp song.h
	g++ song.cpp