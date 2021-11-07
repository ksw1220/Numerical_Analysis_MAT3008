
#include <math.h>
#include <stdio.h>
#define JMAX 20

float rtnewt(void (*funcd)(float, float *, float *), float x1, float x2,
			 float xacc)
{
	FILE *fp;
	fp = fopen("csv/rtnewt.csv", "a+");
	void nrerror(char error_text[]);
	int j;
	float df, dx, f, rtn;

	rtn = 0.5 * (x1 + x2);
	for (j = 1; j <= JMAX; j++)
	{
		(*funcd)(rtn, &f, &df);
		dx = f / df;
		rtn -= dx;
		fprintf(fp, "%f,", rtn);
		if ((x1 - rtn) * (rtn - x2) < 0.0)
			nrerror("Jumped out of brackets in rtnewt");
		if (fabs(dx) < xacc)
		{
			fprintf(fp, "\n");
			return rtn;
		}
	}
	nrerror("Maximum number of iterations exceeded in rtnewt");
	return 0.0;
}
#undef JMAX
