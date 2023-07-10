#include "func.h"
int minRec(int arr[], int size){
	int rez = 0;
	if (size == 1)
		return arr[0];
	else {
		rez=minEl(arr[size - 1], minRec(arr, size - 1));
		return rez;
	}
}
int minEl(int a, int b) {
	if (a < b)
		return a;
	else {
		return b;
	}
}