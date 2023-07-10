#include<stdio.h>
int main()
{
    int p, q, r, i;
    printf("\t\tTruth Table\n\n");
    printf(" P\tQ\tR\t((P^Q)^((Q^!R)||(R^!Q)))||(!P^!R)\n\n");

    for (i = 0;i <= 3;i++)
    {
        p = 1;
        q = i / 2;
        r = i % 2;
        printf(" %d\t%d\t%d\t\t\t%d\n", p, q, r, (((p & q) & ((q & !r) || (r & !q))) || (!p & !r)));
    }
    for (i = 0;i <= 3;i++)
    {
        p = 0;
        q = i / 2;
        r = i % 2;
        printf(" %d\t%d\t%d\t\t\t%d\n", p, q, r, (((p & q) & ((q & !r) || (r & !q))) || (!p & !r)));
    }

    return 0;
}