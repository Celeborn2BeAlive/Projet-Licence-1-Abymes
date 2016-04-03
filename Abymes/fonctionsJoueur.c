#include <stdio.h>
#include <stdlib.h>

#include "structures.h"
#include "fonctions.h"

void initialisationJoueur(mobile* joueur, int** carte, int nbre_lignes, int nbre_colonnes, int niveau, int direction)
{
       int i, j;

       for(i = 0; i < nbre_lignes; i++)
       {
             for(j = 0; j < nbre_colonnes; j++)
             {
                   if(carte[i][j] == '#')
                   {
                     joueur->coords.y = i;
                     joueur->coords.x = j;
                     break;
                   }
             }
       }

       if(niveau == '0')
       {
        printf("Veuillez entrez le pseudo de votre personnage : ");
        scanf("%s", &joueur->name);
       }

       joueur->direction = direction;

}



void deplacementJoueur(int** carte, mobile* joueur, int type_deplacement, int nbre_lignes, int nbre_colonnes)
{
     switch(type_deplacement)
     {
       case 0 : //en haut
            switch(joueur->direction)
            {
              case 0 ://regarde en haut
               if(absenceMur(carte, (joueur->coords.y) - 1, joueur->coords.x) && (joueur->coords.y) != 0)
                (joueur->coords.y)--;
              break;
              case 1 ://regarde � droite
               if(absenceMur(carte, joueur->coords.y, (joueur->coords.x) + 1) && (joueur->coords.x) != (nbre_colonnes - 1))
                (joueur->coords.x)++;
              break;
              case 2 ://regarde en bas
               if(absenceMur(carte, (joueur->coords.y) + 1, joueur->coords.x) && (joueur->coords.y) != (nbre_lignes - 1))
                (joueur->coords.y)++;
              break;
              case 3 ://regarde � gauche
               if(absenceMur(carte, joueur->coords.y, (joueur->coords.x) - 1) && (joueur->coords.x) != 0)
                (joueur->coords.x)--;
              break;
            }
       break;


       case 1 : //en bas
            switch(joueur->direction)
            {
              case 0 ://regarde en haut
               if(absenceMur(carte, (joueur->coords.y) + 1, joueur->coords.x) && (joueur->coords.y) != (nbre_lignes - 1))
                (joueur->coords.y)++;
              break;
              case 1 ://regarde � droite
               if(absenceMur(carte, joueur->coords.y, (joueur->coords.x) - 1) && (joueur->coords.x) != 0)
                (joueur->coords.x)--;
              break;
              case 2 ://regarde en bas
               if(absenceMur(carte, (joueur->coords.y) - 1, joueur->coords.x) && (joueur->coords.y) != 0)
                (joueur->coords.y)--;
              break;
              case 3 ://regarde � gauche
               if(absenceMur(carte, joueur->coords.y, (joueur->coords.x) + 1) && (joueur->coords.x) != (nbre_colonnes - 1))
                (joueur->coords.x)++;
              break;
            }
       break;


       case 2 : //tourne � gauche
            switch(joueur->direction)
            {
              case 0 ://regarde en haut
               joueur->direction = 3;
              break;
              case 1 ://regarde � droite
               joueur->direction = 0;
              break;
              case 2 ://regarde en bas
               joueur->direction = 1;
              break;
              case 3 ://regarde � gauche
               joueur->direction = 2;
              break;
            }
       break;


       case 3 : //tourne � droite
            switch(joueur->direction)
            {
              case 0 ://regarde en haut
               joueur->direction = 1;
              break;
              case 1 ://regarde � droite
               joueur->direction = 2;
              break;
              case 2 ://regarde en bas
               joueur->direction = 3;
              break;
              case 3 ://regarde � gauche
               joueur->direction = 0;
              break;
            }
       break;
     }
}
