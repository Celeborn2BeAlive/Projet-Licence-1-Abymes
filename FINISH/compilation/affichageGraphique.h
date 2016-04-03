void tracerLigne(point point1, point point2, char* color, MlvType* graphismes);
void tracerMur(mur m, char* color, MlvType* graphismes);
void tracerBlockMurs(int numero, int murs_charges[][12], mur** m, MlvType* graphismes);
void tracerScene(point* s, int etape_deplacement, int type_mouvement, int murs_charges[][12], mur** m, MlvType* graphismes, point screen_left_top, point screen_right_top);
void tracerEcran(point screen_right_top, point screen_right_down, point screen_left_down, point screen_left_top, MlvType* graphismes);
void rafraichirEcran(MlvType* graphismes);
void tracerSquelette(point* s, MlvType* graphismes);

