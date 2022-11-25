all : tests_manipulation_fichiers

tests_manipulation_fichiers : tests_manipulation_fichiers.o Manipulation_fichiers_genomes.o structures.o 
	gcc -o tests_manipulation_fichiers tests_manipulation_fichiers.o Manipulation_fichiers_genomes.o structures.o

tests_manipulation_fichiers.o : tests_manipulation_fichiers.c Manipulation_fichiers_genomes.h ../Fonctions_generales/structures.h
	gcc -c tests_manipulation_fichiers.c

Manipulation_fichiers_genome.o : Manipulation_fichiers_genomes.c Manipulation_fichiers_genomes.h ../Fonctions_generales/structures.h
	gcc -c Manipulation_fichiers_genomes.c


#==========Autres dossiers==========
structures.o : ../Fonctions_generales/structures.c ../Fonctions_generales/structures.h
	gcc -c ../Fonctions_generales/structures.c
#===================================

clean : 
	rm -f *.o tests_manipulation_fichiers