#include"header.h"
#include<stdio.h>
#include<math.h>


int main()
{
	double x, y, a, b, h;
	printf("Enter step:\n");
	scanf_s("%lf", &h);
	printf("-------------------------\n");
	printf("|\tTabulation:\t|\n");
	printf("-------------------------\n");
	printf("|   x \t \t   y    |\n");
	printf("-------------------------\n");
	tab(0, 7, h);
	printf("-------------------------\n");


	printf("----------------------------------\n");
	printf("|\tTabulation with sign:\t |\n");
	printf("----------------------------------\n");
	printf("|   x \t  \t   y\t    sign |\n");
	printf("----------------------------------\n");
	tabSign(0, 7, h);
	printf("----------------------------------\n");
	return 0;
}