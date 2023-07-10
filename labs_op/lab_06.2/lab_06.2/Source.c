#define _CRT_SECURE_NO_WARNINGS
#include<stdarg.h>
#include<string.h>
#include<stdio.h>

int main() {
	func("s11 s12 s13", "s21 s22", "s31 s32 s33 s34", NULL);
	func("s41 s42", "s51 s52 s53", NULL);
	return 0;
}
