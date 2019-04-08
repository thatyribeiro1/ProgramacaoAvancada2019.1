#include <stdio.h>

int main()
{
    char vetor1[10];
    int vetor2[10];
    float vetor3[10];
    double vetor4[10];
    char *x1;
    int *x2;
    float *x3;
    double *x4;

    printf("Vetor do tipo char\n\n");
    x1 = vetor1;
    printf("Posicao de memoria do vetor: %p!\n", x1);
    //x1+1
    x1 = x1 + 1;
    printf("Posicao de memoria do vetor: %p!\n", x1);
    //x1+2
    x1 = x1 + 1;
    printf("Posicao de memoria do vetor: %p!\n\n", x1);
    //x1+3
    x1 = x1 + 1;

    printf("Vetor do tipo int\n\n");

    x2 = vetor2;
    printf("Posicao de memoria do vetor: %p!\n", x2);
    //x2+1
    x2 = x2 + 1;
    printf("Posicao de memoria do vetor: %p!\n", x2);
    //x2+2
    x2 = x2 + 1;
    printf("Posicao de memoria do vetor: %p!\n\n", x2);
    //x2+3
    x2 = x2 + 1;

    printf("Vetor do tipo float\n\n");

    x3 = vetor2;
    printf("Posicao de memoria do vetor: %p!\n", x3);
    //x3+1
    x3 = x3 + 1;
    printf("Posicao de memoria do vetor: %p!\n", x3);
    //x3+2
    x3 = x3 + 1;
    printf("Posicao de memoria do vetor: %p!\n\n", x3);
    //x3+3
    x3 = x3 + 1;

    printf("Vetor do tipo double\n\n");

    x4 = vetor2;
    printf("Posicao de memoria do vetor: %p!\n", x4);
    //x4+1
    x4 = x4 + 1;
    printf("Posicao de memoria do vetor: %p!\n", x4);
    //x4+2
    x4 = x4 + 1;
    printf("Posicao de memoria do vetor: %p!\n", x4);
    //x4+3
    x4 = x4 + 1;





}
