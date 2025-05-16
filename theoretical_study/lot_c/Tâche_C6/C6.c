#include<stdio.h>
#include<stdlib.h>
#include "C4.c"


int* retirer_cartes_J1(int* pioche_init, int taille, int i, int j) 
{
    int* res = malloc(sizeof(int) * (taille - 2));
    int count_i = 0;
    int count_j = 0;
    int index = 0;
    for (int k = 0; k < taille; k++) 
    {
        int carte = pioche_init[k];
        if (carte == i && count_i == 0) 
        {
            count_i++;
        }
        else if (carte == j && count_j == 0) 
        {
            count_j++;
        }
        else 
        {
            res[index++] = carte;
        }
    }
    return res;
}

void main_J2(int i, int j,int* carte1_J2,int* carte2_J2) 
{
    int* pioche_restante = retirer_cartes_J1(pioche, 6, i, j);

    int index1 = rand() % 4;
    *carte1_J2 = pioche_restante[index1];

    int index2 = rand() % 4;

    while (index2 == index1) 
    {
        index2 = rand() % 4;
    }
    *carte2_J2 = pioche_restante[index2];
    printf("J2 reçoit les cartes : %d et %d\n", *carte1_J2, *carte2_J2);
}

double P_approx_2_1_main(int i_prime, int j_prime, int i, int j, int n) 
{
    int count = 0;
    for (int k = 0; k < n; k++)
    {
        int carte1_J2;
        int carte2_J2;
        main_J2(i, j,&carte1_J2,&carte2_J2);
        if ((carte1_J2 == i_prime && carte2_J2 == j_prime) || (carte1_J2 == j_prime && carte2_J2 == i_prime)) 
        {
            count++;
        }
    }
    return (double)count / n;
}

double* P_approx_2_1(int i, int j, int n)
{
    double* t;
    t = malloc(sizeof(double) * 6);
    int index=0;
    for(int i_prime=1;i_prime<4;i_prime++)
    {
        for(int j_prime=1;j_prime<4;j_prime++)
        {

            t[index] = P_approx_2_1_main(i_prime,j_prime,i,j,n);
            index++;
        }
    }
    return t;
}

