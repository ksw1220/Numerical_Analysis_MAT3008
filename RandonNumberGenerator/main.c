#include <stdio.h>
#include "header.h"

int main()
{
    FILE *fp = fopen("random_number.csv", "w");

    long tmp;
    int numSamples = 100;
    
    // uniform dstribution
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < numSamples; j++)
        {
            // [-3,2] 구간에서의 uniform distibution을 위해 *5를 한 뒤 -3.0을 하였다.
            float randomNumber = ran0(&tmp) * 5 - 3.0;
            char buf[10];
            sprintf(buf, "%f", randomNumber);
            fputs(buf, fp);
            fputs(",", fp);
        }
        numSamples *= 10;
        fputs("\n", fp);
    }

    // gaussian distribution
    numSamples = 100;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < numSamples; j++)
        {
            // gasdev를 통해 N(0,1)인 정규분포를 따르는 샘플을 얻고
            // *1.5를 한 뒤 0.5를 더하여 N(0.5,1,5)인 정규분포를 따르는 샘플로 바꾸었다.
            float randomNumber = gasdev(&tmp) * 1.5 + 0.5;
            char buf[10];
            sprintf(buf, "%f", randomNumber);
            fputs(buf, fp);
            fputs(",", fp);
        }
        numSamples *= 10;
        fputs("\n", fp);
    }

    fclose(fp); // 파일 포인터 닫기
}
