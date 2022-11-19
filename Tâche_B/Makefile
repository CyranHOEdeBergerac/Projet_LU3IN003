all :  main

main : main.o Fonctions.o fonctions_lecture.o methode_naive.o
	gcc -o main main.o Fonctions.o ../Tache_A/fonctions_lecture.o methode_naive.o



Fonctions.o : Fonctions.c Fonctions.h ../Tache_A/fonctions_lecture.h  ../Tache_A/methode_naive.h
	gcc -c Fonctions.c

main.o : main.c Fonctions.h ../Tache_A/fonctions_lecture.h ../Tache_A/methode_naive.h
	gcc -c main.c

fonctions_lecture.o : ../Tache_A/fonctions_lecture.c ../Tache_A/fonctions_lecture.h
	gcc -c ../Tache_A/fonctions_lecture.c 

methode_naive.o : ../Tache_A/methode_naive.c ../Tache_A/methode_naive.h ../Tache_A/fonctions_lecture.h
	gcc -c ../Tache_A/methode_naive.c



clean : 
	rm -f *.o main 