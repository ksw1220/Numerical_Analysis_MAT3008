void get_eps_float(int *it, float *eps)
{
    float one = 1;
    float next = 1;
    *it = 0;
    while (1 + next - 1)
    {
        *eps = next;
        (*it)++;
        next /= 2;
    }
}