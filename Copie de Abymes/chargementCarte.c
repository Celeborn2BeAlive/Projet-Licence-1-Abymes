#include <stdio.h>
#include <stdlib.h>

#include "fonctions.h"

int** chargementCarte(char* f, int* nbre_lignes, int* nbre_colonnes)
{
    int i, j, k, l;
    char caractere;
    int** carte = NULL;
    FILE* fichier = NULL;
   
    fichier = fopen(f, "r");

    do
    {
        caractere = fgetc(fichier);

        if(*nbre_lignes == 0 && caractere != '\n') (*nbre_colonnes)++;

        if(caractere == '\n') (*nbre_lignes)++;

    }while(caractere != EOF);


    (*nbre_lignes)++;
    

    rewind(fichier);


    carte = malloc((*nbre_lignes)*sizeof(int));

    if(carte == NULL) exit;
    


    for(i = 0; i < *nbre_lignes; i++)
    {
     carte[i] = malloc((*nbre_colonnes)*sizeof(int));

     if(carte[i] == NULL) exit;

     for(j = 0; j < *nbre_colonnes; j++)
      {
        carte[i][j] = fgetc(fichier);
        

        if(j == *nbre_colonnes - 1) fseek(fichier, 2, SEEK_CUR);
      }
    }


    return carte;
}