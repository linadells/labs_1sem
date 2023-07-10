#include<stdio.h>
#define N 10
#define M 10
int main() {
	int arr[M][N], row, col, minR[M];
	printf("Enter quantity of rows:");
	scanf_s("%i", &row);
	printf("Enter quantity of columns:");
	scanf_s("%i", &col);
	printf("Enter matrix:\n");
	for (int i = 0;i < row;i++) {
		for (int j = 0; j < col;j++) {
			scanf_s("%i", &arr[i][j]);
		}
	}
	for (int i = 0; i < row;i++) {
		minR[i] = minRec(arr[i], col); 
	}

	printf("Min elements:\n");
	for (int i = 0; i < row;i++) {
		printf("%i row: %i\n", i + 1, minR[i]);
	}
	return 0;
}
