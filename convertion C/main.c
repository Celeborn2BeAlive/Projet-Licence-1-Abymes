#include <stdio.h>
#include <stdlib.h>

#include "graphic_structures.h"
#include "graphic_initialisation.h"


//CONSTANTES :

                     
int perm_left[32] = {3,11,19,27,28,20,12,4,2,10,18,26,29,21,13,5,1,9,17,25,30,22,14,6,0,8,16,24,31,23,15,7};
int perm_right[32] = {24,16,8,0,7,15,23,31,25,17,9,1,6,14,22,30,26,18,10,2,5,13,21,29,27,19,11,3,4,12,20,28};
int perm_top[32] = {8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,24,25,26,27,28,29,30,31};
int perm_back[32] = {0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23};


int main(int argc, char *argv[])
{
  int i, j;
    
  const int LONGUEUR = 350; //Longueur du premier mur face au joueur
  const int LARGEUR = 200; //Largeur du premier mur au joueur    
      

  point Oprim = initPoint(350 - LONGUEUR/4, 350 - LARGEUR/3.33); //Origine du repere que nous allons utiliser
  
  point p[32]; //points de la scene
  point s[32]; //points sauvegarde de la scene
  point back[8]; //points à l'arriere de la scene


  wall* w[4];
        w[0] = malloc(12*sizeof(wall));
        w[1] = malloc(8*sizeof(wall));
        w[2] = malloc(4*sizeof(wall));
        w[3] = malloc(5*sizeof(wall));
  
  int* loading_walls[4];
       loading_walls[0] = malloc(12*sizeof(int));
       loading_walls[1] = malloc(8*sizeof(int));
       loading_walls[2] = malloc(4*sizeof(int));
       loading_walls[3] = malloc(5*sizeof(int));
 
  initPoints(&p);
  
  for(i = 0; i < 32; i++)
   for(j = 0; j <= 1; j++)
	 s[i].coords[j] = p[i].coords[j];
  
  for(i = 0; i <= 7; i++)
   for(j = 0; j <= 1; j++)
	 back[i].coords[j] = p[i].coords[j];
	 

 
  displayPoints(&p);
  
  initWalls(&p, &back, &w);
  
  
  
  system("PAUSE");
  
  for(i = 0; i < 4; i++)
   free(w[i]);
   
  
  return 0;
}