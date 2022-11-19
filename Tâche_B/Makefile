all :  main

main : main.o Fonctions.o fonctions_lecture.o
	gcc -o main main.o Fonctions.o ../Tache_A/fonctions_lecture.o



Fonctions.o : Fonctions.c Fonctions.h fonctions_lecture.h
	gcc -c Fonctions.c
main.o : main.c Fonctions.h ../Tache_A/fonctions_lecture.h 
	gcc -c main.c


clean : 
	rm -f *.o main