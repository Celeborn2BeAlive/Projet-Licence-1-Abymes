#include <stdio.h>
#include <stdlib.h>

#include "initialisationsStructures.h"



/*FONCTION CHARGEANT LA CARTE*/


int** chargementCarte(char* f, int* nbre_lignes, int* nbre_colonnes, coordonnees* arrivee)
{
    int i, j; /*declaration des variables de boucles*/
    char caractere; /*declaration de la variable qui contiendra tour a tour chacun des caracteres du fichier*/

    int** carte = NULL; /*declaration du double pointeur qui contiendra la carte*/

    FILE* fichier = NULL; /*declaration d'un pointeur de type FILE*/

    fichier = fopen(f, "r"); /*on ouvre le fichier en lecture*/

    do /*on boucle...*/
    {
		caractere = fgetc(fichier); /*recuperation du caractere*/

        if((*nbre_lignes) == 0 && caractere != '\n') (*nbre_colonnes)++; /*si l'on est sur la premiere ligne, on augmente le nbre de colonnes*/

        if(caractere == '\n') (*nbre_lignes)++; /*pour chaque saut de ligne, on augmente le nombre de lignes*/

    }while(caractere != EOF); /*...tant que l'on arrive pas a la fin du fichier*/


    (*nbre_lignes)++; /*on augmente encore une fois le nombre de ligne pour la derniere qui n'a ps été prise en compte*/

	
    rewind(fichier); /*on se place au debut du fichier*/

	
    carte = malloc((*nbre_lignes)*sizeof(int)); /*allocation dynamique d'un tableau de nbre_lignes cases*/

    if(carte == NULL) exit(-1); /*si l'allocation a echoué, on quitte le programme*/



    for(i = 0; i < (*nbre_lignes); i++) /*on boucle sur le nombre de lignes*/
    {
		carte[i] = malloc((*nbre_colonnes)*sizeof(int)); /*pour chaque case du tableau, on alloue nbre_colonnes cases*/

		if(carte[i] == NULL) exit(1); /*si l'allocation a echoué, on quitte le programme*/

		for(j = 0; j < (*nbre_colonnes); j++) /*on boucle sur le nombre de colonne*/
		{
			carte[i][j] = fgetc(fichier); /*on remplit la case avec le caractere*/

			if(carte[i][j] == '!') /*si on est sur la case arrivée*/
			{
				/*on renvoie les coordonnées de l'arrivée*/
                arrivee->y = i;
                arrivee->x = j;
			}

			if(j == (*nbre_colonnes) - 1) /*si on arrive au derniere tout de boucle*/
				fseek(fichier, 1, SEEK_CUR); /*on fait avancer d'un le curseur pour eviter de charger le \n dans le tableau*/
		}
    }

    fclose(fichier); /*on ferme notre fichier*/

    return carte; /*on retourne le tableau contenant la carte*/
}


/*FONCTION TESTANT LA PRESENCE D'UN MUR A UNE CASE DONNEE*/


int absenceMur(int** carte, int i, int j)
{
    if(carte[i][j] == '*') 
		return 0;
    else
		return 1;
}
