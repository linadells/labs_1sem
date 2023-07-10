#include<stdio.h>
#include<stdlib.h>
#include <time.h>
int main(int argc, char *argv[]) {
	int m, * masyv=NULL, ** s = NULL, * dim = NULL, count, k;
	srand(time(NULL));
	m = atoi(argv[1]);
	printf("Quantity of arrays:%i", m);
	dim = (int*)malloc(m*sizeof(int));

	printf("\nSizes of arrays:\n");
	for (int i=0;i < m;i++) {
		dim[i] = (rand() % 10)+1;
		printf("%i: %i\n", i+1, dim[i]);
	}

	count = 0;
	printf("Arrays:\n");
	s = (int**)malloc(m * sizeof(int*));
	for (int i = 0;i < m;i++) {
		s[i] = (int*)malloc(dim[i] * sizeof(int));
		printf("%i array:", i+1);
		for (int j = 0;j < dim[i]; j++) {
			s[i][j] = rand() % 10;
			printf("%i ", s[i][j]);
			count++;
		}
		printf("\n"); 
	}

	masyv = (int*)malloc(count * sizeof(int));
	k = 0;
	for (int i = 0;i < m;i++) {
		for (int j = 0;j < dim[i];j++) {
			masyv[k] = s[i][j];
			k++;
		}
	}

	free(dim);
	dim = NULL;

	for (int i = 0;i < m;i++) {
		free(s[i]);
	}
	free(s);

	printf("Union array:\n");
	for (int i = 0;i < count;i++) {
		printf("%i ", masyv[i]);
	}
	free(masyv);
	masyv = NULL;

	return 0;
}