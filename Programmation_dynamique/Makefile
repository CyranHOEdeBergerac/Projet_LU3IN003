all :  main_Taches_B_C


main_Taches_B_C : main_Taches_B_C.o Tache_B.o Tache_C.o outils.o structures.o fonctions_lecture_ecriture.o
	gcc -o main_Taches_B_C main_Taches_B_C.o Tache_B.o Tache_C.o outils.o structures.o fonctions_lecture_ecriture.o


 main_Taches_B_C.o : main_Taches_B_C.c Tache_B.h Tache_C.h ../Fonctions_generales/outils.h ../Fonctions_generales/structures.h ../Fonctions_generales/fonctions_lecture_ecriture.h
	gcc -c main_Taches_B_C.c


 
 Tache_B.o : Tache_B.c Tache_B.h ../Fonctions_generales/outils.h ../Fonctions_generales/structures.h
	gcc -c Tache_B.c
 
 Tache_C.o : Tache_C.c Tache_C.h ../Fonctions_generales/outils.h
	gcc -c Tache_C.c
 
 
#=====Autres répertoires=====

fonctions_lecture_ecriture.o : ../Fonctions_generales/fonctions_lecture_ecriture.c ../Fonctions_generales/fonctions_lecture_ecriture.h
	gcc -c ../Fonctions_generales/fonctions_lecture_ecriture.c 

outils.o : ../Fonctions_generales/outils.c ../Fonctions_generales/outils.h
	gcc -c ../Fonctions_generales/outils.c

structures.o : ../Fonctions_generales/structures.c ../Fonctions_generales/structures.h
	gcc -c ../Fonctions_generales/structures.c

#============================



clean : 
	rm -f *.o main_Taches_B_C 