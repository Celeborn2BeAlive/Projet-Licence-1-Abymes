#include <stdio.h>
#include <stdlib.h>

#include "fonctions.h"


void affichageConsole(int** c, int nbre_lignes, int nbre_colonnes)
{
     int i, j;
 
     for(i = 0; i < nbre_lignes; i ++)     //on parcour tout le tableau et affiche toute les cases
     {
           for(j = 0; j < nbre_colonnes; j ++)
                 printf("%c", c[i][j]);
           printf("\n");
     }
}