typedef struct coordonnees coordonnees;
struct coordonnees
{
    int x;
    int y;
};

typedef struct mobile mobile;
struct mobile
{
    char name[20];
    int direction;
    coordonnees coords;
};



typedef struct point point;
struct point
{
       double coords[2];
};


typedef struct droiteaffine droiteaffine;
struct droiteaffine
{
       point* origine;
       double coefficient;
};

typedef struct mur mur;
struct mur
{
       point* sommet[4];
};



point initPoint(double x, double y);
mur initMur(point* p1, point* p2, point* p3, point* p4);
droiteaffine initDroiteAffine(double coefficient, point* o);
void afficherPoint(point p, int numero);
void afficherPoints(point* s);
void afficherMursCharges(int murs_charges[][12]);
void afficherCoeffs(double coeff[][32], double* coeff_o, double* coeff_f);
