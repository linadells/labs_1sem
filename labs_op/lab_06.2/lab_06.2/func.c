#define _CRT_SECURE_NO_WARNINGS
#include<stdarg.h>
#include<string.h>
#include<stdio.h>
#define N 100

void func(char* str, ...) {
	va_list p;
	int i = 1;
	char* word, * strN, strN1[100];
	const char* lim = " ";
	va_start(p, str);
	strcpy(strN1, str);
	strN = strN1;
	while (strN) {
		printf("%i string:\n", i);
		word = strtok(strN1, lim);
		while (word) {
			printf("%s\n", word);
			word = strtok(NULL, lim);
		}
		i++;
		strN = va_arg(p, char*);
		if (strN) {
			strcpy(strN1, strN);
		}
	}
	va_end(p);
}