#include <stdio.h>
#include "header.h"
#define LEFT1 0.0
#define RIGHT1 200.0
#define LEFT 0.0
#define RIGHT 400.0
#define N 100
#define ACC1 0.0001
#define ACC2 0.000001

void funcd_R(double x, double *f, double *df)
{
    *f = funcR(x);
    *df = dfuncR(x);
}

int main()
{

    printf("\nBisection method:\n");
    printf("root is: %lf\n", rtbis(funcR, LEFT, RIGHT, ACC1));
    printf("--------------------------\n");
    printf("root is: %lf\n", rtbis(funcR, LEFT, RIGHT, ACC2));
    printf("--------------------------\n");

    printf("\nLinear interpolation method:\n");
    printf("root is: %lf\n", rtflsp(funcR, LEFT, RIGHT, ACC1));
    printf("--------------------------\n");
    printf("root is: %lf\n", rtflsp(funcR, LEFT, RIGHT, ACC2));
    printf("--------------------------\n");

    printf("\nSecant method:\n");
    printf("root is: %lf\n", rtsec(funcR, LEFT, RIGHT, ACC1));
    printf("--------------------------\n");
    printf("root is: %lf\n", rtsec(funcR, LEFT, RIGHT, ACC2));
    printf("--------------------------\n");

    printf("\nNewton-Raphson method:\n");
    printf("root is: %lf\n", rtnewt(funcd_R, LEFT, RIGHT, ACC1));
    printf("--------------------------\n");
    printf("root is: %lf\n", rtnewt(funcd_R, LEFT, RIGHT, ACC2));
    printf("--------------------------\n");

    printf("\nNewton with bracketing method:\n");
    printf("root is: %lf\n", rtsafe(funcd_R, LEFT, RIGHT, ACC1));
    printf("--------------------------\n");
    printf("root is: %lf\n", rtsafe(funcd_R, LEFT, RIGHT, ACC2));
    printf("--------------------------\n");

    printf("\nMuller method:\n");
    printf("root is: %lf\n", muller(funcR, LEFT, RIGHT, (LEFT + RIGHT) / 2, ACC1));
    printf("--------------------------\n");
    printf("root is: %lf\n", muller(funcR, LEFT, RIGHT, (LEFT + RIGHT) / 2, ACC2));
    printf("--------------------------\n");

    int nb;
    double xb1[10], xb2[10];

    zbrak(func32, 0, 2, N, xb1, xb2, &nb);

    printf("\nProblem32 using secant method\n");
    for (int i = 1; i <= nb; i++)
    {
        printf("root is: %lf\n", rtsec(func32, xb1[i], xb2[i], ACC2));
        printf("--------------------------\n");
    }
    zbrak(func36, 0, 2000, N, xb1, xb2, &nb);

    printf("\nProblem36 using secant method\n");
    for (int i = 1; i <= nb; i++)
    {
        printf("root is: %lf\n", rtsec(func36, xb1[i], xb2[i], ACC2));
        printf("--------------------------\n");
    }
    return 0;
}