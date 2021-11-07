void get_eps_double(int *it, double *eps)
{
    double one = 1;
    double next = 1;
    *it = 0;
    while (1 + next - 1)
    {
        *eps = next;
        (*it)++;
        next /= 2;
    }
}