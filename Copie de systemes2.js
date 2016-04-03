function systeme(matrice)
{

 this.matrice_systeme = matrice[0]; //systeme d'inconnues
 this.second_membre = matrice[1]; //solutions
 this.solutions = null;
 
 this.systeme_simplifie = false;

 this.S = sommeLignesSysteme; //permet d'ajouter une combinaison lineaire d'une ligne à une autre
 this.M = multiplicationLigneSysteme; //permet de multiplier une ligne par un scalaire
 this.P = permutationLignesSysteme; //permet d'echanger deux lignes
 this.supprimeLigne = supprimeLigne;
 this.simplificationSysteme = simplificationSysteme; //transforme le systeme en systeme diagonal superieur
 this.resolutionSysteme = resolutionSysteme; //recherche des solutions du systeme
 this.affichageSolutions = affichageSolutions; //affichage des solutions
 this.affichageSysteme = affichageSysteme; //affiche le systeme
 
    /*TRANSFORME LE SYSTEME EN SYSTEME DIAGONAL SUPERIEUR*/
	function simplificationSysteme()
	{
	 var i = null; //variables de boucles
	 var j = null;
	 var premiere_ligne_ok = false; //variable indiquant si la premiere ligne de la matrice est bien traité (premier coeff egal à 1)
	 var colonne_full_zero = false; //variable indiquant si la colonne en cours est uniquement constitué de 0
	 var sous_systeme = null;
	 
	 for(i = 0; i < this.matrice_systeme.length; i++) //on parcourt la matrice du systeme
	 {
	  if(this.matrice_systeme[i][0] == 1) //si le premier coefficient de la ligne i vaut 1
	  {
	   this.P(i, 0); //on place la ligne i en premiere position
	   premiere_ligne_ok = true; //on indique que la premiere ligne est bien traité
	   break; //on casse la boucle
	  }
	 }
	 
	 if(premiere_ligne_ok == false) //si la premiere ligne n'a pas été bien traité
	 {
	  for(i = 0; i < this.matrice_systeme.length; i++) //on parcourt la matrice du systeme
	  {
	   if(this.matrice_systeme[i][0] != 0) //des que le premier coefficient d'une est non nul
	   {
	     this.P(i, 0); //on place cette ligne en premiere position
		 this.M(0, 1/this.matrice_systeme[0][0]); //on divise cette ligne par le premier coefficient pour reduire celui ci à 1
		 premiere_ligne_ok = true; //on indique que la premiere ligne est bien traité
		 break; //on casse la boucle
	   }
	   else //si apres avoir parcouru la matrice aucun premier coefficient non nul n'a été trouvé
	   {
	    if(i == this.matrice_systeme.length - 1)
		{
		 colonne_full_zero = true; //on indique que la colonne est rempli de 0
		}
	   }
	  }
	 }
	 
	 if(this.matrice_systeme.length != 1) //si la matrice du systeme n'est pas une matrice ligne
	 {
	  for(i = 1; i < this.matrice_systeme.length; i++) //on parcourt toutes les lignes en dessous de la premiere
	  {
	   if(this.matrice_systeme[i][0] != 0) //si le premier coeff est non nul
	   {
	    this.S(0, i, -this.matrice_systeme[i][0]); //on lui ajoute/retire une combinaison lineaire de la premiere ligne pr reduire son premier coeff à 0
	   }
	  }
	  
	  sous_systeme = new Array(); //on crée la matrice du sous systeme de notre systeme
	  sous_systeme[0] = new Array();
	  sous_systeme[1] = new Array();
	  
	  for(i = 0; i < this.matrice_systeme.length - 1; i++) //on remplit les lignes du sous systeme 
	  {
	   sous_systeme[0][i] = new Array(); //on crée une matrice ligne pr chaque ligne
	   sous_systeme[1][i] = this.second_membre[i+1]; //on remplit le second membre
	   
	   for(j = 0; j < this.matrice_systeme[i].length - 1; j++) //on remplit chaque case de la matrice du systeme du sous systeme
	   {
	    sous_systeme[0][i][j] = this.matrice_systeme[i+1][j+1];
	   }
	  }
	  
	  sous_systeme = new systeme(sous_systeme); //on instance le sous systeme comme une instance de la classe systeme
	  sous_systeme.simplificationSysteme(); //on simplifie le sous systeme
	  
	  for(i = 0; i < this.matrice_systeme.length - 1; i++) //on recupere le sous systeme simplifié dans notre systeme actuel
	  {
	   this.second_membre[i+1] = sous_systeme.second_membre[i];
	   
	   for(j = 0; j < this.matrice_systeme[i].length - 1; j++)
	   {
	    this.matrice_systeme[i+1][j+1] = sous_systeme.matrice_systeme[i][j];
	   }
	  }
	 }
	 
	 this.systeme_simplifie = true;
	}
	
	
	/*FONCTION DE RESOLUTION DU SYSTEME*/
	function resolutionSysteme(etape)
	{
	 if(this.systeme_simplifie == false) this.simplificationSysteme();
	 
	 var i = null;
	 var j = null;
	 var l = 0;
	 var full_zero = true;
	 var no_solutions = false;
	 
	 for(i = 0; i < this.matrice_systeme.length; i++)
	 {
	  for(j = 0; j < this.matrice_systeme[i].length; j++)
	  {
	   if(this.matrice_systeme[i][j] != 0)
	   {
	    full_zero = false;
		break;
	   }
	  }
	  if(full_zero == true)
	  {
	   if(this.second_membre[i] != 0)
	   {
	    no_solutions = true;
		break;
	   }
	   else this.supprimeLigne(i);
	  }
	  full_zero = true;
	 }

	 if(no_solutions == false)
	 {
	  this.solutions = new Array();
	  
	  for(i = 0; i < this.matrice_systeme[0].length; i++) //creation solutions vierges
	  {
	   this.solutions[i] = new Array();
	   for(j = 0; j < this.matrice_systeme[0].length + 1; j++)
	   {
	    if(i == j) this.solutions[i][j] = 1;
		else this.solutions[i][j] = 0;
	   }
	  }
	  
	  for(i = 0; i < this.matrice_systeme.length; i++) //remplissage avec matrice simplifié
	  {
	   for(j = 0; j < this.matrice_systeme[0].length + 1; j++)
	   {
	    if(i == j) this.solutions[i][j] = 0;
	    else if(j == this.matrice_systeme[0].length) this.solutions[i][j] = this.second_membre[i];
		else this.solutions[i][j] = -this.matrice_systeme[i][j];
	   }
	  }
	  
	  if(etape == 2 || etape == 3)
	  {
	   this.solutions[1][3] = this.solutions[1][3] + this.solutions[1][2]*this.solutions[2][3];
	   this.solutions[1][2] = 0;
	   
	   this.solutions[0][3] = this.solutions[0][3] + this.solutions[0][2]*this.solutions[2][3] + this.solutions[0][1]*this.solutions[1][3];
	   this.solutions[0][2] = 0;
	   this.solutions[0][1] = 0;
	  }
	 }
	}
	
	
	
	/*FONCTION D'AFFICHAGE DU SYSTEME*/
	function affichageSysteme()
	{
	 var i = null;
	 var j = null;
	 
	 document.write('<br /><table>');
	 
	 for(i = 0; i < this.matrice_systeme.length; i++)
	 {
      document.write('<tr>');
	  for(j = 0; j <= this.matrice_systeme[i].length; j++)
	  {
	   document.write('<td>');
	   if(j == this.matrice_systeme[i].length)
	   {
	    document.write(' = '+this.second_membre[i]);
	   }
	   else
	   {
	    if(this.matrice_systeme[i][j] != 0)
		{
	     document.write(this.matrice_systeme[i][j] +'<span style="color:blue">a'+ j +'</span>');
		 
		 if(j != this.matrice_systeme[i].length - 1)
		  document.write(' + ');
		}
       }
	   document.write('</td>');
	  }
	  document.write('</tr>');
	 } 
	 document.write('</table>');
	}
 
    /*FONCTIONS D'AFFICHAGE DES SOLUTIONS*/
	function affichageSolutions()
	{
	 var i = null;
	 var j = null;
	 
	 document.write('<br /><table border="1">');
	 
	 for(i = 0; i < this.solutions.length; i++)
	 {
      document.write('<tr>');
	  for(j = 0; j < this.solutions[i].length; j++)
	  {
	   document.write('<td>'+this.solutions[i][j]+'</td>');
	  }
	  document.write('</tr>');
	 }
	}
 
    /*FONCTIONS D'OPERATIONS SUR LE SYSTEME*/
	function supprimeLigne(l)
	{
	 var i = null;
	 var j = null;
	 var k = -1;
	 var nouvelle_matrice_systeme = new Array();
	 var nouveau_second_membre = new Array();
	 
	 for(i = 0; i < this.matrice_systeme.length; i++)
	 {
	  if(i != l)
	  {
	   k++;
	   nouveau_second_membre[k] = this.second_membre[i];
	   nouvelle_matrice_systeme[i] = new Array();
	   for(j = 0; j < this.matrice_systeme[i].length; j++)
	   {
	    nouvelle_matrice_systeme[k][j] = this.matrice_systeme[i][j];
	   }
	  }
	 }
	 
	 this.matrice_systeme = nouvelle_matrice_systeme;
	 this.second_membre = nouveau_second_membre;
	}
	
	function sommeLignesSysteme(l1, l2, s)
	{
	 if(s == null) s = 1;
	
	 this.matrice_systeme = sommeLignesMatrice(this.matrice_systeme, l1, l2, s);
	 this.second_membre = sommeLignesMatrice(this.second_membre, l1, l2, s);
	 
	 for(i = 0; i < this.matrice_systeme.length; i++)
	 {
	  this.second_membre[i] = Math.round(this.second_membre[i]*100)/100;
	  for(j = 0; j < this.matrice_systeme[i].length; j++)
	  {
	   this.matrice_systeme[i][j] = Math.round(this.matrice_systeme[i][j]*100)/100;
	  }
	 }
	}
	
	function multiplicationLigneSysteme(l, s)
	{
	 var i = null;
	 var j = null;
	 
	 this.matrice_systeme = multiplicationLigneMatrice(this.matrice_systeme, l, s);
	 this.second_membre = multiplicationLigneMatrice(this.second_membre, l, s);
	 
	 for(i = 0; i < this.matrice_systeme.length; i++)
	 {
	  this.second_membre[i] = Math.round(this.second_membre[i]*100)/100;
	  for(j = 0; j < this.matrice_systeme[i].length; j++)
	  {
	   this.matrice_systeme[i][j] = Math.round(this.matrice_systeme[i][j]*100)/100;
	  }
	 }
	}
	
	function permutationLignesSysteme(l1, l2)
	{
	
	 this.matrice_systeme = permutationLignesMatrice(this.matrice_systeme, l1, l2);
	 this.second_membre = permutationLignesMatrice(this.second_membre, l1, l2);
	}
}