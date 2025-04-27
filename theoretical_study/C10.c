#include "C9.c"
#include <stdlib.h>

double P_approx_2_1_alter(int i, int j, int n){
    double res = 0;
    for (int k = 1; k < 4; k++)
    {
        for (int l = 1; l < 4; l++)
        {
            res += P_approx_1(k,l,n) * P_approx_2_1(k,l,i,j,n);
        }
    }
    return res;
}

double* P_approx_2_alter(int n){
    double* res = (double*)malloc(sizeof(double) * 9);
    int index = 0;
    for (int k = 1; k < 4; k++)
    {
        for (int l = 1; l < 4; l++)
        {
            res[index++] = P_approx_2_1_alter(k,l,n);
        }
    }
    return res;
}