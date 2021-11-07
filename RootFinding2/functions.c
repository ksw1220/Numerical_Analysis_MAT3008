
#include <math.h>
#define PI 3.1415926
double funcR(double R)
{
    double ans, a, b, c;
    a = exp(-0.005 * R);
    b =sqrt(2000 - 0.01 * R * R) * 0.05;

    ans = a * cos(b) - 0.01;

    return ans;
}
double dfuncR(double R)
{
    double ans, a, b, c, d;
    a = -exp(-R / 200);
    b = sqrt(200000 - R * R);
    c = b * cos(b / 200) - R * sin(b / 200);

    return ans = a * c / b / 200;
}

double func32(double x)
{
    double ans, a, b;
    a = 3.59672 * x;
    b = (x * x + 0.81) * sqrt(x * x + 0.81);
    ans = 1 - a / b;

    return ans;
}
double func36(double x)
{
    double ans, a, b,c,d;
    a=1.0/1000.0;
    b=1.0/10000.0;
    ans = -0.20597+x*b*(1.671+x*b*(9.7215+x*a*(-9.5838+x*a*1.92520)));
    return ans;
}

#undef PI