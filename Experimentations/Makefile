all : Experimentation_approche_naive 


Experimentation_approche_naive : Experimentation_approche_naive.o Tache_A.o outils.o structures.o fonctions_lecture_ecriture.o Manipulation_fichiers_genomes.o
	gcc -o Experimentation_approche_naive Experimentation_approche_naive.o Tache_A.o outils.o structures.o fonctions_lecture_ecriture.o Manipulation_fichiers_genomes.o


Experimentation_approche_naive.o : Experimentation_approche_naive.c ../Approche_naive/Tache_A.h ../Fonctions_generales/fonctions_lecture_ecriture.h ../Fonctions_generales/outils.h ../Fonctions_generales/structures.h ../Outils_pour_experimentation/Manipulation_fichiers_genomes.h
	gcc -c Experimentation_approche_naive.c


#=====Autres répertoires=====
Tache_A.o : ../Approche_naive/Tache_A.c ../Approche_naive/Tache_A.h 
	gcc -c ../Approche_naive/Tache_A.c

fonctions_lecture_ecriture.o : ../Fonctions_generales/fonctions_lecture_ecriture.c ../Fonctions_generales/fonctions_lecture_ecriture.h
	gcc -c ../Fonctions_generales/fonctions_lecture_ecriture.c 

outils.o : ../Fonctions_generales/outils.c ../Fonctions_generales/outils.h
	gcc -c ../Fonctions_generales/outils.c

structures.o : ../Fonctions_generales/structures.c ../Fonctions_generales/structures.h
	gcc -c ../Fonctions_generales/structures.c

Manipulation_fichiers_genomes.o : ../Outils_pour_experimentation/Manipulation_fichiers_genomes.c ../Outils_pour_experimentation/Manipulation_fichiers_genomes.h
	gcc -c ../Outils_pour_experimentation/Manipulation_fichiers_genomes.c

#============================


clean : 
	rm -f *.o Experimentation_approche_naive

