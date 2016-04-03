
all: exe

exe: main.c initialisationsStructures.o affichageGraphique.o chargementCarte.o console.o fonctionsGraphiques.o fonctionsJoueur.o menuGraphique.o
	./compi_c -o exe main.c initialisationsStructures.o affichageGraphique.o chargementCarte.o console.o fonctionsGraphiques.o fonctionsJoueur.o menuGraphique.o

initialisationsStructures.o: initialisationsStructures.c
	./compi_c -c initialisationsStructures.c

affichageGraphique.o: affichageGraphique.c
	./compi_c -c affichageGraphique.c

chargementCarte.o: chargementCarte.c
	./compi_c -c chargementCarte.c

console.o: console.c
	./compi_c -c console.c

fonctionsGraphiques.o: fonctionsGraphiques.c
	./compi_c -c fonctionsGraphiques.c

fonctionsJoueur.o.o: fonctionsJoueur.o.c
	./compi_c -c fonctionsJoueur.o.c

menuGraphique.o: menuGraphique.c
	./compi_c -c menuGraphique.c

