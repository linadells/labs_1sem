#include<stdio.h>
int main()
{
    int p, q, i;
    printf("\tTruth Table\n\n");
    printf(" P\tQ\tRes\n");

    for (i = 0;i <= 3;i++)
    {

        p = i / 2;
        q = i % 2;
        printf(" %d\t%d\t%d\n", p, q, ((p & !q) || (q & !q)) || p);
    }


    return 0;
}