all : Experimentation_approche_naive Experimentation_Programmation_dynamique Experimentation_Diviser_pour_mieux_regner Extension_alignement_local


Experimentation_approche_naive : Experimentation_approche_naive.o Tache_A.o outils.o structures.o fonctions_lecture_ecriture.o Manipulation_fichiers_genomes.o
	gcc -o Experimentation_approche_naive Experimentation_approche_naive.o Tache_A.o outils.o structures.o fonctions_lecture_ecriture.o Manipulation_fichiers_genomes.o

Experimentation_Programmation_dynamique : Experimentation_Programmation_dynamique.o Tache_B.o Tache_C.o outils.o structures.o fonctions_lecture_ecriture.o Manipulation_fichiers_genomes.o
	gcc -o Experimentation_Programmation_dynamique Experimentation_Programmation_dynamique.o Tache_B.o Tache_C.o outils.o structures.o fonctions_lecture_ecriture.o Manipulation_fichiers_genomes.o

Experimentation_Diviser_pour_mieux_regner : Experimentation_Diviser_pour_mieux_regner.o Tache_B.o Tache_C.o Tache_D.o outils.o structures.o fonctions_lecture_ecriture.o Manipulation_fichiers_genomes.o
	gcc -o Experimentation_Diviser_pour_mieux_regner Experimentation_Diviser_pour_mieux_regner.o Tache_B.o Tache_C.o Tache_D.o outils.o structures.o fonctions_lecture_ecriture.o Manipulation_fichiers_genomes.o


Extension_alignement_local : Extension_alignement_local.o Tache_C.o fonctions_lecture_ecriture.o structures.o outils.o
	gcc -o Extension_alignement_local Extension_alignement_local.o Tache_C.o fonctions_lecture_ecriture.o structures.o outils.o

Extension_alignement_local.o : Extension_alignement_local.c 	../Programmation_dynamique/Tache_C.h ../Fonctions_generales/fonctions_lecture_ecriture.o ../Fonctions_generales/structures.h ../Fonctions_generales/structures.o
	gcc -c Extension_alignement_local.c

Experimentation_Diviser_pour_mieux_regner.o : Experimentation_Programmation_dynamique.c ../Programmation_dynamique/Tache_B.h ../Programmation_dynamique/Tache_C.h ../Programmation_dynamique/Tache_D.h ../Fonctions_generales/fonctions_lecture_ecriture.h ../Fonctions_generales/outils.h ../Fonctions_generales/structures.h ../Outils_pour_experimentation/Manipulation_fichiers_genomes.h
	gcc -c Experimentation_Diviser_pour_mieux_regner.c


Experimentation_approche_naive.o : Experimentation_approche_naive.c ../Approche_naive/Tache_A.h ../Fonctions_generales/fonctions_lecture_ecriture.h ../Fonctions_generales/outils.h ../Fonctions_generales/structures.h ../Outils_pour_experimentation/Manipulation_fichiers_genomes.h
	gcc -c Experimentation_approche_naive.c

Experimentation_Programmation_dynamique.o :  Experimentation_Programmation_dynamique.c ../Programmation_dynamique/Tache_B.h ../Programmation_dynamique/Tache_C.h ../Fonctions_generales/fonctions_lecture_ecriture.h ../Fonctions_generales/outils.h ../Fonctions_generales/structures.h ../Outils_pour_experimentation/Manipulation_fichiers_genomes.h
	gcc -c Experimentation_Programmation_dynamique.c




#=====Autres répertoires=====
Tache_A.o : ../Approche_naive/Tache_A.c ../Approche_naive/Tache_A.h 
	gcc -c ../Approche_naive/Tache_A.c

Tache_B.o : ../Programmation_dynamique/Tache_B.c ../Programmation_dynamique/Tache_B.h
	gcc -c ../Programmation_dynamique/Tache_B.c 

Tache_C.o : ../Programmation_dynamique/Tache_C.c ../Programmation_dynamique/Tache_C.h
	gcc -c ../Programmation_dynamique/Tache_C.c 

Tache_D.o : ../Programmation_dynamique/Tache_D.c ../Programmation_dynamique/Tache_D.h
	gcc -c ../Programmation_dynamique/Tache_D.c 


fonctions_lecture_ecriture.o : ../Fonctions_generales/fonctions_lecture_ecriture.c ../Fonctions_generales/fonctions_lecture_ecriture.h
	gcc -c ../Fonctions_generales/fonctions_lecture_ecriture.c 

outils.o : ../Fonctions_generales/outils.c ../Fonctions_generales/outils.h
	gcc -c ../Fonctions_generales/outils.c

structures.o : ../Fonctions_generales/structures.c ../Fonctions_generales/structures.h
	gcc -c ../Fonctions_generales/structures.c

Manipulation_fichiers_genomes.o : ../Outils_pour_experimentation/Manipulation_fichiers_genomes.c ../Outils_pour_experimentation/Manipulation_fichiers_genomes.h  ../Fonctions_generales/structures.h
	gcc -c ../Outils_pour_experimentation/Manipulation_fichiers_genomes.c

#============================


clean : 
	rm -f *.o Experimentation_approche_naive Experimentation_Programmation_dynamique Experimentation_Diviser_pour_mieux_regner Extension_alignement_local

