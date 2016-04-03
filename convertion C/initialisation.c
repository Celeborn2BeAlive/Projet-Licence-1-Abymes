#include "graphic_structures.h"
#include "graphic_initialisation.h"


double getCoordX(droiteaffine d, double y)
{

 double x;
 
 x = (y - ((d.coefficient*(-d.origine->coords[0]))+d.origine->coords[1]))/d.coefficient;
 
 return x;
 
}

double getCoordY(droiteaffine d, double x)
{

 double y;
 
 y = d.coefficient*x + ((d.coefficient*(-d.origine->coords[0]))+d.origine->coords[1]);

 return y;
 
}


void initPoints(point* s)
{
     
     const int LONGUEUR = 350;
     const int LARGEUR = 200;
     
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
	 droiteaffine beta = initDroiteAffine(-s[24].coords[1]/s[24].coords[0], &s[3]);
     droiteaffine delta = initDroiteAffine(s[24].coords[1]/s[24].coords[0], &s[4]);
     
	 
	 
	 s[16].coords[0] = 3*(LONGUEUR/4)-3*LONGUEUR;
	 s[16].coords[1] = getCoordY(alpha, s[16].coords[0]);
	  

	 s[23].coords[0] = s[16].coords[0];
	 s[23].coords[1] = getCoordY(gama, s[16].coords[0]);
	  
 
	 s[8].coords[0] = -3*(LARGEUR/4);
	 s[8].coords[1] = getCoordY(alpha, s[8].coords[0]);
	  
	  
	 s[15].coords[0] = s[8].coords[0];
	 s[15].coords[1] = getCoordY(gama, s[8].coords[0]);
	 
	 	 
	 
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
	 s[9].coords[1] = getCoordY(epsilon, s[9].coords[0]);
	 

	 s[17].coords[0] = s[16].coords[0] + 2*LONGUEUR;
	 s[17].coords[1] = getCoordY(epsilon, s[17].coords[0]);
	 
	 
	 droiteaffine teta = initDroiteAffine(s[25].coords[1]/(s[1].coords[0]-s[25].coords[0]), &s[6]);

	 s[14].coords[0] = s[15].coords[0] + LONGUEUR;
	 s[14].coords[1] = getCoordY(teta, s[14].coords[0]);
	 

	 s[22].coords[0] = s[23].coords[0] + 2*LONGUEUR;
	 s[22].coords[1] = getCoordY(teta, s[22].coords[0]);
	 
	 
	 droiteaffine omega = initDroiteAffine(s[25].coords[1]/(s[1].coords[0]-s[25].coords[0]), &s[2]);

	 s[10].coords[0] = s[8].coords[0] + 2*LONGUEUR;
	 s[10].coords[1] = getCoordY(omega, s[10].coords[0]);
	 

	 s[18].coords[0] = s[16].coords[0] + 4*LONGUEUR;
	 s[18].coords[1] = getCoordY(omega, s[18].coords[0]);
	 
	 
	 droiteaffine sigma = initDroiteAffine(-s[25].coords[1]/(s[1].coords[0]-s[25].coords[0]), &s[5]);

	 s[13].coords[0] = s[15].coords[0] + 2*LONGUEUR;
	 s[13].coords[1] = getCoordY(sigma, s[13].coords[0]);
	 

	 s[21].coords[0] = s[23].coords[0] + 4*LONGUEUR;
	 s[21].coords[1] = getCoordY(sigma, s[21].coords[0]);

}


void initWalls(point* p, point* back, wall** w)
{
     w[0][0] = initWall(&p[0], &p[1], &p[6], &p[7]);
     w[0][1] = initWall(&p[1], &p[2], &p[5], &p[6]);
     w[0][2] = initWall(&p[2], &p[3], &p[4], &p[5]);
     w[0][3] = initWall(&p[11], &p[3], &p[4], &p[12]);
     w[0][4] = initWall(&p[19], &p[20], &p[12], &p[11]);
     w[0][5] = initWall(&p[27], &p[19], &p[20], &p[28]);
     w[0][6] = initWall(&p[26], &p[27], &p[28], &p[29]);
     w[0][7] = initWall(&p[25], &p[26], &p[29], &p[30]);
     w[0][8] = initWall(&p[24], &p[25], &p[30], &p[31]);
     w[0][9] = initWall(&p[24], &p[31], &p[23], &p[16]); 
     w[0][10] = initWall(&p[16], &p[8], &p[15], &p[23]);
     w[0][11] = initWall(&p[8], &p[0], &p[7], &p[15]);  
	 
     w[1][0] = initWall(&p[9], &p[1], &p[6], &p[14]);
     w[1][1] = initWall(&p[8], &p[9], &p[14], &p[15]);
     w[1][2] = initWall(&p[16], &p[17], &p[22], &p[23]);
     w[1][3] = initWall(&p[25], &p[17], &p[22], &p[30]);
     w[1][4] = initWall(&p[26], &p[18], &p[21], &p[29]);
     w[1][5] = initWall(&p[18], &p[19], &p[20], &p[21]);
     w[1][6] = initWall(&p[10], &p[11], &p[12], &p[13]);
     w[1][7] = initWall(&p[10], &p[2], &p[5], &p[13]);
	 
     w[2][0] = initWall(&p[9], &p[10], &p[13], &p[14]); 
     w[2][1] = initWall(&p[17], &p[9], &p[14], &p[22]);
     w[2][2] = initWall(&p[17], &p[18], &p[21], &p[22]);
     w[2][3] = initWall(&p[18], &p[10], &p[13], &p[21]);

     w[3][0] = initWall(&back[0], &back[1], &back[6], &back[7]);	 
     w[3][1] = initWall(&back[1], &back[2], &back[5], &back[6]);	
     w[3][2] = initWall(&back[2], &back[3], &back[4], &back[5]);	
     w[3][3] = initWall(&back[1], &p[1], &p[6], &back[6]);	
     w[3][4] = initWall(&back[2], &p[2], &p[5], &back[5]);		
     
}