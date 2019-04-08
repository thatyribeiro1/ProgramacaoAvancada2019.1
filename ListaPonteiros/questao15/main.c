
#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main()
{
    int n = 0;

    // Entrada de valores
    printf("Digite o numero de elementos e aperte enter para confirmar: ");
    scanf("%d", &n);

    float* elementos = (float*)malloc( n* sizeof(float) );


    printf("Digite os elementos agora: ");

    for(int i=0; i<n; i++)
    {
        scanf("%f", &elementos[i]);
    }

    // Ordenação
    qsort(&elementos[0], n, sizeof(elementos[0]), cmpfunc);

    // Imprimir o vetor ordenado
    for(int i=0; i<n; i++)
    {
        printf("%f ", elementos[i]);
    }


    return 0;
}
