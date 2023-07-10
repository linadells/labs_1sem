/*#include<stdio.h>
int main() {
	int arr[6][6], sum, res[6][6], temp[6][6];
	printf("Vvedit matritsy:\n");
	for (int i = 0;i < 6;i++) {
		for (int j = 0;j < 6;j++) {
			scanf_s("%i", &arr[i][j]);
			temp[i][j] = arr[i][j];
		}
	}

	printf("\n1 stepin:\n");
	for (int s = 0;s < 4;s++) {
		for (int i = 0;i < 6;i++) {
			for (int j = 0;j < 6;j++) {
				sum = 0;
				for (int n = 0;n < 6;n++) {
					sum += temp[i][n] && arr[n][j];
				}
				res[i][j] = sum;
				printf("%i ", res[i][j]);
			}
			printf("\n");
		}
		/*for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				sum = 0;
				for (int m = 0; m < 6; m++)
				{
					sum || = arr[i][m] && temp[m][j];
					if (value)
						break; // early out
				}
				c[i][j] = value;
			}
		}*//*
		if(s!=3)
			printf("%i stepin:\n", s+1);
		for (int i = 0;i < 6;i++) {
			for (int j = 0;j < 6;j++) {
				temp[i][j] = res[i][j];
			}
		}
	}
	/*
	{
		W = M;
		for (k = 1; k <= n; k++) {
			for (j = 1; j <= n; j++) {
				W(i, j) = W(i, j) || (W(i, k) & &W(k, j));
			}
		}
	}
	*/
	/*
0 1 0 1 0 0
0 0 1 0 0 0
0 0 0 0 0 1
0 0 0 0 1 0
0 0 0 0 0 1
0 0 0 0 0 0
	 *//*
	return 0;
}*/