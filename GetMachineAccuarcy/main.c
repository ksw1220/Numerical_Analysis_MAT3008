#include <stdio.h>
#include "header.h"
int main()
{
    int ibeta, it, irnd, ngrd, machep, negep, iexp, minexp, maxexp;
    // float를 위한 변수들
    float eps_f, epsneg_f, xmin_f, xmax_f;
    // double을 위한 변수들
    double eps_d, epsneg_d, xmin_d, xmax_d;

    //machar in float
    macharFloat(&ibeta, &it, &irnd, &ngrd, &machep, &negep, &iexp, &minexp, &maxexp, &eps_f, &epsneg_f, &xmin_f, &xmax_f);
    printf("machar in float\n");
    printf("eps: %e\n\n", eps_f);

    //machar in double
    macharDouble(&ibeta, &it, &irnd, &ngrd, &machep, &negep, &iexp, &minexp, &maxexp, &eps_d, &epsneg_d, &xmin_d, &xmax_d);

    printf("machar in double\n");
    printf("eps: %e\n\n", eps_d);
    // get_eps_float를 위한 변수

    printf("get_eps in float\n");
    get_eps_float(&it, &eps_f);
    printf("eps: %e\n\n", eps_f);

    //machar in double
    printf("get_eps in double\n");
    get_eps_double(&it, &eps_d);
    printf("eps: %e\n\n", eps_d);
    return 0;
}