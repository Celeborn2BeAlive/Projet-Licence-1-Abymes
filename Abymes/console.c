#include <stdio.h>
#include <stdlib.h>

#include "structures.h"
#include "fonctions.h"



void menuConsole(int** carte, int* nbre_lignes, int* nbre_colonnes, mobile* joueur)
{
  int choix_menu, i;
  int niveau;

  char deplacement;

  coordonnees arrivee;


  printf("Bienvenue dans Abyme, le labyrinthe des abymes, ceci est l'interface console,\n"
         "Veuillez faire votre choix : \n\n"
         "\t1. Nouvelle Partie\n"
         "\t2. Charger Partie\n"
         "\t3. Quitter\n");
  do
  {
   scanf("%d", &choix_menu);

  }while(choix_menu != 1 && choix_menu != 2 && choix_menu != 3);

  if(choix_menu == 3) exit(0);
  else if(choix_menu == 1) niveau = '0';



  for(i = niveau; i <= '9'; i++)
  {

        char nom_fichier[] = "niveaux/niv0.txt";
        nom_fichier[11] = i;


        carte = chargementCarte(nom_fichier, nbre_lignes, nbre_colonnes, &arrivee);

        initialisationJoueur(joueur, carte, *nbre_lignes, *nbre_colonnes, i, 0);

        printf("\n\n## NIVEAU %c ##\n\n", i);

        while((joueur->coords.x != arrivee.x) || (joueur->coords.y != arrivee.y))
        {
          //printf("coordonnees personnage : %d, %d\n", joueur.coords.x, joueur.coords.y);
          //printf("direction : %d\n\n", joueur.direction);

          affichageConsole(carte, *joueur, *nbre_lignes, *nbre_colonnes);

          scanf(" %c", &deplacement);

          switch(deplacement)
          {
            case 'z' :
               deplacementJoueur(carte, joueur, 0, *nbre_lignes, *nbre_colonnes);
            break;
            case 's' :
               deplacementJoueur(carte, joueur, 1, *nbre_lignes, *nbre_colonnes);
            break;
            case 'q' :
               deplacementJoueur(carte, joueur, 2, *nbre_lignes, *nbre_colonnes);
            break;
            case 'd' :
               deplacementJoueur(carte, joueur, 3, *nbre_lignes, *nbre_colonnes);
            break;
          }
        }

        int niveau_suivant = i+1;
        printf("\nFelicitation, vous avez trouve la sortie du labyrinthe !\n"
               "Pret a passer au niveau %c ?\n", niveau_suivant);
        printf("\t1.Passer au niveau suivant\n"
               "\t2.Sauvegarder la partie et continuer\n"
               "\t3.Sauvegarder la partie et quitter\n"
               "\t4.Quitter le jeu sans sauvegarder\n");

        do
               scanf("%d", &choix_menu);
        while(choix_menu != 1 && choix_menu != 2 && choix_menu != 3 && choix_menu != 4);

        if(choix_menu == 4) exit(0);


        free(carte);
        carte = NULL;
        *nbre_lignes = 0;
        *nbre_colonnes = 0;
  }
}



void affichageConsole(int** carte, mobile joueur, int nbre_lignes, int nbre_colonnes)
{
     int i, j;

     for(i = 0; i < nbre_lignes; i ++)     //on parcour tout le tableau et affiche toute les cases
     {
           for(j = 0; j < nbre_colonnes; j ++)
           {
                 if(i == joueur.coords.y && j == joueur.coords.x)
                  printf("%c", joueur.name[0]);
                 else
                  printf("%c", carte[i][j]);
           }
           printf("\n");
     }
}
