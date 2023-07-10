#include<stdio.h>
int main() {
	int arr[4][4], k = 0, arr2[4][4], sum, r = 0, as = 0, s = 0, t = 0;
	printf("Enter matrix\n");
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			scanf_s("%i", &arr[i][j]);
			if ((arr[i][j] != 0) && (arr[i][j] != 1))
			{
				printf("Incorrect input.");
				return 0;
			}
		}
	}

	for (int i = 0;i < 4;i++) {
		if (arr[i][i] == 0) {
			k++;
		}
	}
	if (!k) {
		printf("Reflective\n");
		t++;
	}
	else {
		printf("Not reflective\n");
	}

	k = 0;
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			if (arr[i][j] != arr[j][i]) {
				k++;
			}
		}
	}
	if (!k) {
		printf("Simetric\n");
		s++;
	}
	else {
		printf("Not simetric\n");
	}

	k = 0;
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			if ((arr[i][j] == 0) && (arr[j][i])==1) {
				k++;
			}
		}
	}
	if (k==16) {
		printf("Unsimetric\n");
		as++;
	}
	else {
		printf("Not unsimetric\n");
	}

	k = 0;
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			sum = 0;
			for (int n = 0;n < 6;n++) {
				sum = sum || (arr[i][n] && arr[n][j]);
			}
			arr2[i][j] = sum;
		}
	}

	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			if (arr[i][j] != arr2[i][j]) {
				k++;
				break;
			}
		}
	}
	if (!k) {
		printf("Transitive\n");
		t++;
	}
	else {
		printf("Not transitive\n");
	}

	if ((t == 1) && (s == 1) && (r == 1))
		printf("Ekvivalent\n");
	else {
		printf("Not ekvivalent\n");
	}
	if ((t == 1) && (as == 1) && (r != 1))
		printf("Poradky\n");
	else {
		printf("Not poradky\n");
	}
	if ((t != 1) && (s == 1) && (r == 1))
		printf("Tolerant\n");
	else {
		printf("Not tolerant\n");
	}
	return 0;
}
/*
0 0 0 0
0 0 0 0
0 0 0 0
0 0 1 0
*/