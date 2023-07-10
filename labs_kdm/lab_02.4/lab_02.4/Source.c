#include<stdio.h>
int main() {
	int arr[6][6], sum, res[6][6], temp[6][6], dos[6][6]={0}, wor[6][6];
	printf("Vvedit matritsy:\n");
	for (int i = 0;i < 6;i++) {
		for (int j = 0;j < 6;j++) {
			scanf_s("%i", &arr[i][j]);
			temp[i][j] = arr[i][j];
			dos[i][j] = arr[i][j];
			wor[i][j] = arr[i][j];
			if ((arr[i][j] != 0) && (arr[i][j] != 1))
			{
				printf("Nekorektne znashennya");
				return -1;
			}
		}
	}

	for (int s = 0;s < 2;s++) {
		for (int i = 0;i < 6;i++) {
			for (int j = 0;j < 6;j++) {
				sum = 0;
				for (int n = 0;n < 6;n++) {
					sum = sum||( arr[i][n] && temp[n][j]);
				}
				res[i][j] = sum;
			}
		}
		printf("%i stepin:\n", s + 2);

		for (int i = 0;i < 6;i++) {
			for (int j = 0;j < 6;j++) {
				temp[i][j] = res[i][j];
				dos[i][j] = dos[i][j] || temp[i][j];
				printf("%i ", temp[i][j]);
			}
			printf("\n");
		}

	}
	printf("Matritsa dosyagnosti:\n");
	for (int i = 0;i < 6;i++) {
		for (int j = 0;j < 6;j++) {
			printf("%i ", dos[i][j]);
		}
		printf("\n");
	}
	for (int k = 0; k < 6;k++) {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				wor[i][j] = wor[i][j] || (wor[i][k] && wor[k][j]);
			}
		}
	}

	printf("Matritsa dosyagnosti(algoritm worshella):\n");
	for (int i = 0;i < 6;i++) {
		for (int j = 0;j < 6;j++) {
			printf("%i ", wor[i][j]);
		}
		printf("\n");
	}
	/*
0 1 0 1 0 0
0 0 1 0 0 0
0 0 0 1 0 1
0 0 0 0 1 0
0 0 0 0 0 1
0 0 0 0 0 0
	 */
	return 0;
}