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

#define LONGUEUR 350
#define LARGEUR 200


/*FONCTION INITIALISANT UNE PERMUTATION DE POINT DONNE*/

point* initPerm(int* permutation, point* s)
{
	int i;

	static point new_perm[32]; /*declaration de la permutation*/

	for(i = 0; i < 32; i++) /*pour chacun des points de la scene*/
		new_perm[i] = initPoint(s[permutation[i]].coords[0], s[permutation[i]].coords[1]);
		/*on place son point permut� � sa position dans le tableau*/


	return new_perm; /*on retourne la permutation*/
}


/*FONCTION RENVOYANT LES COORDONNEES SUR L'ECRAN D'UN POINT*/


point getTrueCoords(point p)
{
	/*Nous avons utilis� une base differente de celle de l'ecran pour faciliter les calculs, cette fonction effectue le changement de base de notre*/
	/*repere vers l'ecran afin de pouvoir afficher la scene.*/

	point Oprim = initPoint(237.5, 350 - LARGEUR/3.33); /*Origine du repere utilis� lors des calculs, correspond au point s[0]*/

	point new_point; /*declaration du point sur l'ecran*/

	/*on change de base :*/
	new_point.coords[0] = p.coords[0]  + Oprim.coords[0];
	new_point.coords[1] = -p.coords[1] + Oprim.coords[1];

	return new_point;
}


/*FONCTION RENVOYANT  LA COORDONNEE X D'UN POINT, CALCULEE GRACE A UNE DROITE AFFINE*/


double obtenirCoordX(droiteaffine d, double y)
{

	double x;

	x = (y - ((d.coefficient*(-d.origine->coords[0]))+d.origine->coords[1]))/d.coefficient;

	return x;

}


/*FONCTION RENVOYANT  LA COORDONNEE Y D'UN POINT, CALCULEE GRACE A UNE DROITE AFFINE*/


double obtenirCoordY(droiteaffine d, double x)
{

 double y;

 y = d.coefficient*x + ((d.coefficient*(-d.origine->coords[0]))+d.origine->coords[1]);

 return y;

}


/*FONCTION INITIALISANT LA POSITION DE CHACUN DES POINTS DE LA SCENE*/
/*se referer au shema fourni avec le projet pour une vue d'ensemble de la scene et ainsi comprendre les calculs effectu�es*/


void initPoints(point* s)
{

    int i = 0;


	s[0] = initPoint(0,0);
    s[3] = initPoint(3*(LONGUEUR/2), 0);
    s[4] = initPoint(3*(LONGUEUR/2), 1.33*LARGEUR/3.33);
    s[7] = initPoint(0, 1.33*LARGEUR/3.33);


    s[24] = initPoint(-21*(LONGUEUR/4), -7*(LARGEUR/3.33));
    s[27] = initPoint(s[24].coords[0] + 12*LONGUEUR, s[24].coords[1]);
    s[31] = initPoint(s[24].coords[0], (1.33*(LARGEUR/3.33))+7*(LARGEUR/3.33));
    s[28] = initPoint(s[27].coords[0], s[31].coords[1]);



	while(i <= 24)
	{

		s[1+i].coords[0] = (2*s[i].coords[0]+s[i+3].coords[0])/3;
		s[1+i].coords[1] = (2*s[i].coords[1]+s[i+3].coords[1])/3;

		s[6+i].coords[0] = (2*s[i+7].coords[0]+s[i+4].coords[0])/3;
		s[6+i].coords[1] = (2*s[i+7].coords[1]+s[i+4].coords[1])/3;


		s[2+i].coords[0] = (s[i].coords[0]+2*s[i+3].coords[0])/3;
		s[2+i].coords[1] = (s[i].coords[1]+2*s[i+3].coords[1])/3;


		s[5+i].coords[0] = (s[i+7].coords[0]+2*s[i+4].coords[0])/3;
		s[5+i].coords[1] = (s[i+7].coords[1]+2*s[i+4].coords[1])/3;

		i += 24;
	}

	droiteaffine alpha = initDroiteAffine(s[24].coords[1]/s[24].coords[0], &s[0]);
	droiteaffine gama = initDroiteAffine(-s[24].coords[1]/s[24].coords[0], &s[7]);


	s[16].coords[0] = 3*(LONGUEUR/4)-3*LONGUEUR;
	s[16].coords[1] = obtenirCoordY(alpha, s[16].coords[0]);


	s[23].coords[0] = s[16].coords[0];
	s[23].coords[1] = obtenirCoordY(gama, s[16].coords[0]);


	s[8].coords[0] = -3*(LONGUEUR/4);
	s[8].coords[1] = obtenirCoordY(alpha, s[8].coords[0]);


	s[15].coords[0] = s[8].coords[0];
	s[15].coords[1] = obtenirCoordY(gama, s[8].coords[0]);



	s[19].coords[0] = s[16].coords[0] + 6*LONGUEUR;
	s[19].coords[1] = s[16].coords[1];


	s[20].coords[0] = s[23].coords[0] + 6*LONGUEUR;
	s[20].coords[1] = s[23].coords[1];


	s[11].coords[0] = s[8].coords[0] + 3*LONGUEUR;
	s[11].coords[1] = s[8].coords[1];


	s[12].coords[0] = s[15].coords[0] + 3*LONGUEUR;
	s[12].coords[1] = s[15].coords[1];


	droiteaffine epsilon = initDroiteAffine(-s[25].coords[1]/(s[1].coords[0]-s[25].coords[0]), &s[1]);

	s[9].coords[0] = s[8].coords[0] + LONGUEUR;
	s[9].coords[1] = s[8].coords[1];


	s[17].coords[0] = s[16].coords[0] + 2*LONGUEUR;
	s[17].coords[1] = obtenirCoordY(epsilon, s[17].coords[0]);


	droiteaffine teta = initDroiteAffine(s[25].coords[1]/(s[1].coords[0]-s[25].coords[0]), &s[6]);

	s[14].coords[0] = s[15].coords[0] + LONGUEUR;
	s[14].coords[1] = s[15].coords[1];


	s[22].coords[0] = s[23].coords[0] + 2*LONGUEUR;
	s[22].coords[1] = obtenirCoordY(teta, s[22].coords[0]);


	droiteaffine omega = initDroiteAffine(s[25].coords[1]/(s[1].coords[0]-s[25].coords[0]), &s[2]);

	s[10].coords[0] = s[8].coords[0] + 2*LONGUEUR;
	s[10].coords[1] = s[8].coords[1];


	s[18].coords[0] = s[16].coords[0] + 4*LONGUEUR;
	s[18].coords[1] = obtenirCoordY(omega, s[18].coords[0]);


	droiteaffine sigma = initDroiteAffine(-s[25].coords[1]/(s[1].coords[0]-s[25].coords[0]), &s[5]);

	s[13].coords[0] = s[15].coords[0] + 2*LONGUEUR;
	s[13].coords[1] = s[15].coords[1];


	s[21].coords[0] = s[23].coords[0] + 4*LONGUEUR;
	s[21].coords[1] = obtenirCoordY(sigma, s[21].coords[0]);

}


/*FONCTION INITIALISANT L'ENSEMBLE DES MURS DE LA SCENE*/


void initMurs(point* p, point* p_arriere, mur** m)
{
     m[0][0] = initMur(&p[0], &p[1], &p[6], &p[7]);
     m[0][1] = initMur(&p[1], &p[2], &p[5], &p[6]);
     m[0][2] = initMur(&p[2], &p[3], &p[4], &p[5]);
     m[0][3] = initMur(&p[11], &p[3], &p[4], &p[12]);
     m[0][4] = initMur(&p[19], &p[20], &p[12], &p[11]);
     m[0][5] = initMur(&p[27], &p[19], &p[20], &p[28]);
     m[0][6] = initMur(&p[26], &p[27], &p[28], &p[29]);
     m[0][7] = initMur(&p[25], &p[26], &p[29], &p[30]);
     m[0][8] = initMur(&p[24], &p[25], &p[30], &p[31]);
     m[0][9] = initMur(&p[24], &p[31], &p[23], &p[16]);
     m[0][10] = initMur(&p[16], &p[8], &p[15], &p[23]);
     m[0][11] = initMur(&p[8], &p[0], &p[7], &p[15]);

     m[1][0] = initMur(&p[9], &p[1], &p[6], &p[14]);
     m[1][1] = initMur(&p[8], &p[9], &p[14], &p[15]);
     m[1][2] = initMur(&p[16], &p[17], &p[22], &p[23]);
     m[1][3] = initMur(&p[25], &p[17], &p[22], &p[30]);
     m[1][4] = initMur(&p[26], &p[18], &p[21], &p[29]);
     m[1][5] = initMur(&p[18], &p[19], &p[20], &p[21]);
     m[1][6] = initMur(&p[10], &p[11], &p[12], &p[13]);
     m[1][7] = initMur(&p[10], &p[2], &p[5], &p[13]);

     m[2][0] = initMur(&p[9], &p[10], &p[13], &p[14]);
     m[2][1] = initMur(&p[17], &p[9], &p[14], &p[22]);
     m[2][2] = initMur(&p[17], &p[18], &p[21], &p[22]);
     m[2][3] = initMur(&p[18], &p[10], &p[13], &p[21]);

     m[3][0] = initMur(&p_arriere[0], &p_arriere[1], &p_arriere[6], &p_arriere[7]);
     m[3][1] = initMur(&p_arriere[1], &p_arriere[2], &p_arriere[5], &p_arriere[6]);
     m[3][2] = initMur(&p_arriere[2], &p_arriere[3], &p_arriere[4], &p_arriere[5]);
     m[3][3] = initMur(&p_arriere[1], &p[1], &p[6], &p_arriere[6]);
     m[3][4] = initMur(&p_arriere[2], &p[2], &p[5], &p_arriere[5]);
}


/*FONCTION PROVOQUANT LA REINITIALISATION GRAPHIQUE (POSITION DES POINTS ET CHARGEMENT DES MURS)*/


void initGraphique(int** carte, mobile* joueur, int* nbre_lignes, int* nbre_colonnes, int murs_charges[][12], point* p, point* s)
{
     int i, j;

     for(i = 0; i < 32; i++)
      p[i] = s[i];
      
     for(i = 0; i < 4; i++)
      for(j = 0; j < 12; j++)
       murs_charges[i][j] = 0;

     chargementMurs(*joueur, carte, *nbre_lignes, *nbre_colonnes, murs_charges);
}


/*FONCTION CHARGEANT LES MURS GRACE A UN TABLEAU A 2 DIMENSIONS DE BOOLEAN INDIQUANT SI UN MUR EST CHARGE OU PAS*/


void chargementMurs(mobile joueur, int** carte, int nbre_lignes, int nbre_colonnes, int murs_charges[][12])
{
	
	switch(joueur.direction)
	{

		case 0 : /*regarde en haut*/
		{

			if(joueur.coords.y - 3 >= 0)
			{
				if(joueur.coords.x - 1 >= 0)
					if(carte[joueur.coords.y - 3][joueur.coords.x - 1] == '*')  murs_charges[3][0] = 1;

				if(carte[joueur.coords.y - 3][joueur.coords.x] == '*')  murs_charges[3][1] = 1;

				if(joueur.coords.x + 1 < nbre_colonnes)
					if(carte[joueur.coords.y - 3][joueur.coords.x + 1] == '*') murs_charges[3][2] = 1;
			}
			if(joueur.coords.y - 2 >= 0)
			{
				if(joueur.coords.x - 1 >= 0)
					if(carte[joueur.coords.y - 2][joueur.coords.x - 1] == '*')  {murs_charges[0][0] = 1; murs_charges[3][3] = 1;}

				if(carte[joueur.coords.y - 2][joueur.coords.x] == '*')  murs_charges[0][1] = 1;

				if(joueur.coords.x + 1 < nbre_colonnes)
					if(carte[joueur.coords.y - 2][joueur.coords.x + 1] == '*')  {murs_charges[0][2] = 1; murs_charges[3][4] = 1;}
			}
			if(joueur.coords.y - 1 >= 0)
			{
				if(joueur.coords.x - 2 >= 0)
					if(carte[joueur.coords.y - 1][joueur.coords.x - 2] == '*')  murs_charges[0][11] = 1;

				if(joueur.coords.x - 1 >= 0)
					if(carte[joueur.coords.y - 1][joueur.coords.x - 1] == '*')  {murs_charges[1][0] = 1; murs_charges[1][1] = 1;}

				if(carte[joueur.coords.y - 1][joueur.coords.x] == '*') murs_charges[2][0] = 1;

				if(joueur.coords.x + 1 < nbre_colonnes)
					if(carte[joueur.coords.y - 1][joueur.coords.x + 1] == '*')  {murs_charges[1][7] = 1; murs_charges[1][6] = 1;}

				if(joueur.coords.x + 2 < nbre_colonnes)
					if(carte[joueur.coords.y - 1][joueur.coords.x + 2] == '*')  murs_charges[0][3] = 1;
			}

			if(joueur.coords.x - 2 >= 0)
				if(carte[joueur.coords.y][joueur.coords.x - 2] == '*') murs_charges[0][10] = 1;

			if(joueur.coords.x - 1 >= 0)
				if(carte[joueur.coords.y][joueur.coords.x - 1] == '*')  {murs_charges[2][1] = 1; murs_charges[1][2] = 1;}

			if(joueur.coords.x + 1 < nbre_colonnes)
				if(carte[joueur.coords.y][joueur.coords.x + 1] == '*')  {murs_charges[2][3] = 1; murs_charges[1][5] = 1;}

			if(joueur.coords.x + 2 < nbre_colonnes)
				if(carte[joueur.coords.y][joueur.coords.x + 2] == '*')  murs_charges[0][4] = 1;

			if(joueur.coords.y + 1 < nbre_lignes)
			{
				if(joueur.coords.x - 2 >= 0)
					if(carte[joueur.coords.y + 1][joueur.coords.x - 2] == '*') murs_charges[0][9] = 1;

				if(joueur.coords.x - 1 >= 0)
					if(carte[joueur.coords.y + 1][joueur.coords.x - 1] == '*')  {murs_charges[1][2] = 1; murs_charges[1][3] = 1;}

				if(carte[joueur.coords.y + 1][joueur.coords.x] == '*')  murs_charges[2][2] = 1;

				if(joueur.coords.x + 1 < nbre_colonnes)
					if(carte[joueur.coords.y + 1][joueur.coords.x + 1] == '*')  {murs_charges[1][4] = 1; murs_charges[1][5] = 1;}

				if(joueur.coords.x + 2 < nbre_colonnes)
					if(carte[joueur.coords.y + 1][joueur.coords.x + 2] == '*')  murs_charges[0][5] = 1;
			}
			if(joueur.coords.y + 2 < nbre_lignes)
			{
				if(joueur.coords.x - 1 >= 0)
					if(carte[joueur.coords.y + 2][joueur.coords.x - 1] == '*')  murs_charges[0][8] = 1;

				if(carte[joueur.coords.y + 2][joueur.coords.x] == '*')  murs_charges[0][7] = 1;

				if(joueur.coords.x + 1 < nbre_colonnes)
					if(carte[joueur.coords.y + 2][joueur.coords.x + 1] == '*')  murs_charges[0][6] = 1;
			}
		}
		break;

		case 1 : /*regarde � droite*/
		{
			if(joueur.coords.x + 3 < nbre_colonnes)
			{
				if(joueur.coords.y - 1 >= 0)
					if(carte[joueur.coords.y - 1][joueur.coords.x + 3] == '*')   murs_charges[3][0] = 1;

				if(carte[joueur.coords.y][joueur.coords.x + 3] == '*')   murs_charges[3][1] = 1;

				if(joueur.coords.y + 1 < nbre_lignes)
					if(carte[joueur.coords.y + 1][joueur.coords.x + 3] == '*')   murs_charges[3][2] = 1;
			}
			if(joueur.coords.x + 2 < nbre_colonnes)
			{
				if(joueur.coords.y - 1 >= 0)
					if(carte[joueur.coords.y - 1][joueur.coords.x + 2] == '*')   {murs_charges[0][0] = 1; murs_charges[3][3] = 1;}

				if(carte[joueur.coords.y][joueur.coords.x + 2] == '*')   murs_charges[0][1] = 1;

				if(joueur.coords.y + 1 < nbre_lignes)
					if(carte[joueur.coords.y + 1][joueur.coords.x + 2] == '*')   {murs_charges[0][2] = 1; murs_charges[3][4] = 1;}
			}
			if(joueur.coords.x + 1 < nbre_colonnes)
			{
				if(joueur.coords.y - 2 >= 0)
					if(carte[joueur.coords.y - 2][joueur.coords.x + 1] == '*')   murs_charges[0][11] = 1;

				if(joueur.coords.y - 1 >= 0)
					if(carte[joueur.coords.y - 1][joueur.coords.x + 1] == '*')   {murs_charges[1][0] = 1; murs_charges[1][1] = 1;}

				if(carte[joueur.coords.y][joueur.coords.x + 1] == '*')   murs_charges[2][0] = 1;

				if(joueur.coords.y + 1 < nbre_lignes)
					if(carte[joueur.coords.y + 1][joueur.coords.x + 1] == '*')   {murs_charges[1][7] = 1; murs_charges[1][6] = 1;}

				if(joueur.coords.y + 2 < nbre_lignes)
					if(carte[joueur.coords.y + 2][joueur.coords.x + 1] == '*')   murs_charges[0][3] = 1;
			}

			if(joueur.coords.y - 2 >= 0)
				if(carte[joueur.coords.y - 2][joueur.coords.x] == '*')   murs_charges[0][10] = 1;

			if(joueur.coords.y - 1 >= 0)
				if(carte[joueur.coords.y - 1][joueur.coords.x] == '*')   {murs_charges[2][1] = 1; murs_charges[1][2] = 1;}

			if(joueur.coords.y + 1 < nbre_lignes)
				if(carte[joueur.coords.y + 1][joueur.coords.x] == '*')   {murs_charges[2][3] = 1; murs_charges[1][5] = 1;}

			if(joueur.coords.y + 2 < nbre_lignes)
				if(carte[joueur.coords.y + 2][joueur.coords.x] == '*')   murs_charges[0][4] = 1;

			if(joueur.coords.x - 1 >= 0)
			{
				if(joueur.coords.y - 2 >= 0)
					if(carte[joueur.coords.y - 2][joueur.coords.x - 1] == '*')   murs_charges[0][9] = 1;

				if(joueur.coords.y - 1 >= 0)
					if(carte[joueur.coords.y - 1][joueur.coords.x - 1] == '*')   {murs_charges[1][2] = 1; murs_charges[1][3] = 1;}

				if(carte[joueur.coords.y][joueur.coords.x - 1] == '*')   murs_charges[2][2] = 1;

				if(joueur.coords.y + 1 < nbre_lignes)
					if(carte[joueur.coords.y + 1][joueur.coords.x - 1] == '*')   {murs_charges[1][4] = 1; murs_charges[1][5] = 1;}

				if(joueur.coords.y + 2 < nbre_lignes)
					if(carte[joueur.coords.y + 2][joueur.coords.x - 1] == '*')   murs_charges[0][5] = 1;
			}
			if(joueur.coords.x - 2 >= 0)
			{
				if(joueur.coords.y - 1 >= 0)
					if(carte[joueur.coords.y - 1][joueur.coords.x - 2] == '*')   murs_charges[0][8] = 1;

				if(carte[joueur.coords.y][joueur.coords.x - 2] == '*')   murs_charges[0][7] = 1;

				if(joueur.coords.y + 1 < nbre_lignes)
					if(carte[joueur.coords.y + 1][joueur.coords.x - 2] == '*')   murs_charges[0][6] = 1;
			}
		}
		break;

		case 2 : /* regarde en bas*/
		{
			if(joueur.coords.y + 3 < nbre_lignes)
			{
				if(joueur.coords.x + 1 < nbre_colonnes)
					if(carte[joueur.coords.y + 3][joueur.coords.x + 1] == '*')   murs_charges[3][0] = 1;

				if(carte[joueur.coords.y + 3][joueur.coords.x] == '*')   murs_charges[3][1] = 1;

				if(joueur.coords.x - 1 >= 0)
					if(carte[joueur.coords.y + 3][joueur.coords.x - 1] == '*')   murs_charges[3][2] = 1;
			}
			if(joueur.coords.y + 2 < nbre_lignes)
			{
				if(joueur.coords.x + 1 < nbre_colonnes)
					if(carte[joueur.coords.y + 2][joueur.coords.x + 1] == '*')   {murs_charges[0][0] = 1; murs_charges[3][3] = 1;}

				if(carte[joueur.coords.y + 2][joueur.coords.x] == '*')   murs_charges[0][1] = 1;

				if(joueur.coords.x - 1 >= 0)
					if(carte[joueur.coords.y + 2][joueur.coords.x - 1] == '*')   {murs_charges[0][2] = 1; murs_charges[3][4] = 1;}
			}
			if(joueur.coords.y + 1 < nbre_lignes)
			{
				if(joueur.coords.x + 2 < nbre_colonnes)
					if(carte[joueur.coords.y + 1][joueur.coords.x + 2] == '*')   murs_charges[0][11] = 1;

				if(joueur.coords.x + 1 < nbre_colonnes)
					if(carte[joueur.coords.y + 1][joueur.coords.x + 1] == '*')   {murs_charges[1][0] = 1; murs_charges[1][1] = 1;}

				if(carte[joueur.coords.y + 1][joueur.coords.x] == '*')   murs_charges[2][0] = 1;

				if(joueur.coords.x - 1 >= 0)
					if(carte[joueur.coords.y + 1][joueur.coords.x - 1] == '*')   {murs_charges[1][7] = 1; murs_charges[1][6] = 1;}

				if(joueur.coords.x - 2 >= 0)
					if(carte[joueur.coords.y + 1][joueur.coords.x - 2] == '*')   murs_charges[0][3] = 1;
			}

			if(joueur.coords.x + 2 < nbre_colonnes)
				if(carte[joueur.coords.y][joueur.coords.x + 2] == '*')   murs_charges[0][10] = 1;

			if(joueur.coords.x + 1 < nbre_colonnes)
				if(carte[joueur.coords.y][joueur.coords.x + 1] == '*')   {murs_charges[2][1] = 1; murs_charges[1][2] = 1;}

			if(joueur.coords.x - 1 >= 0)
				if(carte[joueur.coords.y][joueur.coords.x - 1] == '*')   {murs_charges[2][3] = 1; murs_charges[1][5] = 1;}

			if(joueur.coords.x - 2 >= 0)
				if(carte[joueur.coords.y][joueur.coords.x - 2] == '*')   murs_charges[0][4] = 1;

			if(joueur.coords.y - 1 >= 0)
			{
				if(joueur.coords.x + 2 < nbre_colonnes)
					if(carte[joueur.coords.y - 1][joueur.coords.x + 2] == '*')   murs_charges[0][9] = 1;

				if(joueur.coords.x + 1 < nbre_colonnes)
					if(carte[joueur.coords.y - 1][joueur.coords.x + 1] == '*')   {murs_charges[1][2] = 1; murs_charges[1][3] = 1;}

				if(carte[joueur.coords.y - 1][joueur.coords.x] == '*')   murs_charges[2][2] = 1;

				if(joueur.coords.x - 1 >= 0)
					if(carte[joueur.coords.y - 1][joueur.coords.x - 1] == '*')   {murs_charges[1][4] = 1; murs_charges[1][5] = 1;}

				if(joueur.coords.x - 2 >= 0)
					if(carte[joueur.coords.y - 1][joueur.coords.x - 2] == '*')   murs_charges[0][5] = 1;
			}
			if(joueur.coords.y - 2 >= 0)
			{
				if(joueur.coords.x + 1 < nbre_colonnes)
					if(carte[joueur.coords.y - 2][joueur.coords.x + 1] == '*')   murs_charges[0][8] = 1;

				if(carte[joueur.coords.y - 2][joueur.coords.x] == '*')   murs_charges[0][7] = 1;

				if(joueur.coords.x - 1 >= 0)
					if(carte[joueur.coords.y - 2][joueur.coords.x - 1] == '*')   murs_charges[0][6] = 1;
			}
		}
		break;

		case 3 : /* regarde a gauche*/
		{
			if(joueur.coords.x - 3 >= 0)
			{
				if(joueur.coords.y + 1 < nbre_lignes)
					if(carte[joueur.coords.y + 1][joueur.coords.x - 3] == '*')   murs_charges[3][0] = 1;

				if(carte[joueur.coords.y][joueur.coords.x - 3] == '*')   murs_charges[3][1] = 1;

				if(joueur.coords.y - 1 >= 0)
					if(carte[joueur.coords.y - 1][joueur.coords.x - 3] == '*')   murs_charges[3][2] = 1;
			}
			if(joueur.coords.x - 2 >= 0)
			{
				if(joueur.coords.y + 1 < nbre_lignes)
					if(carte[joueur.coords.y + 1][joueur.coords.x - 2] == '*')   {murs_charges[0][0] = 1; murs_charges[3][3] = 1;}

				if(carte[joueur.coords.y][joueur.coords.x - 2] == '*')   murs_charges[0][1] = 1;

				if(joueur.coords.y - 1 >= 0)
					if(carte[joueur.coords.y - 1][joueur.coords.x - 2] == '*')   {murs_charges[0][2] = 1; murs_charges[3][4] = 1;}
			}
			if(joueur.coords.x - 1 >= 0)
			{
				if(joueur.coords.y + 2 < nbre_lignes)
					if(carte[joueur.coords.y + 2][joueur.coords.x - 1] == '*')   murs_charges[0][11] = 1;

				if(joueur.coords.y + 1 < nbre_lignes)
					if(carte[joueur.coords.y + 1][joueur.coords.x - 1] == '*')   {murs_charges[1][0] = 1; murs_charges[1][1] = 1;}

				if(carte[joueur.coords.y][joueur.coords.x - 1] == '*')   murs_charges[2][0] = 1;

				if(joueur.coords.y - 1 >= 0)
					if(carte[joueur.coords.y - 1][joueur.coords.x - 1] == '*')   {murs_charges[1][7] = 1; murs_charges[1][6] = 1;}

				if(joueur.coords.y - 2 >= 0)
					if(carte[joueur.coords.y - 2][joueur.coords.x - 1] == '*')   murs_charges[0][3] = 1;
			}

			if(joueur.coords.y + 2 < nbre_lignes)
				if(carte[joueur.coords.y + 2][joueur.coords.x] == '*')   murs_charges[0][10] = 1;

			if(joueur.coords.y + 1 < nbre_lignes)
				if(carte[joueur.coords.y + 1][joueur.coords.x] == '*')   {murs_charges[2][1] = 1; murs_charges[1][2] = 1;}

			if(joueur.coords.y - 1 >= 0)
				if(carte[joueur.coords.y - 1][joueur.coords.x] == '*')   {murs_charges[2][3] = 1; murs_charges[1][5] = 1;}

			if(joueur.coords.y - 2 >= 0)
				if(carte[joueur.coords.y - 2][joueur.coords.x] == '*')   murs_charges[0][4] = 1;

			if(joueur.coords.x + 1 < nbre_colonnes)
			{
				if(joueur.coords.y + 2 < nbre_lignes)
					if(carte[joueur.coords.y + 2][joueur.coords.x + 1] == '*')   murs_charges[0][9] = 1;

				if(joueur.coords.y + 1 < nbre_lignes)
					if(carte[joueur.coords.y + 1][joueur.coords.x + 1] == '*')   {murs_charges[1][2] = 1; murs_charges[1][3] = 1;}

				if(carte[joueur.coords.y][joueur.coords.x + 1] == '*')   murs_charges[2][2] = 1;

				if(joueur.coords.y - 1 >= 0)
					if(carte[joueur.coords.y - 1][joueur.coords.x + 1] == '*')   {murs_charges[1][4] = 1; murs_charges[1][5] = 1;}

				if(joueur.coords.y - 2 >= 0)
					if(carte[joueur.coords.y - 2][joueur.coords.x + 1] == '*')   murs_charges[0][5] = 1;
			}
			if(joueur.coords.x + 2 < nbre_colonnes)
			{
				if(joueur.coords.y + 1 < nbre_lignes)
					if(carte[joueur.coords.y + 1][joueur.coords.x + 2] == '*')   murs_charges[0][8] = 1;

				if(carte[joueur.coords.y][joueur.coords.x + 2] == '*')   murs_charges[0][7] = 1;

				if(joueur.coords.y - 1 >= 0)
					if(carte[joueur.coords.y - 1][joueur.coords.x + 2] == '*')   murs_charges[0][6] = 1;
			}
		}
		break;

	}
}


/*FONCTION CALCULANT LES COEFFICIENTS DE MOUVEMENT DES POINTS A PARTIR DU PERMUTATION DONNEE*/


void calculCoefficientsMouvement(point* permutation, point* s, double coeff[][32], double* coeff_o, double* coeff_f)
{
	int i, j, k;



	 /*COINS DE LA SCENE GLOBALE*/
     /*
	  Pour calculer � tout moment la position d'un point dans la scene lors d'un mouvement, on commence par calculer la position des coins de la scene globale :
	  on recupere leur position originale, puis leur position apres deplacement (grace au tableau de permutations re�u en argument), on calcule la distance � parcourir en
	  soustrayant les coordonn�es de la position d'origine de chaque coin aux coordonn�es de la position d'arriv�e, puis en divisant le resultat
	  par le nombre d'etapes constituant le deplacement, on obtient un coefficient pour chaque coordonn�e de chaque point.
	  On ajoute alors ce coefficient aux coordonn�es du point � chaque etape de deplacement, ce qui permet de le faire se deplacer � sa position d'arriv�e (voir fonction move())
	  */

	 int points[8] = {0, 3, 4, 7, 24, 27, 28, 31}; /*ce tableau sert uniquement � reunir dans une boucle les operations qui suivent*/



	 for(j = 0; j < 8; j++) /*passe les valeurs du tableau qui correspondent aux numeros des points � traiter*/
	  for(i = 0; i <= 1; i++) /*boucle : 0 position sur l'axe x, 1 : position sur l'axe y*/
	   coeff[i][points[j]] = (permutation[points[j]].coords[i] - s[points[j]].coords[i])/20; /*on calcule le coefficient du point trait�*/


	 /*POINTS INTERNES DE LA SCENE GLOBALE*/
	 /*
	  Pour les autres points, l'application de la methode precedente entraine des decalages lors du deplacement, ce qui entraine des dedoublements de murs.
	  Il faut donc utiliser une autre methode, qui utilise la position des coins precedement trait� � tout moment du deplacement.
	  Nous savons que les points internes de la scene globale sont tous situ�s sur une arrete, delimit� 2 coins de la scene.
	  Ainsi, si un point B est situ� sur une arrete AC, et que l'on prend A comme origine, il existe un coefficient k tel que k*B = C.
	  Nous allons donc effectuer ce proc�d� pour chaque point, d'abord determiner les extremit� de l'arrete contenant le point, puis ramener l'une des extremit� � l'origine,
	  et calculer le coefficient.
	  Deux coefficient vont etre nessecaire : celui � la position d'origine du point, et celui � la position d'arriv�e (en utilisant egalement les positions d'arriv�e des
	  extremit�s de l'arrete.
	  Ainsi, si k1 est le coefficient � l'origine, et k2 est celui � l'arriv�e, on sait qu'au cours du mouvement, k1 doit devenir k2, donc a chaque etape du mouvement, on doit avoir
	  pour le point C :  ||AC|| = (k1+((k2-k1)/nbre_detape_de_mouvement)*nbre_detape_deja_effectuee)*||AB||
	  en ayant bien sur prealablement effectu� de calcul de la position de B � l'etape en cours.
	  Ce qui suit sert donc a calculer (k2-k1)/nbre_detape_de_mouvement.
	  Grace � cette methode, il n'y a aucun decalage puisque chacun des points est forcement plac� sur une arrete.
	  */
	 point point_ref_prim, point_ref_ter, point_prim, point_ter;
	 double coeff_a;


	 points[0] = 24; points[1] = 27; points[2] = 28; points[3] = 31; /*ces points representent le point B dans l'exemple*/

     /*premiere boucle : points des arretes [s[0]s[24]], [s[3]s[27]], [s[7]s[31]], [s[4]s[28]]*/
     for(k = 0; k < 4; k++)
	 {
	  j = points[k]; /*on recupere le point de reference*/

	  /*on l'exprime par rapport � l'autre extremit� de l'arrete (point A dans l'exemple), d'abord � l'origine :*/
	  point_ref_prim = initPoint(s[j].coords[0] - s[j-(8*3)].coords[0], s[j].coords[1] - s[j-(8*3)].coords[1]);
	  /*puis � l'arriv�e*/
	  point_ref_ter = initPoint(permutation[j].coords[0] - permutation[j-(8*3)].coords[0], permutation[j].coords[1] - permutation[j-(8*3)].coords[1]);

	  for(i = (j - 8*2); i <= (j-8); i += 8) /*on boucle sur tous les points de l'arrete (2 points par arrete)*/
	  {
	   /*on exprime le point par rapport � l'autre extremit� de l'arrete, d'abord � l'origine :*/
	   point_prim = initPoint(s[i].coords[0] - s[j-(8*3)].coords[0], s[i].coords[1] - s[j-(8*3)].coords[1]);
	   /*puis � l'arriv�e*/
	   point_ter = initPoint(permutation[i].coords[0] - permutation[j-(8*3)].coords[0], permutation[i].coords[1] - permutation[j-(8*3)].coords[1]);

       /*afficherPoint(point_prim, i);*/
       /*afficherPoint(point_ter, i);*/

	   /*en decoule le coefficient � l'origine : norme de AC � l'origine/norme de AB � l'origine*/
	   coeff_o[i] = (sqrt(pow(point_prim.coords[0], 2) + pow(point_prim.coords[1], 2)))/(sqrt(pow(point_ref_prim.coords[0], 2) + pow(point_ref_prim.coords[1], 2)));

	   /*puis le coefficient � l'arriv�e*/
	   coeff_a = (sqrt(pow(point_ter.coords[0], 2) + pow(point_ter.coords[1], 2)))/(sqrt(pow(point_ref_ter.coords[0], 2) + pow(point_ref_ter.coords[1], 2)));

	   /*enfin, la variation de coefficient � chaque etapes*/
	   coeff_f[i] = (coeff_a - coeff_o[i])/20;
	  }
     }

     points[0] = 3; points[1] = 27; points[2] = 31; points[3] = 7;

	 /*seconde boucle : points des arretes [s[0]s[3]], [s[24]s[27]], [s[4]s[7]], [s[28]s[ 31]]*/
     for(k = 0; k < 4; k++)
	 {
	  j = points[k];

	  point_ref_prim = initPoint(s[j].coords[0] - s[j-3].coords[0], s[j].coords[1] - s[j-3].coords[1]);
	  point_ref_ter = initPoint(permutation[j].coords[0] - permutation[j-3].coords[0], permutation[j].coords[1] - permutation[j-3].coords[1]);

	  for(i = (j - 2); i <= (j-1); i += 1)
	  {
	   point_prim = initPoint(s[i].coords[0] - s[j-3].coords[0], s[i].coords[1] - s[j-3].coords[1]);
	   point_ter = initPoint(permutation[i].coords[0] - permutation[j-3].coords[0], permutation[i].coords[1] - permutation[j-3].coords[1]);

	   coeff_o[i] = (sqrt(pow(point_prim.coords[0], 2) + pow(point_prim.coords[1], 2)))/(sqrt(pow(point_ref_prim.coords[0], 2) + pow(point_ref_prim.coords[1], 2)));

	   coeff_a = (sqrt(pow(point_ter.coords[0], 2) + pow(point_ter.coords[1], 2)))/(sqrt(pow(point_ref_ter.coords[0], 2) + pow(point_ref_ter.coords[1], 2)));

	   coeff_f[i] = (coeff_a - coeff_o[i])/20;
	  }
     }


	 points[0] = 11; points[1] = 19; points[2] = 23; points[3] = 15;

	 /*troisieme boucle : points des arretes [s[8]s[11]], [s[16]s[19]], [s[20]s[23]], [s[12]s[ 15]]*/
	 for(k = 0; k < 4; k++)
	 {
	  j = points[k];

	  point_ref_prim = initPoint(s[j].coords[0] - s[j-3].coords[0], s[j].coords[1] - s[j-3].coords[1]);
	  point_ref_ter = initPoint(permutation[j].coords[0] - permutation[j-3].coords[0], permutation[j].coords[1] - permutation[j-3].coords[1]);

	  for(i = (j - 2); i <= (j-1); i += 1)
	  {
	   point_prim = initPoint(s[i].coords[0] - s[j-3].coords[0], s[i].coords[1] - s[j-3].coords[1]);
	   point_ter = initPoint(permutation[i].coords[0] - permutation[j-3].coords[0], permutation[i].coords[1] - permutation[j-3].coords[1]);

	   coeff_o[i] = (sqrt(pow(point_prim.coords[0], 2) + pow(point_prim.coords[1], 2)))/(sqrt(pow(point_ref_prim.coords[0], 2) + pow(point_ref_prim.coords[1], 2)));

	   coeff_a = (sqrt(pow(point_ter.coords[0], 2) + pow(point_ter.coords[1], 2)))/(sqrt(pow(point_ref_ter.coords[0], 2) + pow(point_ref_ter.coords[1], 2)));

	   coeff_f[i] = (coeff_a - coeff_o[i])/20;
	  }
    }

}


/*FONCTION DEPLACANT LES POINTS A PARTIR DE LEURS COEFFICIENTS*/


void deplacementPoints(point* s, int etape_deplacement, double coeff[][32], double* coeff_o, double* coeff_f)
{

	int i, j, k, l;


	int points[8] = {0, 3, 4, 7, 24, 27, 28, 31};

	for(j = 0; j < 8; j++)
		for(i = 0; i <= 1; i++)
			s[points[j]].coords[i] = s[points[j]].coords[i] + coeff[i][points[j]];



	points[0] = 24; points[1] = 27; points[2] = 28; points[3] = 31;

    for(k = 0; k < 4; k++)
	{
		j = points[k];

		for(i = (j - 8*2); i <= (j-8); i += 8)
			for(l = 0; l <= 1; l++)
				s[i].coords[l] = (s[j].coords[l] - s[(j - 8*3)].coords[l])*(coeff_o[i] + coeff_f[i]*etape_deplacement) + s[(j - 8*3)].coords[l];
    }

	points[0] = 3; points[1] = 27; points[2] = 31; points[3] = 7;

    for(k = 0; k < 4; k++)
	{
		j = points[k];

		for(i = (j - 2); i <= (j-1); i += 1)
			for(l = 0; l <= 1; l++)
				s[i].coords[l] = (s[j].coords[l] - s[(j - 3)].coords[l])*(coeff_o[i] + coeff_f[i]*etape_deplacement) + s[(j - 3)].coords[l];
	}

	points[0] = 11; points[1] = 19; points[2] = 23; points[3] = 15;

	for(k = 0; k < 4; k++)
	{
		j = points[k];

		for(i = (j - 2); i <= (j-1); i += 1)
			for(l = 0; l <= 1; l++)
				s[i].coords[l] = (s[j].coords[l] - s[(j - 3)].coords[l])*(coeff_o[i] + coeff_f[i]*etape_deplacement) + s[(j - 3)].coords[l];
    }

}


/*FONCTION  INITIALISANT LES COORDONNEES DES COINS DU CADRE DE VISION DU JOUEUR*/


void initEcran(point* screen_right_top, point* screen_right_down, point* screen_left_down, point* screen_left_top, point* s)
{

    droiteaffine epsilon = initDroiteAffine(-s[25].coords[1]/(s[1].coords[0]-s[25].coords[0]), &s[1]);
    droiteaffine teta = initDroiteAffine(s[25].coords[1]/(s[1].coords[0]-s[25].coords[0]), &s[6]);


    screen_left_down->coords[0] = (LONGUEUR/4)-30;
	screen_left_down->coords[1] = obtenirCoordY(epsilon, (LONGUEUR/4)-30);

	screen_left_top->coords[0] = (LONGUEUR/4)-30;
	screen_left_top->coords[1] = obtenirCoordY(teta, (LONGUEUR/4)-30);

	screen_right_down->coords[0] = LONGUEUR+(LONGUEUR/4)+30;
	screen_right_down->coords[1] = screen_left_down->coords[1];

	screen_right_top->coords[0] = LONGUEUR+(LONGUEUR/4)+30;
	screen_right_top->coords[1] = screen_left_top->coords[1];

}
