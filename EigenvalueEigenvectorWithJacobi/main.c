#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "nrutil.h"
int main()
{
    int nrot, n = 11;
    float *d = vector(1, n);
    float *r = vector(1, n);
    float **v = matrix(1, n, 1, n);
    float **a = matrix(1, n, 1, n);
    long tmp;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            a[i][j] = gasdev(&tmp);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            a[i][j] = a[j][i];
        }
    }

    printf("symmetric matrix\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%f ", a[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    jacobi(a, n, d, v, &nrot);
    eigsrt(d, v, n);
    printf("\n");
    for (int i = 1; i <= n; i++)
    {

        printf("eigenvalue: %f\n", d[i]);
        printf("eigenvector\n");

        for (int j = 1; j <= n; j++)
        {
            printf("%f ", v[i][j]);
        }
        printf("\n\n");
    }
    free_matrix(v, 1, n, 1, n);
    free_matrix(a, 1, n, 1, n);
    free_vector(r, 1, n);
    free_vector(d, 1, n);
    return 0;
}