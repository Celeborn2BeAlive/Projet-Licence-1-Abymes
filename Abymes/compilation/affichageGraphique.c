#include <stdio.h>
#include <stdlib.h>


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


void tracerLigne(point point1, point point2, char* color, MlvType* graphismes)
{
 point p1 = getTrueCoords(point1);
 point p2 = getTrueCoords(point2);

 draw_line(p1.coords[0], p1.coords[1], p2.coords[0], p2.coords[1], color, graphismes);
}


void tracerMur(mur m, char* color, MlvType* graphismes)
{
 point* pp1 = m.sommet[0];
 point* pp2 = m.sommet[1];
 point* pp3 = m.sommet[2];
 point* pp4 = m.sommet[3];


 point p1 = getTrueCoords(*pp1);
 point p2 = getTrueCoords(*pp2);
 point p3 = getTrueCoords(*pp3);
 point p4 = getTrueCoords(*pp4);

 XPoint points[4] = { {p1.coords[0],p1.coords[1]}, {p2.coords[0],p2.coords[1]}, {p3.coords[0],p3.coords[1]}, {p4.coords[0],p4.coords[1]} };

 draw_filled_polygone(points, 4, "white", graphismes);
 tracerLigne(*pp1, *pp2, "black", graphismes);
 tracerLigne(*pp2, *pp3, "black", graphismes);
 tracerLigne(*pp3, *pp4, "black", graphismes);
 tracerLigne(*pp4, *pp1, "black", graphismes);
 
 
 
}


void tracerBlockMurs(int numero, int murs_charges[][12], mur** m, MlvType* graphismes)
{
	 switch(numero)
	 {
	  case 0 :
	   if(murs_charges[0][1]) tracerMur(m[0][1], "white", graphismes);
       if(murs_charges[2][0]) tracerMur(m[2][0], "white", graphismes);
	  break;

	  case 1 :
	   if(murs_charges[0][0]) tracerMur(m[0][0], "white", graphismes);
	   if(murs_charges[0][11]) tracerMur(m[0][11], "white", graphismes);
	   if(murs_charges[1][0]) tracerMur(m[1][0], "white", graphismes);
	   if(murs_charges[1][1]) tracerMur(m[1][1], "white", graphismes);
	  break;

	  case 2 :
	   if(murs_charges[0][2]) tracerMur(m[0][2], "white", graphismes);
	   if(murs_charges[0][3]) tracerMur(m[0][3], "white", graphismes);
	   if(murs_charges[1][7]) tracerMur(m[1][7], "white", graphismes);
	   if(murs_charges[1][6]) tracerMur(m[1][6], "white", graphismes);
	  break;

	  case 3 :
	   if(murs_charges[0][10]) tracerMur(m[0][10], "white", graphismes);
	   if(murs_charges[2][1]) tracerMur(m[2][1], "white", graphismes);
	  break;

	  case 4 :
	   if(murs_charges[0][4]) tracerMur(m[0][4], "white", graphismes);
	   if(murs_charges[2][3]) tracerMur(m[2][3], "white", graphismes);
	  break;

	  case 5 :
	   if(murs_charges[0][9]) tracerMur(m[0][9], "white", graphismes);
	   if(murs_charges[0][8]) tracerMur(m[0][8], "white", graphismes);
	   if(murs_charges[1][2]) tracerMur(m[1][2], "white", graphismes);
	   if(murs_charges[1][3]) tracerMur(m[1][3], "white", graphismes);
	  break;

	  case 6 :
	   if(murs_charges[0][7]) tracerMur(m[0][7], "white", graphismes);
	   if(murs_charges[2][2]) tracerMur(m[2][2], "white", graphismes);
	  break;

	  case 7 :
	   if(murs_charges[0][5]) tracerMur(m[0][5], "white", graphismes);
	   if(murs_charges[0][6]) tracerMur(m[0][6], "white", graphismes);
	   if(murs_charges[1][5]) tracerMur(m[1][5], "white", graphismes);
	   if(murs_charges[1][4]) tracerMur(m[1][4], "white", graphismes);
	  break;


	 }
}


void tracerScene(int etape_deplacement, int type_mouvement, int mur_charges[][12], mur** m, MlvType* graphismes)
{
	 rafraichirEcran(graphismes);


	 /*mur nuit;*/

	 /*tracerMur(nuit, "black", graphismes);*/


	 switch(type_mouvement)
	 {

	 case -1 : /*immobile*/
		tracerBlockMurs(1, mur_charges, m, graphismes);
		tracerBlockMurs(2, mur_charges, m, graphismes);
		tracerBlockMurs(0, mur_charges, m, graphismes);
		tracerBlockMurs(3, mur_charges, m, graphismes);
		tracerBlockMurs(4, mur_charges, m, graphismes);
	 break;
	 case 0 : /*avance*/
		if(etape_deplacement >= 20)
		{
			if(mur_charges[3][0]) tracerMur(m[3][0], "white", graphismes);
			if(mur_charges[3][1]) tracerMur(m[3][1], "white", graphismes);
			if(mur_charges[3][2]) tracerMur(m[3][2], "white", graphismes);
		}
		if(mur_charges[3][3]) tracerMur(m[3][3], "white", graphismes);
		if(mur_charges[3][4]) tracerMur(m[3][4], "white", graphismes);
		tracerBlockMurs(1, mur_charges, m, graphismes);
		tracerBlockMurs(2, mur_charges, m, graphismes);
		tracerBlockMurs(0, mur_charges, m, graphismes);
		tracerBlockMurs(3, mur_charges, m, graphismes);
		tracerBlockMurs(4, mur_charges, m, graphismes);
	 break;
	 case 1 :/*recule*/
		tracerBlockMurs(1, mur_charges, m, graphismes);
		tracerBlockMurs(2, mur_charges, m, graphismes);
		if(mur_charges[2][0]) tracerMur(m[2][0], "white", graphismes);
		tracerBlockMurs(3, mur_charges, m, graphismes);
		tracerBlockMurs(4, mur_charges, m,  graphismes);
		if(mur_charges[1][2]) tracerMur(m[1][2], "white", graphismes);
		if(mur_charges[1][5]) tracerMur(m[1][5], "white", graphismes);
		tracerBlockMurs(5, mur_charges, m,  graphismes);
		tracerBlockMurs(7, mur_charges, m,  graphismes);
	 break;
	 case 2 : /*tourne à gauche*/
	    if(etape_deplacement < 2) tracerBlockMurs(2, mur_charges, m,  graphismes);
		tracerBlockMurs(1, mur_charges, m,  graphismes);
		if(etape_deplacement >= 19) tracerBlockMurs(5, mur_charges, m,  graphismes);
		tracerBlockMurs(0, mur_charges, m,  graphismes);
		tracerBlockMurs(3, mur_charges, m,  graphismes);
		if(etape_deplacement >= 20) tracerBlockMurs(6, mur_charges, m,  graphismes);
	 break;
	 case 3 : /*tourne à droite*/
	    if(etape_deplacement < 2) tracerBlockMurs(1, mur_charges, m,  graphismes);
		tracerBlockMurs(2, mur_charges, m,  graphismes);
		if(etape_deplacement >= 19) tracerBlockMurs(7, mur_charges, m,  graphismes);
		tracerBlockMurs(0, mur_charges, m,  graphismes);
		tracerBlockMurs(4, mur_charges, m,  graphismes);
		if(etape_deplacement >= 20) tracerBlockMurs(6, mur_charges, m,  graphismes);
	 break;
	}

   display_window(graphismes);
}


void tracerEcran(MlvType* graphismes, point screen_right_top, point screen_right_down, point screen_left_down, point screen_left_top)
{ 
    draw_rectangle(350, 350, 50, 50, "black", graphismes);
    draw_rectangle(350, 425, 50, 50, "black", graphismes);
    draw_rectangle(275, 425, 50, 50, "black", graphismes);
    draw_rectangle(425, 425, 50, 50, "black", graphismes);


    tracerLigne(screen_left_down, screen_left_top, "black", graphismes);
    tracerLigne(screen_left_top, screen_right_top, "black", graphismes);
    tracerLigne(screen_right_top, screen_right_down, "black", graphismes);
    tracerLigne(screen_right_down, screen_left_down, "black", graphismes);


    point ld = getTrueCoords(screen_left_down);
    point rd = getTrueCoords(screen_right_down);
    point lt = getTrueCoords(screen_left_top);
    point rt = getTrueCoords(screen_right_top);

    XPoint points[11] = { {0,0}, {750,0}, {750,500}, {0,500}, {0,lt.coords[1]}, {lt.coords[0],lt.coords[1]}, {ld.coords[0],ld.coords[1]}, {rd.coords[0],rd.coords[1]}, {rt.coords[0],rt.coords[1]}, {0,rt.coords[1]}, {0,0} };

    draw_filled_polygone(points, 11, "white", graphismes);
    
    display_window(graphismes);
}



void rafraichirEcran(MlvType* graphismes)
{
    draw_filled_rectangle(0, 0, 1000, 700, "white", graphismes);   
}


void tracerSquelette(point* s, MlvType* graphismes)
{

 tracerLigne(s[0], s[3], "black", graphismes);
 tracerLigne(s[3], s[27], "black", graphismes);
 tracerLigne(s[27], s[24], "black", graphismes);
 tracerLigne(s[24], s[0], "black", graphismes);
 
 tracerLigne(s[7], s[4], "black", graphismes);
 tracerLigne(s[4], s[28], "black", graphismes);
 tracerLigne(s[28], s[31], "black", graphismes);
 tracerLigne(s[31], s[7], "black", graphismes);

 
 tracerLigne(s[1], s[25], "black", graphismes);
 tracerLigne(s[2], s[26], "black", graphismes);
 tracerLigne(s[6], s[30], "black", graphismes);
 tracerLigne(s[5], s[29], "black", graphismes);
 
 tracerLigne(s[8], s[11], "black", graphismes);
 tracerLigne(s[16], s[19], "black", graphismes);
 tracerLigne(s[15], s[12], "black", graphismes);
 tracerLigne(s[23], s[20], "black", graphismes);
 
 
 tracerLigne(s[0], s[7], "black", graphismes);
 tracerLigne(s[1], s[6], "black", graphismes);
 tracerLigne(s[2], s[5], "black", graphismes);
 tracerLigne(s[3], s[4], "black", graphismes);
 
 tracerLigne(s[11], s[12], "black", graphismes);
 tracerLigne(s[19], s[20], "black", graphismes);
 tracerLigne(s[27], s[28], "black", graphismes);
 tracerLigne(s[26], s[29], "black", graphismes);
 tracerLigne(s[25], s[30], "black", graphismes);
 tracerLigne(s[24], s[31], "black", graphismes);
 tracerLigne(s[16], s[23], "black", graphismes);
 tracerLigne(s[8], s[15], "black", graphismes);
 
 
 tracerLigne(s[9], s[14], "black", graphismes);
 tracerLigne(s[10], s[13], "black", graphismes);
 tracerLigne(s[18], s[21], "black", graphismes);
 tracerLigne(s[17], s[22], "black", graphismes);
 
 display_window(graphismes);


}

