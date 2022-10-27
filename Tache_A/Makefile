all :  main

main : main.o methode_naive.o fonctions_lecture.o
	gcc -o main main.o methode_naive.o fonctions_lecture.o

methode_naive.o : methode_naive.c methode_naive.h fonctions_lecture.h
	gcc -c methode_naive.c


fonctions_lecture.o : fonctions_lecture.c fonctions_lecture.h
	gcc -c fonctions_lecture.c 

main.o : main.c methode_naive.h fonctions_lecture.h 
	gcc -c main.c


clean : 
	rm -f *.o main