typedef struct mobile mobile;
struct mobile
{
       int x;
       int y; 
       int direction;
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
 
typedef struct wall wall;
struct wall
{
       point* sommet[4];
};


point        initPoint(double x, double y);
wall         initWall(point* p1, point* p2, point* p3, point* p4);
droiteaffine initDroiteAffine(double coefficient, point* o);

void         displayPoint(point p);
void         displayPoints(point* s);


