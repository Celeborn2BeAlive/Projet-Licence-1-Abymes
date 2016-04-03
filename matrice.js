function affichageMatrice(matrice)
{
 var i = null;
 var j = null;
	 
 document.write('<br /><table border="1">');
	 
 for(i = 0; i < matrice.length; i++)
 {
  document.write('<tr>');
  for(j = 0; j < matrice[i].length; j++)
  {
   document.write('<td>'+matrice[i][j]+'</td>');
  }
  document.write('</tr>');
 }
}


function ligneFullZero(l, matrice)
{
 var i = null;
 var full_zero = true;
 
 for(j = 0; j < matrice[l].length; j++)
 {
  if(matrice[l][j] != 0) 
  {
   full_zero = false;
   break;
  }
 }
 
 return full_zero;
}


function suppressionLigneMatrice(l, matrice)
{
 var nouvelle_matrice = new Array();

 var i = null;
 var j = null;
 var k = -1;
 
 for(i = 0; i < matrice.length; i++)
 {
  if(i != l)
  {
   k++;
   nouvelle_matrice[k] = new Array();
   for(j = 0; j < matrice[i].length; j++)
   {
	nouvelle_matrice[k][j] = matrice[i][j];
   }
  }
 }
 
 return nouvelle_matrice;
}


function transposeeMatrice(matrice)
{
 var transposee = new Array();
 var i = null;
 var j = null;
 
 for(i = 0; i < matrice[0].length; i++)
 {
  transposee[i] = new Array();
  
  for(j = 0; j < matrice.length; j++)
  {
   transposee[i][j] = matrice[j][i];
  }
 }

 return transposee;
}


function sommeLignesMatrice(matrice, l1, l2, s)
{
 var i = null;
 if(s == null) s = 1;
 
 if(matrice[l2].length == null) matrice[l2] += (s * matrice[l1]);
 else
 {
  for(i = 0; i < matrice[l2].length; i++)
  {
   matrice[l2][i] += (s * matrice[l1][i]);
  }
 }
 
 return matrice;
}


function multiplicationLigneMatrice(matrice, l, s)
{
 var i = null;
 
 if(matrice[l].length == null) matrice[l] *= s;
 else
 {
  for(i = 0; i < matrice[l].length; i++)
  {
   matrice[l][i] *= s;
  }
 }
 
 return matrice;
}


function permutationLignesMatrice(matrice, l1, l2)
{
 var i = null;
 var c = null;
 
 if(matrice[l1].length == null) 
 {
  c = matrice[l1];
  matrice[l1] = matrice[l2];
  matrice[l2] = c;
 }
 else
 {
  for(i = 0; i < matrice[l1].length; i++)
  {
   c = matrice[l1][i];
   matrice[l1][i] = matrice[l2][i];
   matrice[l2][i] = c;
  }
 }
 
 return matrice;
}


