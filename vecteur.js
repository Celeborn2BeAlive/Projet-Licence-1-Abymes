function espaceVectoriel(matrice)
{
 this.base = new Array(); //creation du tableau de la base
 
 for(i = 0; i < matrice.length; i++) //boucle supprimant les vecteurs nul de la base
 {
  if(ligneFullZero(i, matrice) == true) 
  {
   matrice = suppressionLigneMatrice(i, matrice);
  }
  for(j = 0; j < matrice[i].length; j++)
  {
   matrice[i][j] = Math.round(matrice[i][j]*100)/100;
  }
 }
 
 this.base = matrice; //affectation de la base
}

function creerEspaceVectoriel(matrice_solutions) //créé un espace vectoriel a partir d'une matrice solution
{
 var i = null;

 var vecteurs = transposeeMatrice(matrice_solutions); //on transpose les vecteurs de la solution
 
 for(i = 0; i < vecteurs.length; i++) //on enleve les vecteurs nuls
 {
  if(ligneFullZero(i, vecteurs) == true) 
  {
   vecteurs = suppressionLigneMatrice(i, vecteurs);
  }
 }
 
 var espace_vectoriel = new espaceVectoriel(vecteurs); //on crée l'espace vectoriel engendré par les vecteurs de la solution
 
 return espace_vectoriel;
}


function intersectionPlans(plan1, plan2) //trouve la droite vectorielle ou le plan intersection de deux plans
{
 var i = null;
 var j = null;

 var matrice = new Array();
 matrice[0] = new Array();
 matrice[1] = new Array();
 
 var base_plan1 = transposeeMatrice(plan1.base);
 var base_plan2 = transposeeMatrice(plan2.base);
 
 for(i = 0; i < base_plan2.length; i++)
 {
  base_plan2 = multiplicationLigneMatrice(base_plan2, i, -1);
 }
 
 for(i = 0; i < base_plan1.length; i++)
 {
  matrice[0][i] = new Array();
  matrice[1][i] = 0;
  
  for(j = 0; j < base_plan1[i].length; j++)
  {
    matrice[0][i][j] = base_plan1[i][j];
  }
  
  for(j = 0; j < base_plan2[i].length; j++)
  {
    matrice[0][i][j+2] = base_plan2[i][j];
  }
 }
 
 var systeme_intersection = new systeme(matrice);
 
 systeme_intersection.resolutionSysteme(2);
 
 systeme_intersection = suppressionLigneMatrice(systeme_intersection.solutions.length - 1, systeme_intersection.solutions);

 
 base_plan1[0][0] = base_plan1[0][0]*systeme_intersection[0][3];
 base_plan1[1][0] = base_plan1[1][0]*systeme_intersection[0][3];
 base_plan1[2][0] = base_plan1[2][0]*systeme_intersection[0][3];
 
 base_plan1[0][1] = base_plan1[0][1]*systeme_intersection[1][3];
 base_plan1[1][1] = base_plan1[1][1]*systeme_intersection[1][3];
 base_plan1[2][1] = base_plan1[2][1]*systeme_intersection[1][3];
 
 systeme_intersection = new Array();
 
 var alpha = base_plan1[0][0] + base_plan1[0][1];
 var beta = base_plan1[1][0] + base_plan1[1][1];
 var gamma = base_plan1[2][0] + base_plan1[2][1];
 
 systeme_intersection[0] = new Array();
 systeme_intersection[0][0] = alpha;
 systeme_intersection[1] = new Array();
 systeme_intersection[1][0] = beta;
 systeme_intersection[2] = new Array();
 systeme_intersection[2][0] = gamma;
 
 systeme_intersection = creerEspaceVectoriel(systeme_intersection)
 
 return systeme_intersection;
}


function produitVectoriel(vecteur1, vecteur2) //retourne le produit vectoriel de deux vecteurs
{
 var produit_vectoriel = new Array();
 
 produit_vectoriel[0] = Math.round((vecteur1[1]*vecteur2[2] - vecteur1[2]*vecteur2[1])*100)/100;
 produit_vectoriel[1] = Math.round((vecteur1[2]*vecteur2[0] - vecteur1[0]*vecteur2[2])*100)/100;
 produit_vectoriel[2] = Math.round((vecteur1[0]*vecteur2[1] - vecteur1[1]*vecteur2[0])*100)/100;
 
 return produit_vectoriel;
 
}