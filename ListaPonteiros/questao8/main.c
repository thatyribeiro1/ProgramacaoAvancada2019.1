#include <stdio.h>

int main()
{
    int mat[4], *p, x;
    p = mat + 1;
//    p = mat++;//int mat[4] é variavel estatica, seu endereco nao pode ser alterado
//    p = ++mat;
    x = (*mat)++;
}
