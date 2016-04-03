#include <stdio.h>
#include <stdlib.h>

/*
#include <MlvTypeC.h>
#include <MlvProcC.h>

#include "structures.h"
#include "fonctions.h"
#include "affichageGraphique.h"

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
 point p1 = getTrueCoords(wall.sommet[0]);
 point p2 = getTrueCoords(wall.sommet[1]);
 point p3 = getTrueCoords(wall.sommet[2]);
 point p4 = getTrueCoords(wall.sommet[3]);

 XPoint points[4] = { {p1.coords[0],p1.coords[1]}, {p2.coords[0],p2.coords[1]}, {p3.coords[0],p3.coords[1]}, {p4.coords[0],p4.coords[1]} };

 draw_filled_polygone(points, 4, color, graphismes);
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


void tracerScene(int type_mouvement, int murs_charges[][12], mur** m, MlvType* graphismes)
{
	 rafraichirEcran(graphismes);

	 var i, j;
	 //mur nuit;

	 //tracerMur(nuit, "black", graphismes);


	 switch(type_mouvement)
	 {

	 case -1 : //immobile
		tracerBlockMurs(1, mur_charges, graphismes);
		tracerBlockMurs(2, mur_charges, graphismes);
		tracerBlockMurs(0, mur_charges, graphismes);
		tracerBlockMurs(3, mur_charges, graphismes);
		tracerBlockMurs(4, mur_charges, graphismes);
	 break;
	 case 0 : //avance
		if(etape_deplacement >= 20)
		{
			if(murs_charges[3][0]) tracerMur(m[3][0], "white", graphismes);
			if(murs_charges[3][1]) tracerMur(m[3][1], "white", graphismes);
			if(murs_charges[3][2]) tracerMur(m[3][2], "white", graphismes);
		}
		if(murs_charges[3][3]) tracerMur(m[3][3], "white", graphismes);
		if(murs_charges[3][4]) tracerMur(m[3][4], "white", graphismes);
		tracerBlockMurs(1, mur_charges, graphismes);
		tracerBlockMurs(2, mur_charges, graphismes);
		tracerBlockMurs(0, mur_charges, graphismes);
		tracerBlockMurs(3, mur_charges, graphismes);
		tracerBlockMurs(4, mur_charges, graphismes);
	 break;
	 case 1 ://recule
		tracerBlockMurs(1, mur_charges, graphismes);
		tracerBlockMurs(2, mur_charges, graphismes);
		if(murs_charges[2][0]) tracerMur(m[2][0], "white", graphismes);
		tracerBlockMurs(3, mur_charges, graphismes);
		tracerBlockMurs(4, mur_charges, graphismes);
		if(murs_charges[1][2]) tracerMur(m[1][2], "white", graphismes);
		if(murs_charges[1][5]) tracerMur(m[1][5], "white", graphismes);
		tracerBlockMurs(5, mur_charges, graphismes);
		tracerBlockMurs(7, mur_charges, graphismes);
	 break;
	 case 2 : //tourne à gauche
		if(etape_deplacement < 2) tracerBlockMurs(2, mur_charges, graphismes);
		tracerBlockMurs(1, mur_charges, graphismes);
		if(etape_deplacement >= 19) tracerBlockMurs(5, mur_charges, graphismes);
		tracerBlockMurs(0, mur_charges, graphismes);
		tracerBlockMurs(3, mur_charges, graphismes);
		if(etape_deplacement >= 20) tracerBlockMurs(6, mur_charges, graphismes);
	 break;
	 case 3 : //tourne à droite
		if(etape_deplacement < 2) tracerBlockMurs(1, mur_charges, graphismes);
		tracerBlockMurs(2, mur_charges, graphismes);
		if(etape_deplacement >= 19) tracerBlockMurs(7, mur_charges, graphismes);
		tracerBlockMurs(0, mur_charges, graphismes);
		tracerBlockMurs(4, mur_charges, graphismes);
		if(etape_deplacement >= 20) tracerBlockMurs(6, mur_charges, graphismes);
	 break;

	 tracerEcran(graphismes);
}


void tracerEcran(point screen_right_top, point screen_right_down, point screen_left_down, point screen_left_top, MvlType* graphismes)
{
    tracerLigne(screen_left_down, screen_left_top, "black", graphismes);
    tracerLigne(screen_left_top, screen_right_top, "black", graphismes);
    tracerLigne(screen_right_top, screen_right_down, "black", graphismes);
    tracerLigne(screen_right_down, screen_left_down, "black", graphismes);


    point ld = getTrueCoords(screen_left_down);
    point rd = getTrueCoords(screen_right_down);
    point lt = getTrueCoords(screen_left_top);
    point rt = getTrueCoords(screen_right_top);

    XPoint points[11] = { {0,0}, {750,0}, {750,500}, {0,500}, {0,lt.coords[1]}, {lt.coords[0],lt.coords[1]}, {ld.coords[0],ld.coords[1]}, {rd.coords[0],rd.coords[1]}, , {rt.coords[0],rt.coords[1]}, {0,rt.coords[1]}, {0,0} };

    draw_filled_polygone(points, 11, "black", graphismes);
}



void rafraichirEcran(MlvType* graphismes)
{
    draw_filled_rectangle(0, 0, 750, 500, "white", graphismes);
}

*/
