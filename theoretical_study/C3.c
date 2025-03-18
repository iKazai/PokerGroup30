#include<stdio.h>
#include<stdlib.h>

void distrib(int* pioche,int* carte1, int* carte2) {
    srand(time(NULL));
    int index1 = rand() % 6;
    *carte1 = pioche[index1];
    int index2;
     while (index2 == index1) {
        index2 = rand() % 6;
    };
    *carte2 = pioche[index2];
}

void main_J1(int* pioche)
{
    int carte1;
    int carte2;
    distrib(pioche,&carte1, &carte2);
    printf("J1 reçoit les cartes : %d et %d\n", carte1, carte2);
}

double P_approx_1(int i,int j, int* pioche, int n) 
{
    int count=0;
    for(int k=0;k<n;k++)
    {
        int carte1, carte2;
        main_J1(pioche);
        if ((carte1 == i && carte2 == j) || (carte1 == j && carte2 == i))
        {
            count++;
        }
    }
    return (double)count/n;
}

double* P_approx_1_n(int* pioche, int n) {
    double* t;
    t = malloc(sizeof(double) * 9);
    int count=0;
    for(int i=1;i<4;i++)
    {
        for(int j=1;j<4;j++)
        {

            t[count] = P_approx_1(i,j,pioche,n);
            count++;
        }
    }
    return t;
}
