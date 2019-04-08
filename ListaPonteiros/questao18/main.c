#include <stdio.h>
#include <stdlib.h>

void add_vectores(float *vetor_a,float *vetor_b, float* vetor_c, int n_elements)
{
    for(int i=0; i < n_elements; i++)
    {
        vetor_c[i] = vetor_a[i] + vetor_b[i];
    }
}


int main()
{
    int n = 5;
    float *vetor1 = (float*) malloc(sizeof(float) * n);
    float *vetor2 = (float*) malloc(sizeof(float) * n);
    float *vetor3 = (float*) malloc(sizeof(float) * n);

    for(int i=0; i<n; i++)
    {
        float x = (float)rand()/(float)(RAND_MAX);
        vetor1[i] = x;
    }

    for(int i=0; i<n; i++)
    {
        float x = (float)rand()/(float)(RAND_MAX);
        vetor2[i] = x;
    }

    add_vectores(vetor1, vetor2, vetor3, n);

    printf("vec A: ");
    for(int i=0; i<n; i++)
    {
        printf("%f ", vetor1[i]);
    }

    printf("\nvec B: ");
    for(int i=0; i<n; i++)
    {
        printf("%f ", vetor2[i]);
    }

    printf("\nvec A+B: ");
    for(int i=0; i<n; i++)
    {
        printf("%f ", vetor3[i]);
    }

    return 0;
}
