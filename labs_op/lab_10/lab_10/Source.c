#include"header.h"
#include<stdio.h>
#define N 255
#define M 12
#define I 3

int main(int argc, char* argv[]) {
	list** ppFirst;
	stud* new;
	if (argc != 2) {
		printf("Quantity of command argument is wrong");
		return -1;
	}
	printf("\t    List of students\n");
	createList(argv[1], &ppFirst);
	infoNewStud(&new); ;
	insertElem(new, &ppFirst);
	deleteElem(&ppFirst);
	printList(ppFirst);
	freeList(&ppFirst);
	return 0;
}