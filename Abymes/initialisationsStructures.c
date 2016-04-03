#include <stdio.h>
#include <stdlib.h>

#include "structures.h"


point initPoint(double x, double y) //initialise les coordonnées d'un point
{

 point p;

 p.coords[0] = x;
 p.coords[1] = y;

 return p;

}

mur initMur(point* p1, point* p2, point* p3, point* p4) //initialise les sommets d'un mur
{

 mur w;

 w.sommet[0] = p1;
 w.sommet[1] = p2;
 w.sommet[2] = p3;
 w.sommet[3] = p4;

 return w;

}

droiteaffine initDroiteAffine(double coefficient, point* o) //initialise le point d'origine et le coefficient directeur d'une droite affine
{

 droiteaffine d;

 d.origine = o;
 d.coefficient = coefficient;

 return d;

}













void afficherPoint(point p, int numero)
{
     printf("\ncoordonnees du point %d : %lf, %lf\n", numero, p.coords[0], p.coords[1]);
}



void afficherPoints(point* s)
{
     int i;

     for(i = 0; i < 32; i++)
     {
           afficherPoint(s[i], i);
     }

     printf("________________________________________________________________\n");
}


void afficherMursCharges(int murs_charges[][12])
{
     int i;


     for(i = 0; i < 12; i++)
      if(murs_charges[0][i])
	   printf("Le mur 0, %d est charge\n", i);

     printf("\n");

	 for(i = 0; i < 8; i++)
      if(murs_charges[1][i])
	   printf("Le mur 1, %d est charge\n", i);

     printf("\n");

	 for(i = 0; i < 4; i++)
      if(murs_charges[2][i])
	   printf("Le mur 2, %d est charge\n", i);

     printf("\n");

	 for(i = 0; i < 5; i++)
      if(murs_charges[3][i])
	   printf("Le mur 3, %d est charge\n", i);

     printf("\n");
}


void afficherCoeffs(double coeff[][32], double* coeff_o, double* coeff_f)
{
    int i, j, k;
    int points[8] = {0, 3, 4, 7, 24, 27, 28, 31};

    for(i = 0; i < 8; i++)
     printf("\ncoefficients du point %d : %lf, %lf\n", points[i], coeff[0][points[i]], coeff[1][points[i]]);


    points[0] = 24; points[1] = 27; points[2] = 28; points[3] = 31;

    for(k = 0; k < 4; k++)
     for(i = (points[k] - 8*2); i <= (points[k]-8); i += 8)
      printf("\ncoefficients du point %d : origine %lf, finale %lf\n", i, coeff_o[i], coeff_f[i]);


    points[0] = 3; points[1] = 27; points[2] = 31; points[3] = 7;

    for(k = 0; k < 4; k++)
     for(i = (points[k] - 2); i <= (points[k]-1); i += 1)
      printf("\ncoefficients du point %d : origine %lf, finale %lf\n", i, coeff_o[i], coeff_f[i]);


    points[0] = 11; points[1] = 19; points[2] = 23; points[3] = 15;

    for(k = 0; k < 4; k++)
     for(i = (points[k] - 2); i <= (points[k]-1); i += 1)
      printf("\ncoefficients du point %d : origine %lf, finale %lf\n", i, coeff_o[i], coeff_f[i]);
}
