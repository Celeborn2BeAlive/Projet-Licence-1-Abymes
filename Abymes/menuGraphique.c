#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//#include <MlvTypeC.h>
//#include <MlvProcC.h>

#include "structures.h"
#include "fonctions.h"

#define LONGUEUR 350
#define LARGEUR 200


void menuGraphique(mobile* joueur, int** carte, int* nbre_lignes, int* nbre_colonnes)
{
    int i, j, choix_menu, niveau;

    char deplacement;

    coordonnees arrivee;


    /*
    MlvType graphismes;

    create_window("Abymes", 750, 500, graphismes);

    draw_rectangle(350, 350, 50, 50, "black", graphismes);
    draw_rectangle(350, 425, 50, 50, "black", graphismes);
    draw_rectangle(275, 425, 50, 50, "black", graphismes);
    draw_rectangle(425, 425, 50, 50, "black", graphismes);
    */

    int perm_gauche[32] = {3,11,19,27,28,20,12,4,2,10,18,26,29,21,13,5,1,9,17,25,30,22,14,6,0,8,16,24,31,23,15,7};
    int perm_droite[32] = {24,16,8,0,7,15,23,31,25,17,9,1,6,14,22,30,26,18,10,2,5,13,21,29,27,19,11,3,4,12,20,28};
    int perm_avant[32] = {8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,24,25,26,27,28,29,30,31};
    int perm_arriere[32] = {0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23};

    point* perm;
    point permutation[32];


    point p[32]; //points de la scene
    point s[32]; //points sauvegarde de la scene
    point p_arriere[8]; //points à l'arriere de la scene

    initPoints(p);

    for(i = 0; i < 32; i++)
      for(j = 0; j <= 1; j++)
	   s[i].coords[j] = p[i].coords[j];

     for(i = 0; i <= 7; i++)
      for(j = 0; j <= 1; j++)
	   p_arriere[i].coords[j] = p[i].coords[j];

    mur* m[4];
     m[0] = malloc(12*sizeof(mur));
     m[1] = malloc(8*sizeof(mur));
     m[2] = malloc(4*sizeof(mur));
     m[3] = malloc(5*sizeof(mur));

    initMurs(p, p_arriere, m);

    int murs_charges[4][12] = {0};

    double coeff_o[32];
    double coeff_f[32];
    double coeff[2][32];

    point screen_right_top, screen_right_down, screen_left_down, screen_left_top;

    initEcran(&screen_right_top, &screen_right_down, &screen_left_down, &screen_left_top, p);

    printf("coordonnees de l'ecran :\n"
           "coin haut droit : %lf, %lf\n"
           "coin bas droit : %lf, %lf\n"
           "coin bas gauche : %lf, %lf\n"
           "coin haut gauche : %lf, %lf\n\n", screen_right_top.coords[0], screen_right_top.coords[1],
           screen_right_down.coords[0], screen_right_down.coords[1], screen_left_down.coords[0],
           screen_left_down.coords[1], screen_left_top.coords[0], screen_left_top.coords[1]);


    //AFFICHAGE MENU PRINCIPAL
    printf("Bienvenue dans Abyme, le labyrinthe des abymes, ceci est l'interface console,\n"
         "Veuillez faire votre choix : \n\n"
         "\t1. Nouvelle Partie\n"
         "\t2. Charger Partie\n"
         "\t3. Quitter\n");

    do
    {
     //mouse_wait
     scanf("%d", &choix_menu);
    }while(choix_menu != 1 && choix_menu != 2 && choix_menu != 3);

    if(choix_menu == 3) exit(0);
    else if(choix_menu == 1) niveau = '0';

    //REFRESH

    for(i = niveau; i <= '9'; i++)
    {
        char nom_fichier[] = "niveaux/niv0.txt";
        nom_fichier[11] = i;

        carte = chargementCarte(nom_fichier, nbre_lignes, nbre_colonnes, &arrivee);

        initialisationJoueur(joueur, carte, *nbre_lignes, *nbre_colonnes, i, 0);

        printf("\n\n## NIVEAU %c ##\n\n", i);

        while((joueur->coords.x != arrivee.x) || (joueur->coords.y != arrivee.y))
        {
         //AFFICHAGE GRAPHIQUE
         //wait_mouse
         afficherPoints(p);
         affichageConsole(carte, *joueur, *nbre_lignes, *nbre_colonnes);
         initGraphique(carte, joueur, nbre_lignes, nbre_colonnes, murs_charges, p, s);

         scanf(" %c", &deplacement);

         switch(deplacement) //if(position_souris)
          {
            case 'z' :
               deplacementJoueur(carte, joueur, 0, *nbre_lignes, *nbre_colonnes);

               perm = initPerm(perm_avant, p);
            break;
            case 's' :
               deplacementJoueur(carte, joueur, 1, *nbre_lignes, *nbre_colonnes);

               perm = initPerm(perm_arriere, p);
            break;
            case 'q' :
               deplacementJoueur(carte, joueur, 2, *nbre_lignes, *nbre_colonnes);

               perm = initPerm(perm_gauche, p);
            break;
            case 'd' :
               deplacementJoueur(carte, joueur, 3, *nbre_lignes, *nbre_colonnes);

               perm = initPerm(perm_droite, p);
            break;
          }


          for(j = 0; j < 32; j++)
           permutation[j] = perm[j];

          calculCoefficientsMouvement(permutation, p, coeff, coeff_o, coeff_f);

          deplacementPoints(p, 0, 20, 2, coeff, coeff_o, coeff_f);
        }

        int niveau_suivant = i+1;

        //REFRESH
        //MENU FIN

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

