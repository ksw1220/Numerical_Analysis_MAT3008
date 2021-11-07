void macharFloat(int *ibeta, int *it, int *irnd, int *ngrd, int *machep, int *negep,
                 int *iexp, int *minexp, int *maxexp, float *eps, float *epsneg,
                 float *xmin, float *xmax);

void macharDouble(int *ibeta, int *it, int *irnd, int *ngrd, int *machep, int *negep,
                  int *iexp, int *minexp, int *maxexp, double *eps, double *epsneg,
                  double *xmin, double *xmax);

void get_eps_double(int *it, double *eps);

void get_eps_float(int *it, float *eps);