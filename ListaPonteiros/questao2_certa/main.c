#include <stdio.h>

int main()
{
    int i=3,j=5,aux,aux2,aux3,aux4;
    int *p, *q;
    char *r, *t;
    p = &i;
    q = &j;
    printf("p:%p\n",p);
    printf("q:%p\n",q);

    aux = p == &i;
    printf("aux=%d\n",aux);
    aux2 = *p - *q;
    printf("aux2=%d\n",aux2);
    aux3 = **&p;
    printf("aux3=%d\n",aux3);
    aux4 = 3 - *p/(*q) + 7;
    printf("aux4=%d\n",aux4);

    printf("tamanho ints = %d %d\n", sizeof(p), sizeof (q));
    printf("tamanho char = %d %d\n", sizeof(r), sizeof (t));
    return 0;
}
