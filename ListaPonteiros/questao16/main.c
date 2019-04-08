int cmpfunc (float a, float b) {
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
    mySort(elementos, n, cmpfunc);

    // Imprimi vetor ordenado
    for(int i=0; i<n; i++)
    {
        printf("%f ", elementos[i]);
    }


    return 0;
}
