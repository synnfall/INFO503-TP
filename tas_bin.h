#include <stdbool.h>
#include <stdio.h>

typedef struct {
    int val;
    FILE* monotonie;
} noeud;

typedef noeud* tas;



void ajouterTas(tas t, noeud nd);
/* procedure qui ajouter un element provenant d'une monotonie au tas à l'initialisation du tas*/

noeud retireMinTas(tas* t);
/* procedure qui retire le minimum du tas et le retourne, 
et remplace la racine par un nouvel element, le successeur de l'element sortant dans sa monotonie, 
puis celui-ci descend dans le tas pour être à la bonne place*/

bool estTasVide(tas t);


void afficherTas(tas t);
/* affiche les elements du tas*/

tas creerTas(int taille);

void libererTas(tas t); 
