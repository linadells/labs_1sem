#include<stdio.h>
#define N 5

int main()
{
	int iArr[N][N], i, j, iTemp, iDiag[N];

	printf("Enter matrix:\n");

	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < N; ++j)
		{
			scanf_s("%d", &iArr[i][j]);
		}
	}


	for (i = 0; i < N; ++i)
	{
		iDiag[i] = iArr[i][i];
	}


	for (int i = 1; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (iDiag[i] < iDiag[j])
			{
				iTemp = iDiag[i];
				iDiag[i] = iDiag[j];
				iDiag[j] = iTemp;
			}
		}
	}

	for (i = 0; i < N;++i)
	{
		iArr[i][i] = iDiag[i];
	}


	printf("New matrix:\n");


	for (i = 0; i < N; ++i)
	{
		for (j = 0;j < N; ++j)
		{
			printf("% d ", *(*(iArr + i) + j));

		}
		printf("\n");
	}
	return 0;
}