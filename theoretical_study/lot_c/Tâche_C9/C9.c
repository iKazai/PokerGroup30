#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "C6.c"


void main_J2_incond(int* carte1_J2, int* carte2_J2)
{
    int carte1_J1, carte2_J1;
    main_J1(pioche, &carte1_J1, &carte2_J1);

    int* pioche_restante = retirer_cartes_J1(pioche, 6, carte1_J1, carte2_J1);

    int index1 = rand() % 4;
    *carte1_J2 = pioche_restante[index1];

    int index2 = rand() % 4;
    while (index2 == index1)
    {
        index2 = rand() % 4;
    }
    *carte2_J2 = pioche_restante[index2];

    free(pioche_restante);
}

double P_approx_2_main(int i_prime, int j_prime, int n)
{
    int count = 0;
    for (int k = 0; k < n; k++)
    {
        int carte1_J2, carte2_J2;
        main_J2_incond(&carte1_J2, &carte2_J2);

        if ((carte1_J2 == i_prime && carte2_J2 == j_prime) || (carte1_J2 == j_prime && carte2_J2 == i_prime))
        {
            count++;
        }
    }
    return (double)count / n;
}

double* P_approx_2(int n)
{
    double* t = malloc(sizeof(double) * 6); 
    int index = 0;
    for (int i_prime = 1; i_prime <= 3; i_prime++)
    {
        for (int j_prime = 1; j_prime <= 3; j_prime++)
        {
            t[index] = P_approx_2_main(i_prime, j_prime, n);
            index++;
        }
    }
    return t;
}