#include <stdio.h>
#include <stdlib.h>

#include "structures.h"
#include "fonctions.h"


int main(int argc, char *argv[])
{

  mobile joueur;

  //CARTE :
  int nbre_lignes = 0, nbre_colonnes = 0;
  int** carte = NULL;

  //menuConsole(carte, &nbre_lignes, &nbre_colonnes, &joueur);

  menuGraphique(&joueur, carte, &nbre_lignes, &nbre_colonnes);

  //system("PAUSE");
  return 0;
}


