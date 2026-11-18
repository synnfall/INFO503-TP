#include <stdbool.h>

typedef int* doubleTas;

doubleTas creerDoubleTas(int taille);
bool estDoubleTasVide(doubleTas t);
void libererDoubleTas(doubleTas* t); 
void ajouterDoubleTas(doubleTas t, int valeur);
void reorganiseDoubleTasBin(doubleTas t, bool estGauche, int position_tab);

void afficheDoubleTas(doubleTas t);