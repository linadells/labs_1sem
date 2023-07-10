#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>;
#include<math.h>;

int main()
{
	double x, y, a;
	int m;
	printf("Enter x: ");
	scanf_s("%lf", &x);
	printf("Enter y: ");
	scanf_s("%lf", &y);

	m = 2.0;
	a = pow(m, -x) * sqrt((1 / x) * (1 / x) * (1 / x) * (1 / x) + sqrt(fabs(y)));
	printf("Your result is: %lf", a);
	
	return 0;
}