#include <stdio.h>
#include "header.h"
#define LEFT 1.0
#define RIGHT 10.0
#define N 100
#define ACC 0.000001

void funcd_bess(float x, float *f, float *df)
{
    *f = bessj0(x);
    *df = -bessj1(x);
}
void funcd_problem1(float x, float *f, float *df)
{
    *f = func1(x);
    *df = dfunc1(x);
}
void funcd_problem2(float x, float *f, float *df)
{
    *f = func2(x);
    *df = dfunc2(x);
}
void funcd_problem3(float x, float *f, float *df)
{
    *f = func3(x);
    *df = dfunc3(x);
}
void funcd_problem4(float x, float *f, float *df)
{
    *f = func4(x);
    *df = dfunc4(x);
}
void fileInit()
{
    FILE *fp;
    fp = fopen("csv/rtbis.csv", "w");
    fp = fopen("csv/rtflsp.csv", "w");
    fp = fopen("csv/rtsec.csv", "w");
    fp = fopen("csv/rtnewt.csv", "w");
    fp = fopen("csv/rtsafe.csv", "w");
    fp = fopen("csv/muller.csv", "w");
    fp = fopen("csv/problem1.csv", "w");
    fp = fopen("csv/problem2.csv", "w");
    fp = fopen("csv/problem3.csv", "w");
    fp = fopen("csv/problem4.csv", "w");
}
int main()
{
    fileInit();
    int nb;
    float xb1[10], xb2[10];
    double xbd1[10], xbd2[10];
    zbrak(bessj0, LEFT, RIGHT, N, xb1, xb2, &nb);

    printf("Bracketes:\n");
    for (int i = 1; i <= nb; i++)
    {
        printf("%f %f\n", xb1[i], xb2[i]);
    }

    printf("\nBisection method:\n");
    for (int i = 1; i <= nb; i++)
    {
        printf("%f\n", rtbis(bessj0, xb1[i], xb2[i], ACC));
    }
    printf("\nLinear interpolation method:\n");
    for (int i = 1; i <= nb; i++)
    {
        printf("%f\n", rtflsp(bessj0, xb1[i], xb2[i], ACC));
    }

    printf("\nSecant method:\n");
    for (int i = 1; i <= nb; i++)
    {
        printf("%f\n", rtsec(bessj0, xb1[i], xb2[i], ACC));
    }

    printf("\nNewton-Raphson method:\n");
    for (int i = 1; i <= nb; i++)
    {
        printf("%f\n", rtnewt(funcd_bess, xb1[i], xb2[i], ACC));
    }

    printf("\nNewton with bracketing method:\n");
    for (int i = 1; i <= nb; i++)
    {
        printf("%f\n", rtsafe(funcd_bess, xb1[i], xb2[i], ACC,"csv/rtsafe.csv"));
    }

    printf("\nMuller method:\n");
    for (int i = 1; i <= nb; i++)
    {
        printf("%f\n", muller(bessj0, xb1[i], xb2[i], (xb1[i] + xb2[i]) / 2, ACC));
    }

    printf("\nProblem1 with rtsafe.c:\n");
    printf("%f\n", rtsafe(funcd_problem1, 0.1, 1.0, ACC,"csv/problem1.csv"));

    // 완전제곱식 형태를 풀어서 해결
    printf("\nProblem2 with rtsafe.c:\n");
    printf("%f\n", rtsafe(funcd_problem2, 0.0, 1.0, ACC,"csv/problem2.csv"));

    printf("\nProblem3 with rtsafe.c:\n");
    printf("%f\n", rtsafe(funcd_problem3, -2.0, -1.0, ACC,"csv/problem3.csv"));

    printf("\nProblem4 with rtsafe.c:\n");
    printf("%f\n", rtsafe(funcd_problem4, 1, 2, ACC,"csv/problem4.csv"));

    return 0;
}