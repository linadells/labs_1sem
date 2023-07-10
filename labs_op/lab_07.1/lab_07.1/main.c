#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include"header.h"
#include <time.h>
#define FULL
#if defined (FULL) && defined (MINI)
#error You must choose only one version of program (MINI or FULL)
#endif
#if !defined (FULL) && !defined (MINI)
#error You must choose at least one version of program (MINI or FULL)
#endif

int main() {
	#ifdef MINI
	#define N 20	
	int arr[N], arrBub[N], arrQs[N], k;
	clock_t timeStart, timeEnd;
	double timeSortBub, timeSortQs;

	printf("Array:\n");
	srand(time(NULL));
	for (int i = 0;i < N;++i) {
		arr[i] = arrBub[i] = arrQs[i] = rand()%10;
		printf("%i ", arrBub[i]);
	}

	k = 0;
	for (int i = 0;i < N;++i) {
		if (arrBub[i] != arrQs[i]) {
			k++;
			break;
		}
	}
	if (k == 1)
		printf("\n\nArray before sorting aren`t the same\n");
	if (!k)
		printf("\n\nArray before sorting are the same\n");

	
	timeStart = clock();
	bubbleSort(arrBub, N);
	timeEnd = clock();
	timeSortBub = ((double)(timeEnd - timeStart)) / CLOCKS_PER_SEC;

	printf("\nBuble sort:\n");
	for (int i = 0;i < N;++i) {
		printf("%i ", arrBub[i]);
	}
	printf("\nSorting time:%lf\n", timeSortBub);

	k = 0;
	for (int i = 0;i < N;++i) {
		if (arrBub[i] < arrBub[i + 1]) {
			k++;
			break;
		}
	}
	if(k==1)
		printf("\nArray isn`t sorted\n");
	if(!k) 
		printf("\nArray is sorted\n");
	
	timeStart = clock();
	qs_sort(arrQs, 0, N-1);
	timeEnd = clock();
	timeSortQs = ((double)(timeEnd - timeStart)) / CLOCKS_PER_SEC;

	printf("\nQuick sort:\n");
	for (int i = 0;i < N;++i) {
		printf("%i ", arrQs[i]);
	}
	printf("\nSorting time:%lf\n", timeSortQs);

	k = 0;
	for (int i = 0;i < N;++i) {
		if (arrQs[i] < arrQs[i + 1]) {
			k++;
			break;
		}
	}
	if (k == 1)
		printf("\nArray isn`t sorted\n");
	if (!k) 
		printf("\nArray is sorted\n");

	k = 0;
	for (int i = 0;i < N;++i) {
		if (arrBub[i] != arrQs[i]) {
			k++;
			break;
		}
	}
	if (k == 1)
		printf("\nArray after sorting aren`t the same\n");
	if (!k)
		printf("\nArray after sorting are the same\n");

	if (timeSortBub > timeSortQs)
		printf("\nQuick sorting is faster then bubble sorting for %lf seconds\n", timeSortBub - timeSortQs);
	else {
		printf("\nQuick sorting is slower then bubble sorting for %lf seconds\n", timeSortQs - timeSortBub);
	}
	#endif
#ifdef FULL
#define N 30000
	int arr[N], arrBub[N], arrQs[N], k;
	clock_t timeStart, timeEnd;
	double timeSortBub, timeSortQs;

	printf("Array:\n");
	srand(time(NULL));

	k = 0;
	for (int i = 0;i < N;++i) {
		if (arrBub[i] != arrQs[i]) {
			k++;
			break;
		}
	}
	if (k == 1)
		printf("\n\nArray before sorting aren`t the same\n");
	if (!k)
		printf("\n\nArray before sorting are the same\n");


	timeStart = clock();
	bubbleSort(arrBub, N);
	timeEnd = clock();
	timeSortBub = ((double)(timeEnd - timeStart)) / CLOCKS_PER_SEC;

	printf("\nBuble sort:\n");
	printf("\nSorting time:%lf\n", timeSortBub);

	k = 0;
	for (int i = 0;i < N;++i) {
		if (arrBub[i] < arrBub[i + 1]) {
			k++;
			break;
		}
	}
	if (k == 1)
		printf("\nArray isn`t sorted\n");
	if (!k)
		printf("\nArray is sorted\n");

	timeStart = clock();
	qs_sort(arrQs, 0, N - 1);
	timeEnd = clock();
	timeSortQs = ((double)(timeEnd - timeStart)) / CLOCKS_PER_SEC;

	printf("\nQuick sort:\n");
	printf("\nSorting time:%lf\n", timeSortQs);

	k = 0;
	for (int i = 0;i < N;++i) {
		if (arrQs[i] < arrQs[i + 1]) {
			k++;
			break;
		}
	}
	if (k == 1)
		printf("\nArray isn`t sorted\n");
	if (!k)
		printf("\nArray is sorted\n");

	k = 0;
	for (int i = 0;i < N;++i) {
		if (arrBub[i] != arrQs[i]) {
			k++;
			break;
		}
	}
	if (k == 1)
		printf("\nArray after sorting aren`t the same\n");
	if (!k)
		printf("\nArray after sorting are the same\n");

	if (timeSortBub > timeSortQs)
		printf("\nQuick sorting is faster then bubble sorting for %lf seconds\n", timeSortBub - timeSortQs);
	else {
		printf("\nQuick sorting is slower then bubble sorting for %lf seconds\n", timeSortQs - timeSortBub);
	}
#endif
}