#include <stdio.h>
#include <stdlib.h>

#include "initialisationsStructures.h"


int** chargementCarte(char* f, int* nbre_lignes, int* nbre_colonnes, coordonnees* arrivee)
{
    int i, j;
    char caractere;

    int** carte = NULL;

    FILE* fichier = NULL;

    fichier = fopen(f, "r");

    do
    {
        caractere = fgetc(fichier);

        if((*nbre_lignes) == 0 && caractere != '\n') (*nbre_colonnes)++;

        if(caractere == '\n') (*nbre_lignes)++;

    }while(caractere != EOF);


    (*nbre_lignes)++;


    rewind(fichier);


    carte = malloc((*nbre_lignes)*sizeof(int));

    if(carte == NULL) exit(1);



    for(i = 0; i < (*nbre_lignes); i++)
    {
     carte[i] = malloc((*nbre_colonnes)*sizeof(int));

     if(carte[i] == NULL) exit(1);

     for(j = 0; j < (*nbre_colonnes); j++)
      {
        carte[i][j] = fgetc(fichier);

        if(carte[i][j] == '!')
        {
                       arrivee->y = i;
                       arrivee->x = j;
        }

        if(j == (*nbre_colonnes) - 1) fseek(fichier, 1, SEEK_CUR);
      }
    }

    fclose(fichier);

    return carte;
}


int absenceMur(int** carte, int i, int j)
{
    if(carte[i][j] == '*') return 0;
    else return 1;
}
