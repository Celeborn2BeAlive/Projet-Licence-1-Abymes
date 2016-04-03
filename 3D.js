/*declaration des vecteurs de la base canonique de R^3*/
var vecteur_x = new Array(1, 0, 0);
var vecteur_y = new Array(0, 1, 0);
var vecteur_z = new Array(0, 0, 1);

//declaration du vecteur selon lequel on realise la projection
var vecteur_p = new Array(1, 1, 1);


//creation d'un systeme a partir des coordonnées de ce vecteur pour trouver le plan orthogonal
var systeme_vecteur_p = new Array();

systeme_vecteur_p[0] = new Array();
systeme_vecteur_p[0][0] = vecteur_p;
systeme_vecteur_p[1] = new Array();
systeme_vecteur_p[1][0] = 0;

var systeme_plan_P = new systeme(systeme_vecteur_p);

systeme_plan_P.resolutionSysteme(1);

//on crée un espace vectoriel a partir des solutions
var plan_P = creerEspaceVectoriel(systeme_plan_P.solutions);

affichageMatrice(plan_P.base);


//creation de l'espace vectoriel du plan engendré par les vecteurs p et z
var matrice_plan_p_z = new Array();

matrice_plan_p_z[0] = vecteur_z;
matrice_plan_p_z[1] = vecteur_p;

var plan_p_z = new espaceVectoriel(matrice_plan_p_z);

affichageMatrice(plan_p_z.base);

//on calcule la droite vectorielle intersection du plan de projection de du plan vect(p, z)
var intersection = intersectionPlans(plan_P, plan_p_z);

affichageMatrice(intersection.base);

//on cherche a present le vecteur u de norme 1 et pointant vers le haut
var i_cx = intersection.base[0][0];
var i_cy = intersection.base[0][1];
var i_cz = intersection.base[0][2];

var epsilon = Math.round((Math.sqrt(1/((i_cx)*(i_cx)+(i_cy)*(i_cy)+(i_cz)*(i_cz))))*100)/100;

if(i_cz < 0) epsilon = -epsilon;

var vecteur_u = new Array(Math.round(epsilon*i_cx*100)/100, Math.round(epsilon*i_cy*100)/100, Math.round(epsilon*i_cz*100)/100);


//on cherche le vecteur de norme 1 sur la droite vectorielle engendré par p
var p_cx = vecteur_p[0];
var p_cy = vecteur_p[1];
var p_cz = vecteur_p[2];


var epsilon = Math.round((Math.sqrt(1/((p_cx)*(p_cx)+(p_cy)*(p_cy)+(p_cz)*(p_cz))))*100)/100;

vecteur_p_prim = new Array(Math.round(epsilon*p_cx*100)/100, Math.round(epsilon*p_cy*100)/100, Math.round(epsilon*p_cz*100)/100);

//on fait le produit vectoriel de u et p' pour trouver v et ainsi avoir la base canonique 2D
var vecteur_v = produitVectoriel(vecteur_u, vecteur_p_prim);

//on projete les vecteurs x, y et z dans vect(u, v)
systeme_projection = new Array();

systeme_projection[0] = new Array();
systeme_projection[1] = new Array();

systeme_projection[0][0] = new Array(vecteur_p[0], vecteur_u[0], vecteur_v[0]);
systeme_projection[0][1] = new Array(vecteur_p[1], vecteur_u[1], vecteur_v[1]);
systeme_projection[0][2] = new Array(vecteur_p[2], vecteur_u[2], vecteur_v[2]);

systeme_projection[1][0] = vecteur_x[0];
systeme_projection[1][1] = vecteur_x[1];
systeme_projection[1][2] = vecteur_x[2];

var sys_projection_x = new systeme(systeme_projection);

sys_projection_x.resolutionSysteme(3);

var P_vecteur_x = new Array();

P_vecteur_x[0] = sys_projection_x.solutions[1][3];
P_vecteur_x[1] = sys_projection_x.solutions[2][3];

document.write("P(x) = "+P_vecteur_x[0]+"u +"+P_vecteur_x[1]+"v <br />");



systeme_projection[0][0] = new Array(vecteur_p[0], vecteur_u[0], vecteur_v[0]);
systeme_projection[0][1] = new Array(vecteur_p[1], vecteur_u[1], vecteur_v[1]);
systeme_projection[0][2] = new Array(vecteur_p[2], vecteur_u[2], vecteur_v[2]);

systeme_projection[1][0] = vecteur_y[0];
systeme_projection[1][1] = vecteur_y[1];
systeme_projection[1][2] = vecteur_y[2];

var sys_projection_y = new systeme(systeme_projection);

sys_projection_y.resolutionSysteme(3);

var P_vecteur_y = new Array();

P_vecteur_y[0] = sys_projection_y.solutions[1][3];
P_vecteur_y[1] = sys_projection_y.solutions[2][3];

document.write("P(y) = "+P_vecteur_y[0]+"u +"+P_vecteur_y[1]+"v <br />");



systeme_projection[0][0] = new Array(vecteur_p[0], vecteur_u[0], vecteur_v[0]);
systeme_projection[0][1] = new Array(vecteur_p[1], vecteur_u[1], vecteur_v[1]);
systeme_projection[0][2] = new Array(vecteur_p[2], vecteur_u[2], vecteur_v[2]);

systeme_projection[1][0] = vecteur_z[0];
systeme_projection[1][1] = vecteur_z[1];
systeme_projection[1][2] = vecteur_z[2];

var sys_projection_z = new systeme(systeme_projection);

sys_projection_z.resolutionSysteme(3);

var P_vecteur_z = new Array();

P_vecteur_z[0] = sys_projection_z.solutions[1][3];
P_vecteur_z[1] = sys_projection_z.solutions[2][3];

document.write("P(z) = "+P_vecteur_z[0]+"u +"+P_vecteur_z[1]+"v <br />");

