#include "graphic_structures.h"
#include "graphic_initialisation.h"


point initPoint(double x, double y) //initialise les coordonnées d'un point
{

 point p;
 
 p.coords[0] = x;
 p.coords[1] = y;
 
 return p;
 
}


wall initWall(point* p1, point* p2, point* p3, point* p4) //initialise les sommets d'un mur
{

 wall w;
 
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


void displayPoint(point p)
{
     printf("\ncoordonnees du point : %lf, %lf\n", p.coords[0], p.coords[1]);
}


void displayPoints(point* s)
{
     int i;
     
     for(i = 0; i < 32; i++)
     {
           displayPoint(s[i]);      
     }
}







