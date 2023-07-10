#include<stdio.h>
#define N 10
#include "header.h"
int main() {
	int matrixA[N][N], matrixB[N][N], matrixC[N][N], size, maxr, maxB, maxC;
	int* adr;

	printf("Enter size of matrixs:");
	scanf_s("%i", &size);

	printf("Enter matrix A:\n");
	scaning(matrixA, size);
	printf("Max element: %i\n", max(matrixA, size));

	maxr = max(matrixA, size);
	adr = &matrixA[0][0];



	printf("Enter matrix B:\n");
	scaning(matrixB, size);
	maxB = max(matrixB, size);
	printf("Max element: %i\n", maxB);

	if (maxB > maxr) {
		maxr = maxB;
		adr = &matrixB[0][0];
	}
	


	printf("Enter matrix C:\n");
	scaning(matrixC, size);
	maxC = max(matrixC, size);
	printf("Max element: %i\n", maxC);

	if (maxC > maxr) {
		maxr = maxC;
		adr = &matrixC[0][0];
	}
	
	printf("Max element of all matrixes:%i\n", maxr);
	printf("Matrix with max element:\n");
	for (int n = 0;n < size;++n) {
		for (int m = 0;m < size;++m) {
			printf("%-i  ", *(adr+n*N+m));
		}
		printf("\n");
	}
}