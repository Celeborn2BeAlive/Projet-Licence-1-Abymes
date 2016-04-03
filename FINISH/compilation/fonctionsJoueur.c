#include <stdio.h>
#include <stdlib.h>

#include "initialisationsStructures.h"
#include "chargementCarte.h"

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
        scanf("%19s", joueur->name);
       }

       joueur->direction = direction;

}



int deplacementJoueur(int** carte, mobile* joueur, int type_deplacement, int nbre_lignes, int nbre_colonnes)
{
     switch(type_deplacement)
     {
       case 0 : /*en haut*/
            switch(joueur->direction)
            {
              case 0 :/*regarde en haut*/
               if(absenceMur(carte, (joueur->coords.y) - 1, joueur->coords.x) && (joueur->coords.y) != 0)
                { (joueur->coords.y)--; return 1;}
               else
                return 0;
              break;
              case 1 :/*regarde à droite*/
               if(absenceMur(carte, joueur->coords.y, (joueur->coords.x) + 1) && (joueur->coords.x) != (nbre_colonnes - 1))
                {(joueur->coords.x)++; return 1;}
               else
                return 0;
              break;
              case 2 :/*regarde en bas*/
               if(absenceMur(carte, (joueur->coords.y) + 1, joueur->coords.x) && (joueur->coords.y) != (nbre_lignes - 1))
                {(joueur->coords.y)++; return 1;}
               else
                return 0;
              break;
              case 3 :/*regarde à gauche*/
               if(absenceMur(carte, joueur->coords.y, (joueur->coords.x) - 1) && (joueur->coords.x) != 0)
                {(joueur->coords.x)--; return 1;}
               else
                return 0;
              break;
            }
       break;


       case 1 : /*en bas*/
            switch(joueur->direction)
            {
              case 0 :/*regarde en haut*/
               if(absenceMur(carte, (joueur->coords.y) + 1, joueur->coords.x) && (joueur->coords.y) != (nbre_lignes - 1))
                {(joueur->coords.y)++; return 1;}
               else
                return 0;
              break;
              case 1 :/*regarde à droite*/
               if(absenceMur(carte, joueur->coords.y, (joueur->coords.x) - 1) && (joueur->coords.x) != 0)
                {(joueur->coords.x)--; return 1;}
               else
                return 0;
              break;
              case 2 :/*regarde en bas*/
               if(absenceMur(carte, (joueur->coords.y) - 1, joueur->coords.x) && (joueur->coords.y) != 0)
                {(joueur->coords.y)--; return 1;}
               else
                return 0;
              break;
              case 3 :/*regarde à gauche*/
               if(absenceMur(carte, joueur->coords.y, (joueur->coords.x) + 1) && (joueur->coords.x) != (nbre_colonnes - 1))
                {(joueur->coords.x)++; return 1;}
               else
                return 0;
              break;
            }
       break;


       case 2 : /*tourne à gauche*/
            switch(joueur->direction)
            {
              case 0 :/*regarde en haut*/
               joueur->direction = 3;
              break;
              case 1 :/*regarde à droite*/
               joueur->direction = 0;
              break;
              case 2 :/*regarde en bas*/
               joueur->direction = 1;
              break;
              case 3 :/*regarde à gauche*/
               joueur->direction = 2;
              break;
            }
       break;


       case 3 : /*tourne à droite*/
            switch(joueur->direction)
            {
              case 0 :/*regarde en haut*/
               joueur->direction = 1;
              break;
              case 1 :/*regarde à droite*/
               joueur->direction = 2;
              break;
              case 2 :/*regarde en bas*/
               joueur->direction = 3;
              break;
              case 3 :/*regarde à gauche*/
               joueur->direction = 0;
              break;
            }
       break;
     }
}




void sauvegarde(int niveau, mobile* joueur)
{
	char nom_fichier[81];
 	FILE* fichier_sauvegarde;
 	
 	printf("Entrez le nom du fichier de sauvegarde\n");
 	
 	scanf("%80s", nom_fichier);
 	
 	fichier_sauvegarde = fopen(nom_fichier, "wb");
 	
 	fwrite(&niveau, sizeof(int), 1, fichier_sauvegarde);
   fwrite(joueur->name, sizeof(joueur->name), 1, fichier_sauvegarde);

   fclose(fichier_sauvegarde);
}

int chargement(int* niveau, mobile* joueur)
{
	char nom_fichier[81];
 	FILE* fichier_sauvegarde;
 	
 	printf("Entrez le nom du fichier a charger\n");

	scanf("%80s", nom_fichier);
	
 	
 	fichier_sauvegarde = fopen(nom_fichier, "rb");
 	
 	if(fichier_sauvegarde == NULL)
 	{
 		printf("Le fichier n'existe pas\n");
 		return 0;
 	}
 	else
 	{
 		fread(niveau, sizeof(int), 1, fichier_sauvegarde);
 		fread(joueur->name, sizeof(joueur->name), 1, fichier_sauvegarde);
 		fclose(fichier_sauvegarde);
 		return 1;
 	}

}
