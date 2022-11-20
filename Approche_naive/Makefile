all :  main_Tache_A

main_Tache_A : main_Tache_A.o Tache_A.o fonctions_lecture_ecriture.o structures.o outils.o
	gcc -o main_Tache_A main_Tache_A.o Tache_A.o fonctions_lecture_ecriture.o structures.o outils.o



Tache_A.o : Tache_A.c Tache_A.h ../Fonctions_generales/outils.h
	gcc -c Tache_A.c

main_Tache_A.o : main_Tache_A.c Tache_A.h ../Fonctions_generales/fonctions_lecture_ecriture.h ../Fonctions_generales/structures.h ../Fonctions_generales/outils.h
	gcc -c main_Tache_A.c


#=====Autres répertoires=====

fonctions_lecture_ecriture.o : ../Fonctions_generales/fonctions_lecture_ecriture.c ../Fonctions_generales/fonctions_lecture_ecriture.h
	gcc -c ../Fonctions_generales/fonctions_lecture_ecriture.c 

outils.o : ../Fonctions_generales/outils.c ../Fonctions_generales/outils.h
	gcc -c ../Fonctions_generales/outils.c

structures.o : ../Fonctions_generales/structures.c ../Fonctions_generales/structures.h
	gcc -c ../Fonctions_generales/structures.c

#============================

clean : 
	rm -f *.o main_Tache_A