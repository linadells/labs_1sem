/*#include<stdio.h>
int main() {
	int matrix[8][8], min, sum = 0, minj[8];

	printf("Enter matrix:\n");
	for (int i = 0;i < 8;i++) {
		for (int j = 0;j < 8;j++) {
			scanf_s("%i", &matrix[i][j]);
		}
	}

	min = matrix[0][1];
	int i = 0, k = 0;
	for (int j = 0;j < 8;j++) {//перебираємо j
		if (i == 0)
			j = 1;
		if (i != j) {//щоб не йти по діагоналі
			if (matrix[i][j] < min); //пошук мінімального
			min = matrix[i][j];
			for (int n = 0;n <= k;n++) { //чи ми не заходили у цю вершину
				if (min != minj[n]) //чи ми не заходили у цю вершину
					minj[k] = j;
			}
		}

		sum += min;
		i = minj[k];
		k++;
		printf("%i", minj[i]);
	}
	
	return 0;
}
/*
0 1 6 7 3 5 4 6
1 0 6 5 4 2 3 5
6 6 0 1 7 6 1 5
7 5 1 0 6 7 5 1
3 4 7 6 0 5 6 5
5 2 6 7 5 0 5 4
4 3 1 5 6 5 0 7
6 5 5 1 5 4 7 0
*/