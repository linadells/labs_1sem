#include<stdio.h>
#include<ctype.h>
#define N 100

int main()
{
	int iQuant, i;
	double dArr[N], dMax, dSum, dAver;

	printf("Enter quantity:");
	scanf_s("%d", &iQuant);

	dSum = 0;
	for (i = 0; i < iQuant; ++i)
	{
		printf("Enter %i element:", i + 1);
		scanf_s("%lf", dArr + i);
		dSum += dArr[i];
	}

	double* ptr = dArr;

	dAver = dSum / iQuant;
	dMax = 0;

	printf("\nAverage:%.3lf\n", dAver);

	for (i = 0; i < iQuant; ++i)
	{
		if (dArr[i] > dMax)
			dMax = dArr[i];
	}
	printf("Max:%.3lf\n", dMax);

	for (i = 0; i < iQuant; ++i)
	{
		if (*(dArr+i) > dAver && dArr[i] != dMax)
			*(dArr+i) = 0;

		if (dArr[i] == dMax)
			dArr[i] = dAver;
	}

	printf("\nNew array:\n");


	for (i = 0; i < iQuant; ++i)
	{
		printf("%.3llf\n", *(ptr + i));
	}
	return 0;
}