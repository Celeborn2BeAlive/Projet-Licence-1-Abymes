void initialisationJoueur(mobile* joueur, int** carte, int nbre_lignes, int nbre_colonnes, int niveau, int direction);
int deplacementJoueur(int** carte, mobile* joueur, int type_deplacement, int nbre_lignes, int nbre_colonnes);
void sauvegarde(int niveau, mobile* joueur);
int chargement(int* niveau, mobile* joueur);
