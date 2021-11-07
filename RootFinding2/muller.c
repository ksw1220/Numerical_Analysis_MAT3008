#include <stdio.h>
#include <math.h>
const int MAXIT = 100;

double div_diff2(double (*func)(double), double a, double b)
{
	return ((*func)(a) - (*func)(b)) / (a - b);
}

double div_diff3(double (*func)(double), double a, double b, double c)
{
	return (div_diff2(func, b, c) - div_diff2(func, a, b)) / (c - a);
}
double muller(double (*func)(double), double x0, double x1, double x2, double xacc)
{
	void nrerror(char error_text[]);
	int j;
	double x3, dx, w, s_delta, denoms, swap;

	for (j = 1; j <= MAXIT; j++)
	{
		w = div_diff2(func, x2, x1) + div_diff2(func, x2, x0) - div_diff2(func, x2, x1);
		s_delta = sqrt(w * w - 4 * (*func)(x2)*div_diff3(func, x2, x1, x0));

		denoms = fabs(w + s_delta) > fabs(w - s_delta) ? w + s_delta : w - s_delta;
		x3 = x2 - 2 * (*func)(x2) / denoms;

		x0 = x1;
		x1 = x2;
		x2 = x3;
		dx = x2 - x1;
		if (fabs(dx) < xacc || (*func)(x2) == 0.0)
		{
			printf("%d iterations\n",j);
			return x2;
		}
	}
	nrerror("Maximum number of iterations exceeded in muller");
	return 0.0;
}
#undef MAXIT