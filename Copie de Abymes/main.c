#include <stdio.h>
#include <stdlib.h>

#include "fonctions.h"


int main(int argc, char *argv[])
{
  int nbre_lignes = 0, nbre_colonnes = 0;
  int** carte;
  
  char fichier[] = "carte.txt";

  carte = chargementCarte(fichier, &nbre_lignes, &nbre_colonnes);

  affichageConsole(carte, nbre_lignes, nbre_colonnes);

  free(carte);
  
  
  system("PAUSE");	
  return 0;
}



