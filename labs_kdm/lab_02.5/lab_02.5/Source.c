#include<stdio.h>
int main()
{
	int matrixG[10][10], matrixH[10][10], matrixUn[10][10], matrixInt[10][10];
	int size = 6;

	int quantV = 0, quantE = 0;

	printf("Enter matrix G:\n");
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			scanf_s("%i", &matrixG[i][j]);
			if ((matrixG[i][j] != 0) && (matrixG[i][j] != 1))
			{
				printf("Incorrect input.");
				return 0;
			}
		}
	}


	quantV = 0, quantE = 0;
	printf("Complement matrix:\n");
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (matrixG[i][j] == 0 && i != j) {
				printf("%i ", 1);
				quantE++;
			}
			if (matrixG[i][j] == 1) {
				printf("%i ", 0);
			}
			if (i == j) {
				printf("%i ", 0);
			}
		}
		printf("\n");
		quantV++;
	}
	printf("Quantity of edges:%i\n", quantE);
	printf("Quantity of vertex:%i\n", quantV);

	printf("Enter matrix H:\n");
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			scanf_s("%i", &matrixH[i][j]);
			if ((matrixH[i][j] != 0) && (matrixH[i][j] != 1))
			{
				printf("Incorrect input.");
				return 0;
			}
		}
	}

	quantV = 0, quantE = 0;
	printf("Intersection matrix:\n");
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrixInt[i][j] = matrixG[i][j] && matrixH[i][j];
			printf("%i ", matrixInt[i][j]);
			if (matrixInt[i][j] == 1)
				quantE++;
		}
		printf("\n");
		quantV++;
	}
	printf("Quantity of edges:%i\n", quantE);
	printf("Quantity of vertex:%i\n", quantV);

	quantV = 0, quantE = 0;
	printf("Union matrix:\n");
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrixUn[i][j] = (matrixG[i][j] || matrixH[i][j]);
			printf("%i ", matrixUn[i][j]);
			if (matrixUn[i][j] == 1)
				quantE++;
		}
		printf("\n");
		quantV++;
	}
	printf("Quantity of edges:%i\n", quantE);
	printf("Quantity of vertex:%i\n", quantV);


	return 0;
}
/*
0 1 0 1 0 0
0 0 1 0 0 0 
0 0 0 1 0 1
0 0 0 0 1 0
0 0 0 0 0 1
0 0 0 0 0 0

0 1 0 1 0 0
0 0 1 0 0 0
0 0 0 1 0 1
0 0 0 0 1 0
0 1 0 0 0 1
0 0 0 0 0 0
*/