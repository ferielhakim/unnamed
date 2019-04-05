
#include "structs.h"

/* Prototypes des fonctions utilisées */
extern void drawMap(void);
extern void drawAnimatedEntity(GameObject *entity);
extern void drawHud(void);
extern void drawString(char *text, int x, int y, TTF_Font *font);


/* Structures globales */
extern Gestion jeu;
extern Map map;
extern GameObject player;
extern GameObject monster[];
extern TTF_Font *font;
