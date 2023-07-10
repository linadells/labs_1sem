#include<stdio.h>
int main() {
	int R1[3][3], R2[3][3], NR1[3][3], NR2[3][3], com12[3][3], com21[3][3], sum;
	printf("Enter matrix R1:\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf_s("%i", &R1[i][j]);
			if ((R1[i][j] != 0) && (R1[i][j] != 1))
			{
				printf("Incorrect input.");
				return 0;
			}
		}
	}

	printf("Enter matrix R2:\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf_s("%i", &R2[i][j]);
			if ((R2[i][j] != 0) && (R2[i][j] != 1))
			{
				printf("Incorrect input.");
				return 0;
			}
		}
	}

	printf("Additin R1:\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (R1[i][j] == 0) 
			{
				NR1[i][j] = 1;
				printf("1 ");
			}
			if (R1[i][j] == 1)
			{
				NR1[i][j] = 0;
				printf("0 ");
			}
		}
		printf("\n");
	}

	printf("Additin R2:\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (R2[i][j] == 0)
			{
				NR2[i][j] = 1;
				printf("1 ");
			}
			if (R2[i][j] == 1)
			{
				NR2[i][j] = 0;
				printf("0 ");
			}
		}
		printf("\n");
	}

	printf("Intersection matrix:\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%i ", R1[i][j] && R2[i][j]);
		}
		printf("\n");
	}

	printf("Union matrix:\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%i ", R1[i][j] || R2[i][j]);
		}
		printf("\n");
	}

	printf("Difference matrix:\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%i ", R1[i][j] && NR2[i][j]);
		}
		printf("\n");
	}

	printf("Simetric difference matrix:\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%i ", (R1[i][j]||R2[i][j]) && !(R1[i][j] && R2[i][j]));
		}
		printf("\n");
	}

	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			sum = 0;
			for (int n = 0;n < 3;n++) {
				sum = sum || (R2[i][n] && R1[n][j]);
			}
			com12[i][j] = sum;
		}
	}

	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			sum = 0;
			for (int n = 0;n < 3;n++) {
				sum = sum || (R1[i][n] && R2[n][j]);
			}
			com21[i][j] = sum;
		}
	}

	printf("Composition of 1 and 2 matrix:\n");
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			printf("%i ", com12[i][j]);
		}
		printf("\n");
	}

	printf("Composition of 2 and 1 matrix:\n");
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			printf("%i ", com21[i][j]);
		}
		printf("\n");
	}
	return 0;
}

/*
1 0 0
0 0 0
1 0 0 

1 1 0 
1 1 1
0 0 1 
*/