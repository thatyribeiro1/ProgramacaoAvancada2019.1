#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int mycmpfunc (float a, float b) {
   return (a > b);
}

void mySort(float *base, unsigned int nitems, int (*compar)(float, float) )
{
    for(int i=0; i < nitems; i++)
    {
        float menorValor = base[i];
        int indiceMenor = i;
        for(int j=i+1; j<nitems; j++)
        {
            if( compar(menorValor, base[j]) )
            {
                menorValor = base[j];
                base[j] = base[indiceMenor];
                base[indiceMenor] = menorValor;
            }
        }
    }
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main()
{
    int n = 20000;
    float* elementos = (float*)malloc( n* sizeof(float) );
    float* elementos2 = (float*)malloc( n* sizeof(float) );

    clock_t start1, end1, start2, end2;
    double cpu_time_used1, cpu_time_used2;

    // fill randomly the vector
    for(int i=0; i<n; i++)
    {
        float x = (float)rand()/(float)(RAND_MAX);
        elementos[i] = x;
        elementos2[i] = x;
    }

    start1 = clock();
    qsort(&elementos[0], n, sizeof(elementos[0]), cmpfunc);
    end1 = clock();

    start2 = clock();
    mySort(elementos2, n, mycmpfunc);
    end2 = clock();

    cpu_time_used1 = ((double) (end1 - start1)) / CLOCKS_PER_SEC;
    cpu_time_used2 = ((double) (end2 - start2)) / CLOCKS_PER_SEC;

    printf("qsort execution time: %lf\n", cpu_time_used1);
    printf("mysort execution time: %lf\n", cpu_time_used2);

    return 0;
}
