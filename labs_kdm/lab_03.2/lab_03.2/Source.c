#include<stdio.h>
#define N 12
int main() {
	int pruf[N - 2], arr[N] = { 1,2,3,4,5,6,7,8,9,10,11,12 }, minE, n = N - 2, copy[N], minind;
	printf("Enter pruffers kod:\n");
	for (int i = 0;i < N - 2;i++) {
		scanf_s("%i", &pruf[i]);
	}
	printf("Edges of graph:\n");
	for (int k = 0;k < N;k++) {
		minE = 999;
		if (k < N - 2) {
			for (int i = 0;i < N;i++){
				copy[i] = arr[i];
			}
			for (int i = 0;i < N - 2;i++) {
				for (int j = 0;j < N;j++) {
					if (copy[i] == pruf[j]) {
						copy[i] = 999;
					}
				}
			}
			for (int j = 0;j < N;j++) {
				if ((copy[j] < minE)) {
					minE = copy[j];
					minind = j;
				}
			}		
			arr[minind] = 999;
			printf("%i%i\n", pruf[k], minE);
			pruf[k] = 999;
		 }
		else {
			for (int i = 0;i < N;i++) {
				if (arr[i] < minE) {
					minE = arr[i];
					arr[i] = 999;
					}
			}
			printf("%i", minE);
			
		}
	}
	return 0;
}
/*
6 5 4 2 3 4 4 6 5 5
*/