/******************************************************************************/
/* PRESENTATION - demo                                                        */
/* Ce programme demontre quelques unes des utilisations de la librairie       */
/* graphique developpee par les enseignants du DEUG SSM-S2 et S4 en permettant*/
/* de dessiner des motifs dans une fenetre de dimension variable.             */
/******************************************************************************/
/* COMPILATION                                                                */
/* La compilation d'un programme C utilisant la librairie est realisee par la */
/* commande suivante :                                                        */
/*                      compi_c <nom_prog>                                    */
/* Ou <nom_prog>.c est le nom du fichier contenant le programme source C.     */
/* Si la compilation est reussie, le programme executable sera cree sous le   */
/* repertoire courant avec le nom <nom_prog>.                                 */
/* Exemple :            ved projet.c            Edition du fichier source     */
/*                      compi_c projet          Lancement de la compilation   */
/*                      projet                  Lancement de l'execution      */
/******************************************************************************/
/* STRUCTURE                                                                  */
/* La structure d'un programme utilisant la librairie d'affichage est la      */
/* suivante :                                                                 */
/* ...                                                                        */
/* #include <MlvTypeC.h>        -> inclusion des definitions de type.         */
/* #include <MlvProcC.h>        -> inclusion des definitions de fonctions.    */
/* ...                                                                        */
/* main (int argc, char **argv)                                               */
/* {                                                                          */
/*    ...                                                                     */
/*    MlvType  x_var;           -> declaration d'une structure utilisee par   */
/*    ...                          toutes les procedures de la librairie.     */
/* }                                                                          */
/******************************************************************************/
/* UTILISATION DES COULEURS                                                   */
/* Tous les programmes de trace utilisent le parametre "color_name" qui permet*/
/* de pspecifier la couleur du dessin, du remplissage ou du texte a ecrire.   */
/* Cette chaine de caracteres est un nom anglais qui permet de preciser la    */
/* valeur des composantes R (rouge), G (vert et B (bleu).                     */
/*                                                                            */
/* La liste complete des noms et des valeurs des composantes sont stockes dans*/
/* le fichier "rgb.txt" qui se trouve dans le repertoire de cette librairie.  */
/*                                                                            */
/* Voici un extrait de ce fichier:                                            */
/*    ...                                                                     */
/* 173 216 230             light blue                                         */
/* 173 216 230             LightBlue                                          */
/* 176 224 230             powder blue                                        */
/* 176 224 230             PowderBlue                                         */
/* 175 238 238             pale turquoise                                     */
/* 175 238 238             PaleTurquoise                                      */
/*   0 206 209             dark turquoise                                     */
/*   0 206 209             DarkTurquoise                                      */
/*  72 209 204             medium turquoise                                   */
/*  72 209 204             MediumTurquoise                                    */
/*  64 224 208             turquoise                                          */
/*   0 255 255             cyan                                               */
/*    ...                                                                     */
/******************************************************************************/
/* LIBRAIRIE                                                                  */
/* change_cursor :  Change la forme du pointeur de la souris en utilisant une */
/*                  des fontes predefinies.                                   */
/*                                                                            */
/* change_cursor (                                                            */
/* int              cursor,             Numero de curseur entre 0 et          */
/*                                      MAX_CURSOR = 152                      */
/*                                      Curseurs particuliers:                */
/*                                      - BUSY_CURSOR  : une montre           */
/*                                      - READY_CURSOR : une fleche           */
/*    MlvStruct     *x_var)             Structure standard toujours passee    */
/*============================================================================*/
/* close_window : Ferme une fenetre precedemment ouverte par "create_window". */
/*                cette fonction est particulierement utile lorsqu'on a ouvert*/
/*                une deuxieme fenetre, et qu'on souhaite la fermer sans      */
/*                quitter le programme.                                       */
/*                                                                            */
/*                Attention : La structure standard "x_var" d'une fenetre     */
/*                fermee ne contient plus d'imformation pertinente. Ne plus   */
/*                l'utiliser pour l'affichage tant qu'une fenetre n'ait ete   */
/*                ouverte par "create_window" en passant cette structure.     */
/*                                                                            */
/* close_window (                                                             */
/*    MlvStruct     *x_var)             Structure standard toujours passee    */
/*============================================================================*/
/* create_window : Cree une fenetre vide dans laquelle un motif pourra etre   */
/*                 dessine. Le nom du display destination ainsi que les       */
/*                 dimensions de la fenetre sont passees en parametres.       */
/*                                                                            */
/*                 Le nom du display sur lequel doit etre affiche la fenetre  */
/*                 est une chaine de caracteres ecrite selon la syntaxe X     */
/*                 standard: <host:board.screen> (exemple: "carol:0.0").      */
/*                 Lorsque l'on desire ouvrir la connection sur l'ecran par   */
/*                 defaut, la valeur NULL doit etre passee.                   */
/*                                                                            */
/*                 create_window doit etre la premiere procedure a appeler.   */
/*                                                                            */
/* create_window (                                                            */
/*   char           *display_name,      Nom de l'ecran destination            */
/*   int            width,              Largeur desiree de la fenetre         */
/*   int            height,             Hauteur desiree de la fenetre         */
/*   MlvStruct      *x_var)             Structure standard toujours passee    */
/*============================================================================*/
/* display_area : Affiche tout ou partie de la fenetre.                       */
/*                La fonction "display_window" utilise cette fonction pour    */
/*                re-afficher (on dit aussi rafraichir) toute la fenetre.     */
/*                                                                            */
/*                Lorsque seulement une partie de la fenetre doit etre        */
/*                rafraichie, il est conseillee de ne re-afficher que cette   */
/*                partie. Le gain de temps peut etre tres sensible.           */
/*                                                                            */
/*                Le rectangle est defini par les coordonnees de son coin     */
/*                superieur gauche (x,y), sa largeur et sa hauteur.           */
/*                                                                            */
/* display_area (                                                             */
/*    int           x,                  Coordonnee en X du coin sup. gauche   */
/*    int           y,                  Coordonnee en Y du coin sup. gauche   */
/*    int           width,              Largeur de la partie a rafraichir     */
/*    int           height,             Hauteur de la partie a rafraichir     */
/*    MlvStruct     *x_var)             Structure standard toujours passee    */
/*============================================================================*/
/* draw_circle : Dessine un cercle a une position et avec un rayon specifies  */
/*               en parametre.                                                */
/*                                                                            */
/* draw_circle (                                                              */
/*    int           x,                  Coordonnee en X du centre             */
/*    int           y,                  Coordonnee en Y du centre             */
/*    int           radius,             Rayon du cercle                       */
/*    char          *color_name,        Couleur du trace                      */
/*    MlvStruct     *x_var)             Structure standard toujours passee    */
/*============================================================================*/
/* draw_filled_circle : Dessine un disque plein dont le centre et le rayon    */
/*                      sont passes en parametre.                             */
/*                                                                            */
/* draw_filled_circle (                                                       */
/*    int           x,                  Coordonnee en X du centre             */
/*    int           y,                  Coordonnee en Y du centre             */
/*    int           radius,             Rayon du disque                       */
/*    char          *color_name,        Couleur de remplissage                */
/*    MlvStruct     *x_var)             Structure standard toujours passee    */
/*============================================================================*/
/* draw_filled_polygone : Dessine un polygone plein, de couleur "gray", avec  */
/*                    le nombre de sommets "npoints". Le tableau "poly"       */
/*                    contient un nombre "npoints" de structures de type      */
/*                    XPoint. Cette structure possede 2 champs "x" et "y" de  */
/*                    type SHORT INT.                                         */
/*                                                                            */
/*                    Exemple:   XPoint pts[3] = { {1,1}, {3,4}, {2,3} };     */
/*                                ...                                         */
/*                               draw_filled_polygone(pts, 3, BLACK, x_var);  */
/*                                                                            */
/* draw_filled_polygone (                                                     */
/*    XPoint        poly[],             Liste des points                      */
/*    int           npoints,            Nombre de sommets du polygone         */
/*    char          *color_name,        Couleur de remplissage                */
/*    MlvStruct     *x_var)             Structure standard toujours passee    */
/*============================================================================*/
/* draw_filled_rectangle : Dessine un rectangle plein dans une fenetre        */
/*                  prealablement creee par la fonction "create_window".      */
/*                  Le rectangle est defini par les coordonnees de son coin   */
/*                  superieur gauche (x,y), sa largeur et sa  hauteur.        */
/*                  La coordonnee x correspond aux abscisses selon l'axe      */
/*                  horizontal oriente de gauche a droite, y correspond aux   */
/*                  ordonnees selon l'axe vertical oriente de haut en bas.    */
/*                  La couleur ("gray") specifie le niveau de gris a utiliser */
/*                  pour le remplissage.                                      */
/*                                                                            */
/* draw_filled_rectangle (                                                    */
/*    int           x,                  Coordonnee en X du coin sup. gauche   */
/*    int           y,                  Coordonnee en Y du coin sup. gauche   */
/*    int           width,              Largeur du rectangle (en pixels)      */
/*    int           height,             Hauteur du rectangle (en pixels)      */
/*    char          *color_name,        Couleur de remplissage                */
/*    MlvStruct     *x_var)             Structure standard toujours passee    */
/*============================================================================*/
/* draw_line : Dessine un segment de droite dans une fenetre prealablement    */
/*             creee par la fonction "create_window".                         */
/*             Les extremites du segment sont definies par deux points donnes */
/*             en parametre. Soit un point (x,y), x correspond aux abscisses  */
/*             selon l'axe horizontal oriente de gauche a droite, y correspond*/
/*             aux ordonnees selon l'axe vertical oriente de haut en bas.     */
/*                                                                            */
/* draw_line (                                                                */
/*    int           x1,                 Coordonnee en X du premier point      */
/*    int           y1,                 Coordonnee en Y du premier point      */
/*    int           x2,                 Coordonnee en X du deuxieme point     */
/*    int           y2,                 Coordonnee en Y du deuxieme point     */
/*    char          *color_name,        Couleur du trace                      */
/*    MlvStruct     *x_var)             Structure standard toujours passee    */
/*============================================================================*/
/* draw_point :Dessine un point dans  une fenetre prealablement creee par la  */
/*             fonction "create_window".                                      */
/*                                                                            */
/* draw_point (                                                               */
/*    int           x,                  Coordonnee en X du point              */
/*    int           y,                  Coordonnee en Y du point              */
/*    char          *color_name,        Couleur du trace                      */
/*    MlvStruct     *x_var)             Structure standard toujours passee    */
/*============================================================================*/
/* draw_rectangle : Dessine un rectangle dans une fenetre prealablement creee */
/*                  par la fonction "create_window".                          */
/*                  Le rectangle est defini par les coordonnees de son coin   */
/*                  superieur gauche (x,y), sa largeur et sa hauteur.         */
/*                  La coordonnee x correspond aux abscisses selon l'axe      */
/*                  horizontal oriente de gauche a droite, y correspond aux   */
/*                  ordonnees selon l'axe vertical oriente de haut en bas.    */
/*                                                                            */
/* draw_rectangle (                                                           */
/*    int           x,                  Coordonnee en X du coin sup. gauche   */
/*    int           y,                  Coordonnee en Y du coin sup. gauche   */
/*    int           width,              Largeur du rectangle (en pixels)      */
/*    int           height,             Hauteur du rectangle (en pixels)      */
/*    char          *color_name,        Couleur du trace                      */
/*    MlvStruct     *x_var)             Structure standard toujours passee    */
/*============================================================================*/
/* draw_string :    Affiche un texte dans une fenetre creee par create_window */
/*                  La position du texte est passee en parametre. Celle-ci    */
/*                  correspond a la position inferieure gauche du premier     */
/*                  caractere (comprendre inferieur comme base des lettres).  */
/*                  La fonction gere aussi les fontes systeme. On peut connai-*/
/*                  tre la liste des fontes disponible en tapant par exemple  */
/*                  la commande UNIX 'xlsfonts'.                              */
/*                                                                            */
/*                  La couleur ("gray") specifie le niveau de gris a utiliser */
/*                  pour le dessin du contour et le remplissage.              */
/*                                                                            */
/* draw_string (                                                              */
/*    int           x,                  Coordonnee en X du coin inf. gauche   */
/*    int           y,                  Coordonnee en Y du coin inf. gauche   */
/*    char          *text,              Texte a afficher                      */
/*    char          *font_name          Nom de la fonte a utiliser            */
/*    char          *color_name,        Couleur du trace                      */
/*    MlvStruct     *x_var)             Structure standard toujours passee    */
/*============================================================================*/
/* mouse_wait : Suspend l'execution jusqu'au prochain clic souris et retourne */
/*              les coordonnees du point vise ou des valeurs negatives en     */
/*              cas d'echec.                                                  */
/*                                                                            */
/* mouse_wait (                                                               */
/*    int           *x,                 Coordonnee en X du point attendu      */
/*    int           *y,                 Coordonnee en Y du point attendu      */
/*    MlvStruct     *x_var)             Structure standard toujours passee    */
/*============================================================================*/
/* name_window: Change le titre d'une fenetre.                                */
/*                                                                            */
/* name_window (                                                              */
/*    char          *name,              Nouveau titre de la fenetre           */
/*    MlvStruct     *x_var)             Structure standard toujours passee    */
/*============================================================================*/
/* random : Genere un nombre aleatoire dans l'intervalle defini par l'utili-  */
/*          sateur.                                                           */
/*          Soit range, l'entier defini comme etant la borne superieure de    */
/*          l'intervalle, "random" retourne une valeur dans l'intervalle :    */
/*          [0,(range-1)]                                                     */
/*                                                                            */
/* random (                                                                   */
/*    int           range)              Borne superieure de l'intervalle      */
/*============================================================================*/
/* text_size :  Calcule les dimensions en pixels d'une chaine de caracteres   */
/*              donnee et pour une police de caracteres (on dit aussi fonte)  */
/*              donnee.                                                       */
/*                                                                            */
/*              Cette fonction permet de calculer les dimensions (largeur,    */
/*              hauteur et elevation) d'un message a afficher, et donc        */
/*              d'adapter l'interface pour centrer et aligner les textes.     */
/*                                                                            */
/*              Les parametres "text", "font_name" et "x_var" sont en entree  */
/*              de la fonction. "width", "height" et "ascent" sont en sortie. */
/*                                                                            */
/* text_size (                                                                */
/*    char          *text,              Texte qu'on desirera afficher         */
/*    char          *font_name          Nom de la fonte a utiliser            */
/*    int           *width,             Largeur totale du texte (en pixels)   */
/*    int           *height,            hauteur du texte (du plus bas au plus */
/*                                      haut). Par exemple "pb" a une hauteur */
/*                                      superieure a celle de "ab".           */
/*    int           *ascent,            Hauteur au dessus de la base du texte */
/*                                      (baseline). Par exemple, "pb" et "ab" */
/*                                      ont la meme elevation (ascent).       */
/*    MlvStruct     *x_var)             Structure standard toujours passee    */
/*============================================================================*/
/* wait_seconds : Suspend l'execution pendant le nombre specifie de secondes. */
/*                                                                            */
/* wait_seconds (                                                             */
/*    int           seconds)            Nombre entier de secondes a attendre  */
/*============================================================================*/
/* wait_micros : Suspend l'execution pendant le nombre specifie de micro-     */
/*               secondes (=1.e-6 seconde).                                   */
/*                                                                            */
/* wait_micros (                                                              */
/******************************************************************************/

#include <stdio.h>

#include <MlvTypeC.h>
#include <MlvProcC.h>


/******************************************************************************/
/* Retourner le plus proche entier                                            */
/******************************************************************************/
int round (float x)
{
   if (x >= 0.0)
      return ((int)(x + 0.5));
   else /* (x < 0.0) */
      return((int)(x - 0.5));
} /* round */



/******************************************************************************/
/* Demonstration d'affichage des points                                       */
/******************************************************************************/
void demo_point (int width, int height, MlvType *x_var_p)
{
   int border        = 10;
   int min_increment = 3;
   int x_increment, y_increment, x1, y1;

   x_increment = width / 50;
   if (x_increment < min_increment)
      x_increment = min_increment;
   y_increment = height / 50;
   if (y_increment < min_increment)
      y_increment = min_increment;
   x1 = border;
   y1 = border;
   while ((x1 < width - border) && (y1 < height - border))
   {
      draw_point (x1,y1,"blue",x_var_p);
      x1 = x1 + x_increment;
      y1 = y1 + y_increment;
   }
   display_window (x_var_p);
} /* demo_point */


/******************************************************************************/
/* Demonstration d'affichage des lignes                                       */
/******************************************************************************/
void demo_line (int width, int height, MlvType *x_var_p)
{
   int border = 10;
   int x_increment = 5;
   int y_increment = 7;
   int x1, y1, x2, y2;

   x1 = border;
   y1 = border;
   x2 = width - border;
   y2 = height - border;
   while ((x1 < width - border) && (y1 < height - border) &&
          (x2 > border)         && (y2 > border))
   {
      draw_line (x1,y1,x2,y2,"red",x_var_p);
      x1 = x1 + x_increment;
      y1 = y1 + y_increment;
      x2 = x2 - x_increment;
      y2 = y2 - y_increment;
   }
   display_window (x_var_p);
} /* demo_line */


/******************************************************************************/
/* Demonstration d'affichage des cercles                                      */
/******************************************************************************/
void demo_circle (int width, int height, MlvType *x_var_p)
{
   int   border           = 10;
   int   x_increment      = 10;
   int   radius_increment = 1;
   float x, y, a, b, x0;
   int   i, j, radius;
   int   gray_value;
   char  color_name[20];

   x0 = width / 3;
   x  = border;
   a  = -(height / 3) / ((x - x0) * (x - x0));
   b  = height - border;
   radius = 10;
   gray_value = 1;
   do
   {
      y = a * (x - x0) * (x - x0) + b;
      i = round(x);
      j = round(y);
      gray_value = (gray_value + 2) % 101;
      sprintf (color_name,"gray%d",gray_value);
      draw_circle (i,j,radius,color_name,x_var_p);
      radius = radius + radius_increment;
      x = x + x_increment;
   } while ((x >= border) && (x <= width - border) &&
            (y >= border) && (y <= height - border));
   display_window (x_var_p);
} /* demo_circle */


/******************************************************************************/
/* Demonstration d'affichage des rectangles                                   */
/******************************************************************************/
void demo_rectangle (int width, int height, MlvType *x_var_p)
{
   int border           = 10;
   int x_increment      = 10;
   int y_increment      = 10;
   int x0, y0, rec_width, rec_height;
   int color_index;
   char *color_table[] = {
      "PapayaWhip",  "AliceBlue",  "midnight blue", "DarkSeaGreen",
      "dark salmon", "violet red", "LemonChiffon3", "LightCyan1", 
      "aquamarine2", "gold1",      "sienna1",       "tan2"  };

   x0         = border;
   y0         = border;
   rec_width  = width  - 2 * border;
   rec_height = height - 2 * border;
   color_index = 0;
   do
   {
      draw_rectangle (x0,y0,rec_width,rec_height,color_table[color_index],
         x_var_p);
      color_index = (color_index + 1) % 12;
      x0         = x0 + x_increment;
      y0         = y0 + x_increment;
      rec_width  = rec_width  - 2 * x_increment;
      rec_height = rec_height - 2 * y_increment;
   } while ((rec_width > 0) && (rec_height > 0));
   display_window (x_var_p);
} /* demo_rectangle */


/******************************************************************************/
/* Demonstration d'affichage de texte                                         */
/******************************************************************************/
void demo_text (int width, int height, MlvType *x_var_p)
{
#define FONT_NUMBER 6
#define MARGIN      40
   int  x, y, i;
   int  text_width, text_height, text_ascent;
   char *text = "Demonstration de TEXTES";
   char *font[FONT_NUMBER] = {
      "10x20",
      "*-times-*-r-*",
      "-*-courier-bold-*--20-*",
      "*symbol*--34-*",
      "-adobe-helvetica-medium-o-normal--20-140-100-100-p-98-iso8859-1",
      "-*-helvetica-bold-r-normal--25-*-*-*-*-*-*-*" };
   char *color_table[FONT_NUMBER] = {
      "red", "green", "blue", "yellow", "magenta", "cyan"};

   x = MARGIN;
   y = 0;

   for (i=0; i<FONT_NUMBER; i++)
   {
      fprintf(stderr,"font[%d]=<%s>\n",i,font[i]);
      text_size(text,font[i],&text_width,&text_height,&text_ascent,x_var_p);
      y = y + text_height + MARGIN;
      draw_string (x,y,text,font[i],"black",x_var_p);
      draw_string (x,y+text_height,text,font[i],color_table[i],x_var_p);
      display_window (x_var_p);
   }
} /* demo_text */


/******************************************************************************/
/* Demonstration d'affichage des disques et rectangles remplis                */
/******************************************************************************/
void demo_disk (int width, int height, MlvType *x_var_p)
{
   int disk_number      = 40;
   int radius_max       = 20;
   int idisk, i, j, radius;
   int rectangle_width, rectangle_height;

/*----------------------------------------------------------------------------*/
/* Afficher les disques                                                       */
/*----------------------------------------------------------------------------*/
   for (idisk=0; idisk<disk_number; idisk++)
   {
      i      = random (width);
      j      = random (height);
      if (idisk % 2 == 0)
      {
         radius = random (radius_max);
         draw_filled_circle (i,j,radius,"blue",x_var_p);
         display_window (x_var_p);
      }
      else
      {
         rectangle_width  = random (radius_max);
         rectangle_height = random (radius_max);
         draw_filled_rectangle (i,j,rectangle_width,rectangle_height,"red",
            x_var_p);
         display_window (x_var_p);
      }
   }
} /* demo_disk */


/******************************************************************************/
/* Demonstration de test souris                                               */
/******************************************************************************/
void demo_mouse (int width, int height, MlvType *x_var_p)
{
   int              border = 40;
   int              x, y;               /* coordonnees ENTIERES */
   XPoint           points[10];         /* coordonnees SHORT des points saisis*/
   int              i;
   char             *text = "Cliquer 10 fois dans la fenetre";
   char             *font = "-*-helvetica-bold-r-normal--25-*-*-*-*-*-*-*";

/*----------------------------------------------------------------------------*/
/* Afficher le message                                                        */
/*----------------------------------------------------------------------------*/
   draw_string (0,border,text,font,"black",x_var_p);
   display_window (x_var_p);
/*----------------------------------------------------------------------------*/
/* Saisir les points                                                          */
/*----------------------------------------------------------------------------*/
   for (i=0; i<10; i++)
   {
      mouse_wait(&x,&y,x_var_p);
      printf ("   Point %2d : (%3d, %3d)\n",i,x,y);

      draw_point (x,y,"black",x_var_p);
/*----------------------------------------------------------------------------*/
/*    Conserver les coordonnees dans un tableau de SHORT INT                  */
/*----------------------------------------------------------------------------*/
      points[i].x = x;
      points[i].y = y;
/*----------------------------------------------------------------------------*/
/*    Lorsqu'au moins trois points ont ete saisis, remplir le polygone        */
/*----------------------------------------------------------------------------*/
      if (i >= 3)
         draw_filled_polygone (points,i+1,"gray",x_var_p);
/*----------------------------------------------------------------------------*/
/*    Rafraichir le dessin                                                    */
/*----------------------------------------------------------------------------*/
      display_window (x_var_p);
   }
} /* demo_mouse */


/******************************************************************************/
/* Demonstration dynamique d'affichage des lignes                             */
/******************************************************************************/
void anim_line (int width, int height, MlvType *x_var_p)
{
   int border      = 10;
   int x_increment = 15;
   int y_increment = 19;
   int x1, y1, x2, y2, seconds;

/*----------------------------------------------------------------------------*/
/* Saisir le delai d'affichage                                                */
/*----------------------------------------------------------------------------*/
   do
   {
      printf ("Entrer le delai d'affichage en secondes (entier de 1 a 10) : ");
      scanf ("%d",&seconds);
   } while ((seconds < 1) || (seconds > 10));
/*----------------------------------------------------------------------------*/
/* Boucle d'affichage des lignes                                              */
/*----------------------------------------------------------------------------*/
   x1 = border;
   y1 = border;
   x2 = width - border;
   y2 = height - border;
   while ((x1 < width - border) && (y1 < height - border) &&
          (x2 > border)         && (y2 > border))
   {
      draw_line (x1,y1,x2,y2,"black",x_var_p);
      display_window (x_var_p);
      wait_seconds (seconds);
      x1 = x1 + x_increment;
      y1 = y1 + y_increment;
      x2 = x2 - x_increment;
      y2 = y2 - y_increment;
   }
} /* anim_line */


/******************************************************************************/
/* Demonstration dynamique d'affichage des cercles                            */
/******************************************************************************/
void anim_circle (int width, int height, MlvType *x_var_p)
{
   int   border           = 10;
   int   x_increment      = 10;
   int   radius_increment = 1;
   float x, y, a, b, x0;
   int   i, j, radius, milliseconds;

/*----------------------------------------------------------------------------*/
/* Saisir le delai d'affichage                                                */
/*----------------------------------------------------------------------------*/
   do
   {
      printf ("Entrer le delai d'affichage en millisecondes (environ) : ");
      scanf ("%d",&milliseconds);
   } while (milliseconds < 1);
/*----------------------------------------------------------------------------*/
/* Boucle d'affichage des cercles                                             */
/*----------------------------------------------------------------------------*/
   x0 = width / 3;
   x  = border;
   a  = -(height / 3) / ((x - x0) * (x - x0));
   b  = height - border;
   radius = 10;
   do
   {
      y = a * (x - x0) * (x - x0) + b;
      i = round(x);
      j = round(y);
      draw_circle (i,j,radius,"black",x_var_p);
      display_window (x_var_p);
      wait_micros (milliseconds*1000);
      draw_circle (i,j,radius,"white",x_var_p);
      display_window (x_var_p);
      radius = radius + radius_increment;
      x = x + x_increment;
   } while ((x >= border) && (x <= width - border) &&
            (y >= border) && (y <= height - border));
} /* anim_circle */


/******************************************************************************/
/* Effacer la fenetre                                                         */
/******************************************************************************/
void effacer (int width, int height, MlvType *x_var_p)
{
   draw_filled_rectangle (0,0,width,height,"white",x_var_p);
   display_window (x_var_p);
} /* effacer */


/******************************************************************************/
/* Changer le curseur                                                         */
/******************************************************************************/
void changer_curseur (MlvType *x_var_p)
{
   int              cursor;
/*----------------------------------------------------------------------------*/
/* Saisir la fonte desiree                                                    */
/*----------------------------------------------------------------------------*/
   printf ("Choisir le numero de la fonte du curseur parmi les suivantes: \n");
   printf("\
   X_cursor             0  arrow                2  based_arrow_down     4 \n\
   based_arrow_up       6  boat                 8  bogosity            10 \n\
   bottom_left_corner  12  bottom_right_corner 14  bottom_side         16 \n\
   bottom_tee          18  box_spiral          20  center_ptr          22 \n\
   circle              24  clock               26  coffee_mug          28 \n\
   cross               30  cross_reverse       32  crosshair           34 \n\
   diamond_cross       36  dot                 38  dotbox              40 \n\
   double_arrow        42  draft_large         44  draft_small         46 \n\
   draped_box          48  exchange            50  fleur               52 \n\
   gobbler             54  gumby               56  hand1               58 \n\
   hand2               60  heart               62  icon                64 \n\
   iron_cross          66  left_ptr            68  left_side           70 \n\
   left_tee            72  leftbutton          74  ll_angle            76 \n\
   lr_angle            78  man                 80  middlebutton        82 \n\
   mouse               84  pencil              86  pirate              88 \n\
   plus                90  question_arrow      92  right_ptr           94 \n\
   right_side          96  right_tee           98  rightbutton        100 \n\
   rtl_logo           102  sailboat           104  sb_down_arrow      106 \n\
   sb_h_double_arrow  108  sb_left_arrow      110  sb_right_arrow     112 \n\
   sb_up_arrow        114  sb_v_double_arrow  116  shuttle            118 \n\
   sizing             120  spider             122  spraycan           124 \n\
   star               126  target             128  tcross             130 \n\
   top_left_arrow     132  top_left_corner    134  top_right_corner   136 \n\
   top_side           138  top_tee            140  trek               142 \n\
   ul_angle           144  umbrella           146  ur_angle           148 \n\
   watch              150  xterm              152 \n");
   scanf ("%d",&cursor);
/*----------------------------------------------------------------------------*/
/* Changer le curseur                                                         */
/*----------------------------------------------------------------------------*/
   change_cursor (cursor,x_var_p);
} /* changer_curseur */


/******************************************************************************/
/* Ouvrir et fermer d'autres fenetres que la fenetre principale               */
/******************************************************************************/
void ouvrir_fermer_fenetres ()
{
#define WINDOW_WIDTH  200
#define WINDOW_HEIGHT  50
   int              window_number;      /* nombre de fenetres desirees */
   int              i;                  /* index parmi les fenetres */
   MlvType          *x_var_list=NULL;   /* structures pour gerer les fenetres */
   char             buf[50];            /* buffer pour generer les noms */
/*----------------------------------------------------------------------------*/
/* Saisir le nombre de fentres desires                                        */
/*----------------------------------------------------------------------------*/
   printf ("Nombre de fenetres que vous desirez ouvrir : ");
   scanf ("%d",&window_number);
/*----------------------------------------------------------------------------*/
/* Allouer autant de structures standards que de fenetres desires             */
/*----------------------------------------------------------------------------*/
   if ((x_var_list=(MlvType*)calloc(window_number,sizeof(MlvType))) == NULL)
   {
      fprintf (stderr,
         "ouvrir_fermer_fenetres: Impossible d'allouer %d structures\n",
         window_number);
      return;
   }
/*----------------------------------------------------------------------------*/
/* Ouvrir les fenetres                                                        */
/*----------------------------------------------------------------------------*/
   for (i=0; i<window_number; i++)
   {
      create_window (NULL,WINDOW_WIDTH,WINDOW_HEIGHT,&(x_var_list[i]));
      sprintf (buf,"Fenetre %d",i+1);
      name_window (buf,&(x_var_list[i]));
   }
/*----------------------------------------------------------------------------*/
/* Marquer une temporisation                                                  */
/*----------------------------------------------------------------------------*/
   for (i=5; i>=0; i--)
   {
      fprintf (stderr,"Effacement des fenetres dans %2d secondes\r",i);
      wait_seconds (1);
   }
   printf ("\n");
/*----------------------------------------------------------------------------*/
/* Fermer les fenetres                                                        */
/*----------------------------------------------------------------------------*/
   for (i=0; i<window_number; i++)
   {
      close_window (&(x_var_list[i]));
   }
/*----------------------------------------------------------------------------*/
/* Liberer la memoire allouee                                                 */
/*----------------------------------------------------------------------------*/
   if (x_var_list)
      free (x_var_list);
   x_var_list = NULL;
} /* ouvrir_fermer_fenetres */


/******************************************************************************/
/******************************************************************************/
/* PROGRAMME PRINCIPAL                                                        */
/******************************************************************************/
int main (
   int              argc,               /* nombre d'arg. en ligne de commande */
   char             **argv)             /* liste des arguments */
{
/******************************************************************************/
/* Variables locales                                                          */
/******************************************************************************/
   char             *display_name=NULL; /* ecran destination */
   int              width;              /* largeur de la fenetre */
   int              height;             /* hauteur de la fenetre */
   int              option;             /* option choisie par l'utilisateur */
   MlvType          x_var;              /* structure standard de la librairie */

/******************************************************************************/
/* Saisir les dimensions de la fenetre a afficher (si elles n'ont pas ete     */
/* passees en ligne de commande)                                              */
/******************************************************************************/
   if ((argc < 3)                            ||
       (sscanf(argv[1],"%d",&width) <= 0)    ||
       (sscanf(argv[2],"%d",&height) <= 0))
   {
      do
      {
         printf ("Entrer les dimensions de la fenetre de dessin ");
         printf ("(largeur hauteur) : ");
      } while (scanf("%d %d",&width,&height) < 2);
   }
/******************************************************************************/
/* Creer et afficher la fenetre                                               */
/******************************************************************************/
   create_window (display_name,width,height,&x_var);
   name_window ("demo",&x_var);
/******************************************************************************/
/* Afficher le menu et saisir l'option choisie                                */
/******************************************************************************/
   do
   {
      printf("  0. effacer la fenetre\n");
      printf("  1. demonstration statique des points\n");
      printf("  2. demonstration statique des lignes\n");
      printf("  3. demonstration statique des cercles\n");
      printf("  4. demonstration statique des rectangles\n");
      printf("  5. demonstration statique d'affichage de texte\n");
      printf("  6. demonstration statique des disques et rectangles remplis\n");
      printf("  7. demonstration de test souris et remplissage de polygones\n");
      printf("  8. demonstration dynamique des lignes\n");
      printf("  9. demonstration dynamique des cercles\n");
      printf(" 10. changer la forme du curseur\n");
      printf(" 11. ouvrir / fermer plusieurs fenetres\n");
      printf(" 99. QUITTER\n");
      printf("Entrer l'option choisie : ");
      scanf ("%d",&option);
      switch (option)
      {
         case 0 : effacer        (width,height,&x_var);
                  break;
         case 1 : demo_point     (width,height,&x_var);
                  break;
         case 2 : demo_line      (width,height,&x_var);
                  break;
         case 3 : demo_circle    (width,height,&x_var);
                  break;
         case 4 : demo_rectangle (width,height,&x_var);
                  break;
         case 5 : demo_text      (width,height,&x_var);
                  break;
         case 6 : demo_disk      (width,height,&x_var);
                  break;
         case 7 : demo_mouse     (width,height,&x_var);
                  break;
         case 8 : anim_line      (width,height,&x_var);
                  break;
         case 9 : anim_circle    (width,height,&x_var);
                  break;
         case 10: changer_curseur (&x_var);
                  break;
         case 11: ouvrir_fermer_fenetres ();
                  break;
      }
   } while (option != 99);
/******************************************************************************/
/* Sortir                                                                     */
/******************************************************************************/
   exit (0);
} /* main */
