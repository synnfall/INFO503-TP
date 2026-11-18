#include "double_tas.h"

#include <stdio.h>

int main()
{
    int valeurs_test[] = {50, 10, 25, 25, 80, 5, -5, 40, 99};
    int nb = 9;

    doubleTas t = creerDoubleTas(nb);

    for (int i = 0; i < nb; i++)
    {
        printf("Ajout de %d\n", valeurs_test[i]);
        ajouterDoubleTas(t, valeurs_test[i]);
        afficheDoubleTas(t);
        printf("\n");
    }

    libererDoubleTas(&t);
    return 0;
}