int** chargementCarte(char* f, int* nbre_lignes, int* nbre_colonnes, coordonnees* arrivee);

void menuConsole(int** carte, int* nbre_lignes, int* nbre_colonnes, mobile* joueur);
void affichageConsole(int** carte, mobile joueur, int nbre_lignes, int nbre_colonnes);


void initialisationJoueur(mobile* joueur, int** carte, int nbre_lignes, int nbre_colonnes, int niveau, int direction);
void deplacementJoueur(int** carte, mobile* joueur, int type_deplacement, int nbre_lignes, int nbre_colonnes);
int absenceMur(int** carte, int i, int j);


void initGraphique(int** carte, mobile* joueur, int* nbre_lignes, int* nbre_colonnes, int murs_charges[][12], point* p, point* s);

double obtenirCoordX(droiteaffine d, double y);
double obtenirCoordY(droiteaffine d, double x);

void initPoints(point* s);
void initMurs(point* p, point* p_arriere, mur** m);

void chargementMurs(mobile joueur, int** carte, int nbre_lignes, int nbre_colonnes, int murs_charges[][12]);

point* initPerm(int* permutation, point* s);

void calculCoefficientsMouvement(point* perm, point* s, double coeff[][32], double* coeff_o, double* coeff_a);

void deplacementPoints(point* s, int etape_deplacement, int etapes_restantes, int type_mouvement, double coeff[][32], double* coeff_o, double* coeff_f);

void initEcran(point* screen_right_top, point* screen_right_down, point* screen_left_down, point* screen_left_top, point* p);

