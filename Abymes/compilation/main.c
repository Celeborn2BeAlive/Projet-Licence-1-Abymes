#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <MlvTypeC.h>
#include <MlvProcC.h>


#include "initialisationsStructures.h"
#include "affichageGraphique.h"
#include "chargementCarte.h"
#include "console.h"
#include "fonctionsGraphiques.h"
#include "fonctionsJoueur.h"
#include "menuGraphique.h"



int main(int argc, char *argv[])
{

  mobile joueur;

  /*CARTE :*/
  int nbre_lignes = 0, nbre_colonnes = 0;
  int** carte = NULL;

  /*menuConsole(carte, &nbre_lignes, &nbre_colonnes, &joueur);*/

  menuGraphique(&joueur, carte, &nbre_lignes, &nbre_colonnes);


  return 0;
}


