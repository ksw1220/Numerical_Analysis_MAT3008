void zbrak(double (*fx)(double), double x1, double x2, int n, double xb1[],
		   double xb2[], int *nb);
double rtbis(double (*func)(double), double x1, double x2, double xacc);
double rtflsp(double (*func)(double), double x1, double x2, double xacc);
double rtsec(double (*func)(double), double x1, double x2, double xacc);
double rtnewt(void (*funcd)(double, double *, double *), double x1, double x2,
             double xacc);
double rtsafe(void (*funcd)(double, double *, double *), double x1, double x2,
             double xacc);
double muller(double (*func)(double), double x0, double x1, double x2, double xacc);
double funcR(double x);
double dfuncR(double x);
double func32(double x);
double func36(double x);
void nrerror(char error_text[]);