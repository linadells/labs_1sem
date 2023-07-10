#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>
#define size 256

int main()
{
    FILE* flin = NULL;
    double x, y, res;
    char inputfilename[size];

    flin = fopen("D:\\користувач\\Документи\\моє\\лаби\\labs_op\\lab_04.02\\lab_04.02\\in.bin", "wb");

    printf("Enter x:\n");
    scanf_s("%lf", &x);
    fwrite(&x, sizeof(double), 1, flin);

    printf("Enter y:\n");
    scanf_s("%lf", &y);
    fwrite(&y, sizeof(double), 1, flin);
    fclose(flin);

    return 0;
}
