#include <stdlib.h>
#include <stdio.h>

#include "double_tas.h"

doubleTas creerDoubleTas(int taille)
{
    int* res = malloc(sizeof(int)*(taille+2));
    if (res == NULL)
    {
        fprintf(stderr, "Erreur d'allocation mémoire pour le double tas\n");
        exit(EXIT_FAILURE);
    }
    *res = 1; // (a) La racine de l’arbre ne contient aucun élément
    return res;
}

bool estDoubleTasVide(doubleTas t)
{
    return *t<=1;
}

void libererDoubleTas(doubleTas* t)
{
    free(*t);
    *t = NULL;
}

int ecartTasSymetrique(int pos)
{
    int res = 1;
    while (pos > 3)
    {
        pos /= 2;
        res *= 2;
    }
    return res;
}

bool estAGauche(int pos)
{
    // on regarde le premier père après la racine pour savoir si le tas est a gauche ou a droite
    while (pos > 3)
    {
        pos = pos / 2;
    }
    return pos==2;
}

void swap(int* val1, int* val2)
{
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

void reorganiseDoubleTasBin(doubleTas t, bool estGauche, int position_tab)
{
    if (estGauche)
    {
        while (position_tab > 2 && t[position_tab / 2] > t[position_tab])
        {
            swap(&(t[position_tab]), &(t[position_tab / 2]));

            position_tab /= 2;
        }
    } else {
        while (position_tab > 3 && t[position_tab / 2] < t[position_tab])
        {
            swap(&(t[position_tab]), &(t[position_tab / 2]));

            position_tab /= 2;
        }
    }
    
}

void ajouterDoubleTas(doubleTas t, int valeur)
{
    int position_tab = ++(*t); // on augement la taille de tableau car on va ajouter un élément

    t[position_tab] = valeur;

    bool estGauche = estAGauche(position_tab);
    int distanceAuteTasDansListe = ecartTasSymetrique(position_tab);

    if (position_tab == 2)
    {
        //On insere le premier element si on est ici donc il est forcément bien placé
        return;
    }
    

    if (estGauche)
    {
      int m = position_tab + distanceAuteTasDansListe;
      
      int posSymetrique;
      if (m <= *t)
      {
        posSymetrique = m;
      } else {
        posSymetrique = m / 2; // si le fils n'existe pas on prend le père alors
      }

      if (t[position_tab] > t[posSymetrique])
      {
        swap(&(t[position_tab]), &(t[posSymetrique]));

        //Alors on doit après réorganiser l'autre tas donc on inverse les positions
        position_tab = posSymetrique;
        estGauche = false;
      }
      //Sinon on doit justement réorgniser ce tas
      
    } else {
        int l = position_tab - distanceAuteTasDansListe;

        if (t[l] > t[position_tab])
        {
            swap(&(t[position_tab]), &(t[l]));

            //Alors on doit après réorganiser l'autre tas donc on inverse les positions
            position_tab = l;
            estGauche = true;
        }
        //Sinon on doit justement réorgniser ce tas
    }
    
    //Réorganisation du tas
    reorganiseDoubleTasBin(t,estGauche,position_tab);
}

void afficheTasHorizontal(doubleTas t, int pos, int ecart)
{
    if (pos > *t)
    {
        return;
    }
    afficheTasHorizontal(t,pos*2+1,ecart+1);
    for (int i = 0; i < ecart; i++)
    {
        printf("\t");
    }
    printf("%d\n", t[pos]);
    afficheTasHorizontal(t,pos*2,ecart+1);
}

void afficheDoubleTas(doubleTas t)
{
    afficheTasHorizontal(t,3,1);
    printf("\n");
    afficheTasHorizontal(t,2,1);
}