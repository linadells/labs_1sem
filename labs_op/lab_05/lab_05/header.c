#include<math.h>
#include<stdio.h>
#include"header.h"
double func(double x) {
	double y = pow((x + 1), -2.0 / 3.0);
	return y;
}

int funcSign(double x, double *y) {
	*y = func(x);
	int res;
	if (*y < 0)
		res = -1;
	if (*y == 0)
		res = 0;
	else {
		res = 1;
	}
	return res;
}

void tab(double a, double b, double h) {
	double x, y;
	for (x = a;x <= b;x += h)
	{
		y = func(x);
		printf("|%lf\t%lf|\n", x, y);
	}
}
 
void tabSign(double a, double b, double h) {
	double x, y;
	int res;
	for (x = a;x <= b;x += h)
	{
		res = funcSign(x, &y);
		printf("|%lf\t%lf      %i  |\n", x, y, res);
	}
}