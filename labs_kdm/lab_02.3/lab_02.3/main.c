/*#include<stdio.h>
void swap(int* elem1, int* elem2) {
	int temp = *elem1;
	*elem1 = *elem2;
	*elem2 = temp;
}
void selectionSort(int array[], int size) {
	for (int step = 0; step < size - 1; step++) {
		int min_idx = step;
		for (int i = step + 1; i < size; i++) {
			if (array[i] < array[min_idx])
				min_idx = i;
		}
		swap(&array[min_idx], &array[step]);
	}
}

int main() {
	int arr[8][8] = 
	{
	0,1,6,7,3,5,4,6,
	1,0,6,5,4,2,3,5,
	6,6,0,1,7,6,1,5,
	7,5,1,0,6,7,5,1,
	3,4,7,6,0,5,6,5,
	5,2,6,7,5,0,5,4,
	4,3,1,5,6,5,0,7,
	6,5,5,1,5,4,7,0};
	int u[8] = {2,3,4,5,6,7,8 }, marsh[8]={1}, waga = 0, versh = 1, mini = 0, minj = 0;

	for (int k = 0;k < 8;k++) {
		selectionSort(arr[k], 8);
	}
	for (int i = 1; i < 7;i++) {
		for (int j=0;j < 8;j++) {
			if (arr[mini][j] != 0) {
				mini = j;
				marsh
			}
		}
	}

	/*

	for (int n = 0;n < 8;n++) {
			for (j = 0; j < 8;++j) {
				if (arr[mini][j] < arr[mini][minj] && u[i]!=0) {
					mini = j;
					minj = j;
				}
		}
		marsh[n] = mini;
		waga += arr[mini][minj];
		u[mini] = 0;
		n++;
	}
	*//*
	for (i = 0;i < 8;++i) {
		for (j = 0;j < 8;++j) {
			printf("%i ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}*/