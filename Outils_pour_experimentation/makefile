all : tests_manipulation_fichiers

tests_manipulation_fichiers : tests_manipulation_fichiers.o Manipulation_fichiers_genomes.o 
	gcc -o tests_manipulation_fichiers tests_manipulation_fichiers.o Manipulation_fichiers_genomes.o

tests_manipulation_fichiers.o : tests_manipulation_fichiers.c Manipulation_fichiers_genomes.h
	gcc -c tests_manipulation_fichiers.c

Manipulation_fichiers_genome.o : Manipulation_fichiers_genomes.c Manipulation_fichiers_genomes.h
	gcc -c Manipulation_fichiers_genomes.c

clean : 
	rm -f *.o tests_manipulation_fichiers