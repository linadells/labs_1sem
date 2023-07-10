#define N 10
#include"header.h"
int max(int matrix[][N], int size) {
	int max = matrix[0][0];
	for (int n = 0;n < size;++n) {
		for (int m = 0;m < size;++m) {
			if (matrix[n][m] > max)
				max = matrix[n][m];
		}
	}
	return max;
}

void scaning(int matrix[N][N], int size) {
	for (int n = 0;n < size;++n) {
		for (int m = 0;m < size;++m) {
			scanf_s("%i", &matrix[n][m]);
		}
	}
}