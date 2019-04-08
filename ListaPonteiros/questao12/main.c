#include <stdio.h>

int main()
{
    float aloha[10], coisas[10][5], *pf, value = 2.2;
    char aloha2[10]="value";
    int i=3;


//------------------------------------------------------------------a-----------------------------------------------------------------------------------------

    aloha[2] = value; //irá funcionar
    printf("ITEM A\n\n");
    printf("Posicao 2: %f\n\n", aloha[2]);


//------------------------------------------------------------------b-----------------------------------------------------------------------------------------

    printf("ITEM B\n\n");
    scanf("%f", &aloha);//irá funcionar

    printf("Posicao 0: %f\n\n", aloha[0]);

//------------------------------------------------------------------c-----------------------------------------------------------------------------------------

    printf("ITEM C\n\n");
    //aloha = "value"; //não irá funcionar pois nao é possivel atribuir valores a este array sem explicitar em qual posicao do array ele deve ficar.
    //Além disso, a array é do tipo float e o programa está tentando armazenar uma string nela
    printf("Posicao 0: %f\n\n", aloha[0]);
    printf("String correta: %s\n\n", aloha2);

//------------------------------------------------------------------d-----------------------------------------------------------------------------------------

    printf("ITEM D\n\n");
    printf("%.1f\n", aloha);//ira funcionar

//------------------------------------------------------------------e-----------------------------------------------------------------------------------------

    printf("ITEM E\n\n");
    aloha[3] = 5.5;
    coisas[4][4] = aloha[3];//ira funcionar
    printf("Valor da posicao 3 de aloha: %f\n\n", coisas[4][4]);

//------------------------------------------------------------------f-----------------------------------------------------------------------------------------

//    coisas[5] = aloha;//nao vai funcionar pois coisas é uma matriz, portanto precisa de dois argumentos. O compilador interpreta coisas[5] como uma array. Além disso,
//    //a posicao do array aloha também deveria ser explicitada

//------------------------------------------------------------------g-----------------------------------------------------------------------------------------

    printf("ITEM G\n\n");
//    pf = value;//nao ira funcionar, pois o valor de uma variavel float nao pode ser atribuido a um ponteiro, somente um endereco. Ver linha abaixo
      pf = &value;//comando correto
//------------------------------------------------------------------h-----------------------------------------------------------------------------------------

    printf("ITEM H\n\n");
    pf = aloha;//ira funcionar

    return 0;
}
