#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tas_bin.h"
#define NB_MONOTONIE 10


int main()
{
    FILE* f1 = fopen("./monotonies/monotonie_1.txt", "r");
    FILE* f2 = fopen("./monotonies/monotonie_2.txt", "r");
    FILE* f3 = fopen("./monotonies/monotonie_3.txt", "r");
    FILE* f4 = fopen("./monotonies/monotonie_4.txt", "r");
    FILE* f5 = fopen("./monotonies/monotonie_5.txt", "r");
    FILE* f6 = fopen("./monotonies/monotonie_6.txt", "r");
    FILE* f7 = fopen("./monotonies/monotonie_7.txt", "r");
    FILE* f8 = fopen("./monotonies/monotonie_8.txt", "r");
    FILE* f9 = fopen("./monotonies/monotonie_9.txt", "r");
    FILE* f10 = fopen("./monotonies/monotonie_10.txt", "r");

    FILE* cible = fopen("./res.txt", "w");
    if (!f1 || !f2 || !f3 || !f4 || !f5 || !f6 || !f7 || !f8 || !f9 || !f10 || !cible)
    {
        printf("Erreur lors de l'ouverture des fichiers");
        exit(EXIT_FAILURE);
    }
    
    noeud n1;
    noeud n2;
    noeud n3;
    noeud n4;
    noeud n5;
    noeud n6;
    noeud n7;
    noeud n8;
    noeud n9;
    noeud n10;
    n1.monotonie = f1;
    n2.monotonie = f2;
    n3.monotonie = f3;
    n4.monotonie = f4;
    n5.monotonie = f5;
    n6.monotonie = f6;
    n7.monotonie = f7;
    n8.monotonie = f8;
    n9.monotonie = f9;
    n10.monotonie = f10;

    tas t = creerTas(NB_MONOTONIE);
    // si il n'y a pas d'élément a traiter dans une monotonie
    // on l'ajoute pas au tas
    if (fscanf(f1, "%d", &n1.val) == 1) ajouterTas(t, n1);
    if (fscanf(f2, "%d", &n2.val) == 1) ajouterTas(t, n2);
    if (fscanf(f3, "%d", &n3.val) == 1) ajouterTas(t, n3);
    if (fscanf(f4, "%d", &n4.val) == 1) ajouterTas(t, n4);
    if (fscanf(f5, "%d", &n5.val) == 1) ajouterTas(t, n5);
    if (fscanf(f6, "%d", &n6.val) == 1) ajouterTas(t, n6);
    if (fscanf(f7, "%d", &n7.val) == 1) ajouterTas(t, n7);
    if (fscanf(f8, "%d", &n8.val) == 1) ajouterTas(t, n8);
    if (fscanf(f9, "%d", &n9.val) == 1) ajouterTas(t, n9);
    if (fscanf(f10, "%d", &n10.val) == 1) ajouterTas(t, n10);
    
    while (!estTasVide(t))
    {
        afficherTas(t);
        noeud sortie = retireMinTas(&t);
        fprintf(cible, "%d\n", sortie.val);
    }
    
    
    return 0;
}