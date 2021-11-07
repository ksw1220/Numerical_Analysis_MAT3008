void gaussj(float **a, int n, float **b, int m);
void ludcmp(float **a, int n, int *indx, float *d);
void lubksb(float **a, int n, int *indx, float b[]);
void svdcmp(float **a, int m, int n, float w[], float **v);
void svdsol(float **V, int n, float *W, float **U, float *b);
void mprove(float **a, float **alud, int n, int indx[], float b[], float x[]);
