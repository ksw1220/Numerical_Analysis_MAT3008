#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "header.h"

void printM(float **A, int n, int m)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            printf("%f ", A[i][j]);
        }
        printf("\n");
    }
}

void solution(FILE *fp)
{
    char buffer[100];
    char *tok;
    int N, M, row = 0, col = 1;
    float **A, **B;
    // gaussj를 위한 변수들
    float **A_gau, **B_gau;
    // ludcmp를 위한 변수들
    float **A_lud, *B_lud, d_lud;
    int *indx_lud;
    // svdcmp를 위한 변수들
    float **A_svd, *B_svd, *W_svd, **V_svd;
    // mprove를 위한 변수들
    float **A_mpr, **A_lud_mpr, *B_mpr, *x_mpr, d_mpr;
    int *indx_mpr;
    // filepointer를 통해 .dat파일을 읽고, 배열의 크기를 동적할당하고,
    // 알맞게 행렬에 데이터를 삽입한다.
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        if (row == 0)
        {
            tok = strtok(buffer, "\t");
            N = atoi(tok);
            tok = strtok(NULL, "\t");
            M = atoi(tok);
            A = (float **)malloc(sizeof(float *) * N + 1);
            A_gau = (float **)malloc(sizeof(float *) * N + 1);
            A_lud = (float **)malloc(sizeof(float *) * N + 1);
            A_svd = (float **)malloc(sizeof(float *) * N + 1);

            B = (float **)malloc(sizeof(float *) * N + 1);
            B_gau = (float **)malloc(sizeof(float *) * N + 1);
            B_lud = (float *)malloc(sizeof(float) * N + 1);

            B_svd = (float *)malloc(sizeof(float) * N + 1);
            W_svd = (float *)malloc(sizeof(float) * N + 1);
            V_svd = (float **)malloc(sizeof(float *) * N + 1);

            A_mpr = (float **)malloc(sizeof(float *) * N + 1);
            A_lud_mpr = (float **)malloc(sizeof(float *) * N + 1);

            B_mpr = (float *)malloc(sizeof(float) * N + 1);
            x_mpr = (float *)malloc(sizeof(float) * N + 1);
            W_svd = (float *)malloc(sizeof(float) * N + 1);
            indx_mpr = (int *)malloc(sizeof(int) * N + 1);
            for (int i = 0; i <= N; i++)
            {
                A[i] = (float *)malloc(sizeof(float) * N + 1);
                A_gau[i] = (float *)malloc(sizeof(float) * N + 1);
                A_lud[i] = (float *)malloc(sizeof(float) * N + 1);
                A_svd[i] = (float *)malloc(sizeof(float) * N + 1);
                A_mpr[i] = (float *)malloc(sizeof(float) * N + 1);
                A_lud_mpr[i] = (float *)malloc(sizeof(float) * N + 1);
                B[i] = (float *)malloc(sizeof(float) * 2);
                B_gau[i] = (float *)malloc(sizeof(float) * 2);
                V_svd[i] = (float *)malloc(sizeof(float) * 2);
            }
        }
        else if (row == N + 1)
        {
            tok = strtok(buffer, "\t");
            for (row = 1; row <= N; row++)
            {
                float num = atof(tok);
                if (num == 0 && strlen(tok) == 2)
                    break;

                B[row][1] = num;
                tok = strtok(NULL, "\t");
            }
        }
        else
        {
            tok = strtok(buffer, "\t");
            for (col = 1; col <= N; col++)
            {
                float num = atof(tok);
                if (num == 0 && strlen(tok) == 2)
                    break;

                A[row][col] = num;
                tok = strtok(NULL, "\t");
            }
        }
        row++;
    }

    // copy
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            A_gau[i][j] = A_lud[i][j] = A_svd[i][j] = A_mpr[i][j] = A_lud_mpr[i][j] = A[i][j];
        }
        B_gau[i][1] = B_lud[i] = B_svd[i] = B_mpr[i] = B[i][1];
    }
    // gaussj.c를 통한 풀이
    // gaussj.c 함수를 거쳐
    // A_gau에는 input A_gau의 inverse matrix가 output으로 저장되고,
    // B_gau에는 input B_gau에서 solution matrix인 x로 output으로 저장된다.
    // 따라서 B_gau의 1번째 col을 출력하는 것이 solution이다.
    gaussj(A_gau, N, B_gau, 1);
    printf("\n\ngauss\n");
    printf("--------------\n");
    for (int i = 1; i <= N; i++)
    {
        printf("%f ", B_gau[i][1]);
    }

    // ludcmp.c를 통한 풀이
    // ludcmp.c 함수를 거쳐
    // A_lud에는 decomposition된 output이 저장되고,
    // indx_lud에는 partial pivoting에 영향을 준 row들이 output으로 저장되고,
    // d_lud에는 row interchanges가 even이라면 1이, odd라면 -1이 저장된다.
    ludcmp(A_lud, N, indx_lud, &d_lud);
    // ludcmp의 output으로 얻어낸 배열과 함수들을 lubksb에 넣어 solution을 구한다.
    // B_lud에 solution matrix가 output으로 저장되고 이를 출력한다.
    lubksb(A_lud, N, indx_lud, B_lud);

    printf("\n\nludcmp\n");
    printf("--------------\n");
    for (int i = 1; i <= N; i++)
    {
        printf("%f ", B_lud[i]);
    }
    printf("\n");

    // svdcmp를 통한 풀이
    // A = U dot W dot V(transpose)
    // svdcmp함수를 거쳐 A_svd가 decompostion된다.
    // A_svd에는 U가 output으로 저장되고,
    // W_svd에는 diagonal single matrix가 저장되고,
    // V_svd에는 V matrix가 저장된다. 하지만 이는 transpose된 결과가 아니다.
    svdcmp(A_svd, N, N, W_svd, V_svd);
    printf("\n\nsvdcmp\n");
    printf("--------------\n");
    // svdcmp를 통해 얻어낸 결과들로 solution을 구하기 위한
    // svdsol 함수를 정의하여 사용하였다.
    // x = V dot [diag(1/w)] dot (U(transpose) dot b)
    // 위의 식처럼 x를 구하기 위한 과정을 함수에 구현하였다
    // svdsol의 결과로 solution matrix가 B_svd에 저장된다.
    svdsol(V_svd, N, W_svd, A_svd, B_svd);
    for (int i = 1; i <= N; i++)
    {
        printf("%f ", B_svd[i]);
    }

    // mprove를 통한 풀이
    // ludcmp를 통해 필요한 값들을 얻어낸 뒤 mprove함수를 실행한다.
    printf("\n\nmprove\n");
    printf("--------------\n");
    ludcmp(A_lud_mpr, N, indx_mpr, &d_mpr);

    // ludcmp를 통해 decompostino된 값은 A_lud_mpr이다.
    // mprove 함수의 실행 결과
    // x_mpr에 solution matrix가 저장된다.
    mprove(A_mpr, A_lud_mpr, N, indx_mpr, B_mpr, x_mpr);
    for (int i = 1; i <= N; i++)
    {
        printf("%f ", x_mpr[i]);
    }

    // A의 inverse matrix
    // gaussj의 실행 결과로 A_gau에는 inverse matrix가 저장되므로 이를 출력한다.
    printf("\n\ninverse of A\n");
    printf("--------------\n");
    printM(A_gau, N, N);

    // A의 determinant
    // ludcmp를 통해 얻어 낸 d_lud값과, A_lud의 diagonal 성분을 곱하여 det를 얻어낸다
    printf("\n\ndeterminant of A\n");
    printf("--------------\n");
    for (int j = 1; j <= N; j++)
    {
        d_lud *= A_lud[j][j];
    }
    printf("%f\n", d_lud);
    for (int i = 0; i <= N; i++)
    {
        free(A[i]);
        free(B[i]);
        free(A_gau[i]);
        free(B_gau[i]);
        free(A_lud[i]);
        free(A_svd[i]);
        free(V_svd[i]);
        free(A_mpr[i]);
        free(A_lud_mpr[i]);
    }
    free(A);
    free(B);
    free(A_gau);
    free(A_lud);
    free(B_lud);
    free(A_svd);
    free(B_svd);
    free(W_svd);
    free(V_svd);
    free(B_mpr);
    free(x_mpr);
    free(indx_mpr);
}
int main()
{
    FILE *fp;

    fp = fopen("hw5_data/lineq2.dat", "r");
    if (fp == NULL)
    {
        printf("There is no %s", "lineq2.dat");
        exit(1);
    }
    else
    {
        solution(fp);
        fclose(fp);
    }
    return 0;
}