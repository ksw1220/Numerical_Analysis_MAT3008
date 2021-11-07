void zbrak(float (*fx)(float), float x1, float x2, int n, float xb1[],
           float xb2[], int *nb);
float bessj0(float x);
float bessj1(float x);
float rtbis(float (*func)(float), float x1, float x2, float xacc);
float rtflsp(float (*func)(float), float x1, float x2, float xacc);
float rtsec(float (*func)(float), float x1, float x2, float xacc);
float rtnewt(void (*funcd)(float, float *, float *), float x1, float x2,
             float xacc);
float rtsafe(void (*funcd)(float, float *, float *), float x1, float x2,
             float xacc, char *filename);
float muller(float (*func)(float), float x0, float x1, float x2, float xacc);
float func1(float x);
float dfunc1(float x);
float func2(float x);
float dfunc2(float x);
float func3(float x);
float dfunc3(float x);
float func4(float x);
float dfunc4(float x);
void nrerror(char error_text[]);