#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define N 1000

int main()
{
    int k, i, j, len, quant, l;
    char* word, * lim = " ";
    char str[N];
    char sym;

    printf("Enter str:");
    fgets(str, N, stdin);


    k = 0;
    l = 0;
    word = strtok(str, lim);

    while(word!=NULL)
    {
        len = strlen(word);
        for (i = 0; i < len; i++)
        {
            sym = word[i];
            for (j = i + 1; j <= len; j++) {
                if (sym == word[j]) {
                    break;
                }
                if (j == len - 1)
                    k++;
            }
            if (i == len - 1)
                k++;
        }

        if (k == len)
        {
            l++;
            if (l == 1)
                printf("Words without reapitings:");
            printf("%s ", word);
           
        }
       
        word = strtok(NULL, lim);
        k = 0;
    }
    if (l == 0) {
        printf("There aren`t any words witout reapitings");
    }
    return 0;
}