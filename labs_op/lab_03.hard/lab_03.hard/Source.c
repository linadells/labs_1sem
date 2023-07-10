#include<stdio.h>
#define N 3

int main()
{
	int arr3d[N + 2][N][N], i, j, k, n, sum, temp[N][N];

	for (k = 0;k <= N+1;++k)
	{
		if (k < N)
		{
			printf("Enter %i layer:\n", k + 1);
			for (i = 0;i < N;++i)
			{
				for (j = 0;j < N;++j)
				{
					scanf_s("%i", &arr3d[k][i][j]);
				}
			}
		}
		if (k == N)
		{
			for (i = 0;i < N;++i)
			{
				for (j = 0;j < N;++j)
				{
					arr3d[k][i][j]=0;
				}
			}

		}
		if (k == N + 1)
		{
			for (i = 0;i < N;++i)
			{
				for (j = 0;j < N;++j)
				{
					arr3d[k][i][j] = 0;
				}
			}
		}
	}



	for (k = 0; k < N; ++k) 
	{
		for (i = 0; i < N;++i) 
		{
			for (j = 0; j < N; ++j) 
			{
				arr3d[N][i][j] += arr3d[k][i][j];
			}
		}
	}
	
	printf("Sum of matrix:\n");
	for (i = 0; i < N;++i)
	{
		for (j = 0; j < N; ++j)
		{
			printf("%i ", arr3d[N][i][j]);
		}
		printf("\n");
	}


	
	for (i = 0;i < N;++i)
	{
		for (j = 0; j < N;++j)
		{
			temp[i][j] = arr3d[0][i][j];
		}
	}


	for (k = 1;k < N; ++k)
	{
		for (i = 0; i < N;++i) 
		{
			for (j = 0; j < N; ++j) 
			{
				for (n = 0; n < N;++n) 
				{
					arr3d[N + 1][i][j] += temp[i][n] * arr3d[k][n][j];
				} 
			}
		}

		for (i = 0; i < N;++i)
		{
			for (j = 0;j < N;++j)
			{
				temp[i][j] = arr3d[N + 1][i][j];
				if (k != N - 1) arr3d[N + 1][i][j] = 0;
			}

		}
	}

	
	printf("Multiplication of matrix:\n");
	for (i = 0; i < N;++i)
	{
		for (j = 0; j < N; ++j)
		{
			printf("%i ", arr3d[N+1][i][j]);
		}
		printf("\n");
	}
	return 0;
}
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27