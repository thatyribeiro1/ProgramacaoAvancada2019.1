#include <stdio.h>
#include <stdlib.h>

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
    for(int i=0; i<n; i++)
    {
        float menorValor = elementos[i];
        int indiceMenor = i;
        for(int j=i+1; j<n; j++)
        {
            if(menorValor > elementos[j])
            {
                menorValor = elementos[j];
                elementos[j] = elementos[indiceMenor];
                elementos[indiceMenor] = menorValor;

            }
        }
    }

    // Imprimir vetor ordenado
    for(int i=0; i<n; i++)
    {
        printf("%f ", elementos[i]);
    }


    return 0;
}
