
#include <math.h>
#define PI 3.1415926
float func1(float x)
{
    float ans, a, b;
    a = 10 * exp(-x);
    b = sin(2 * PI * x);
    ans = a * b - 2;

    return ans;
}

float dfunc1(float x)
{
    float ans, a, b, c;
    a = -1 * exp(-x);
    b = 10 * sin(2 * PI * x);
    c = -20 * PI * cos(2 * PI * x);
    ans = a * (b + c);

    return ans;
}
float func2(float x)
{
    float ans, a;
    a = x - exp(-x);
    ans = a;

    return ans;
}

float dfunc2(float x)
{
    float ans, a;
    a = 1 + exp(-x);
    ans = a;

    return ans;
}

float func3(float x)
{
    float ans, a, b;
    a = cos(x + sqrt(2));
    b = x * (x / 2 + sqrt(2));
    ans = a + b;

    return ans;
}

float dfunc3(float x)
{
    float ans, a, b;
    a = -sin(x + sqrt(2));
    b = x + sqrt(2);
    ans = a + b;

    return ans;
}

float func4(float x)
{
    float ans, a, b;
    a = tan(x) - exp(x) + 1;
    ans = a;

    return ans;
}

float dfunc4(float x)
{
    float ans, a, b;
    a = 1 / cos(x) / cos(x);
    b = -exp(x);
    ans = a + b;
    return ans;
}

#undef PI