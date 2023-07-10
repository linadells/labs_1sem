#include"header.h"
void bubbleSort(int array[], long size)
{
	int i, j;
	for (i = 0; i < size-1; i++) {
		for (j = 0; j < size-i-1; j++) {
			if (array[j] < array[j + 1])
				swap(array, j, j + 1);
		}
	}
}

void swap(int array[], long pos1, long pos2)
{
	long tmp;
	tmp = array[pos1];
	array[pos1] = array[pos2];
	array[pos2] = tmp;
}

void qs_sort(int array[], long start, long end)
{
	long head = start, tail = end - 1, tmp;
	long diff = end - start;
	long pe_index;

	if (diff < 1) return;
	if (diff == 1)
		if (array[start] < array[end]) {
			swap(array, start, end);
			return;
		}

	long m = (start + end) / 2;
	if (array[start] <= array[m]) {
		if (array[m] <= array[end]) pe_index = m;
		else if (array[end] <= array[start]) pe_index = start;
		else pe_index = end;
	}
	else {
		if (array[start] <= array[end]) pe_index = start;
		else if (array[end] <= array[m]) pe_index = m;
		else pe_index = end;
	}
	long pe = array[pe_index]; 
	swap(array, pe_index, end);

	while (1) {
		while (array[head] > pe)
			++head;
		while (array[tail] < pe && tail > start)
			--tail;
		if (head >= tail) break;
		swap(array, head++, tail--);
	}
	swap(array, head, end);
	long mid = head;
	qs_sort(array, start, mid - 1); 
	qs_sort(array, mid + 1, end);
} 