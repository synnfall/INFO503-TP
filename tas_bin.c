#include "tas_bin.h"
#include <stdlib.h>
#include <stdio.h>


void ajouterTas(tas t, noeud nd)
{   
    t[0].val++; // on incrémente le nombre de noeud dans le tas
    int p = t[0].val; // on récupère l'indice du dernier noeud
    t[p] = nd; // on ajoute le noeud à la fin du tas
    int i = p; 
    while (i > 1 && t[i/2].val > t[i].val) 
    //tant que le parent est plus grand que le noeud ajouté on remonte le noeud
    {
        noeud tmp = t[i]; //permutation du noeud avec son parent
        t[i] = t[i/2];
        t[i/2] = tmp;
        i = i/2;
    }    
}


noeud retireMinTas(tas* t)
{
    if (*t==NULL)
    {
        exit(EXIT_FAILURE);
    }
    
    noeud* tableau = *t;
    noeud res = tableau[1];

    int* indice_c = &(tableau[0].val);
    
    if (fscanf(res.monotonie, "%d\n",&tableau[1].val) == EOF)
    {
        // si on a EOF alors la monotonie est vide

        (*indice_c)--; // on prend la dernière case 
        if (*indice_c > 0)
        {
            tableau[1] = tableau[*indice_c + 1];
        }
        // Sinon la taille du tas est a 1 alors il n'y a plus qu'une seule monotonie non vide
        // or on vient de la vider ainsi on a finis la fusion
    }

    if (*indice_c > 0)
    {
        //maintenant on fait descendre cette racine si necessaire pour que la tas
        //respecte ses propriétés
        int indice_parcours = 1;
        int fg = indice_parcours*2;
        int fd = indice_parcours*2 + 1;
        int taille = *indice_c + 1;
        while ((fg < taille && tableau[fg].val<tableau[indice_parcours].val) || (fd < taille && tableau[fd].val<tableau[indice_parcours].val))
        {
            int indice_a_echanger;
            if (tableau[fg].val<tableau[indice_parcours].val)
            {
                //le fils gauche est plus petit que la racine.
                if (fd < taille && tableau[fg].val>tableau[fd].val)
                {
                    //alors le fils droit existe donc on l'echange avec le plus petit des fils qui la est le fils droit
                    indice_a_echanger = fd;
                } else
                {
                    // le fils droit existe pas ou il est plus grand que le fils gauche donc on inverse le neud avec son fils gauche
                    indice_a_echanger = fg;
                }
            } else {
                // si le fils gauche est pas plus petit que le noeud courant alors c'est le fils droit qui l'est
                indice_a_echanger = fd;
            }

            // on fait l'echange avec le fils
            noeud temps = tableau[indice_a_echanger];
            tableau[indice_a_echanger] = tableau[indice_parcours];
            tableau[indice_parcours] = temps;

            //on a un nouveau noeud courant
            indice_parcours = indice_a_echanger;

            fg = indice_parcours*2;
            fd = indice_parcours*2+1;
        }
    }
    
    return res;
}

bool estTasVide(tas t)
{
    return t[0].val == 0;
}

void afficheTasHorizontal(tas t, int pos, int ecart)
{
    if (pos > t->val)
    {
        return;
    }
    afficheTasHorizontal(t,pos*2+1,ecart+1);
    for (int i = 0; i < ecart; i++)
    {
        printf("\t");
    }
    printf("%d\n", t[pos].val);
    afficheTasHorizontal(t,pos*2,ecart+1);
}

void afficherTas(tas t)
{
    afficheTasHorizontal(t, 3,1);
    printf("%d\n", t[1].val);
    afficheTasHorizontal(t, 2,1);
}

tas creerTas(int taille)
{
    tas t = (tas)malloc((taille+1)*sizeof(noeud));
    if (t == NULL)
    {
        fprintf(stderr, "Erreur d'allocation mémoire pour le tas\n");
        exit(EXIT_FAILURE);
    }
    t[0].val = 0;
    return t;
}

void libererTas(tas t)
{
    free(t);

}

