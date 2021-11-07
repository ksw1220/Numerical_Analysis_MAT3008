#include <stdio.h>
#include <math.h>
const int MAXIT = 100;

float div_diff2(float (*func)(float), float a, float b)
{
	return ((*func)(a) - (*func)(b)) / (a - b);
}

float div_diff3(float (*func)(float), float a, float b, float c)
{
	return (div_diff2(func, b, c) - div_diff2(func, a, b)) / (c - a);
}
float muller(float (*func)(float), float x0, float x1, float x2, float xacc)
{
	FILE *fp;
	fp = fopen("csv/muller.csv", "a+");
	void nrerror(char error_text[]);
	int j;
	float x3, dx, w, s_delta, denoms, swap;

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
		fprintf(fp, "%f,", x2);
		if (fabs(dx) < xacc || (*func)(x2) == 0.0)
		{
			fprintf(fp, "\n");
			return x2;
		}
	}
	nrerror("Maximum number of iterations exceeded in muller");
	return 0.0;
}
#undef MAXIT