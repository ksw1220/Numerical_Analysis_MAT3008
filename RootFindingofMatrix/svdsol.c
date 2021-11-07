#include <math.h>
#include <stdio.h>
void svdsol(float **V, int n, float *W, float **U, float *b)
{

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (W[j] != 0.0)
                V[i][j] /= W[j];
            else
                V[i][j] = 0.0;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        float tmp = 0.0;
        for (int j = 1; j <= n; j++)
        {
            tmp += U[j][i] * b[j];
        }
        W[i] = tmp;
    }

    for (int i = 1; i <= n; i++)
    {
        float tmp = 0;
        for (int j = 1; j <= n; j++)
        {
            tmp += V[i][j] * W[j];
        }
        b[i] = tmp;
    }
}