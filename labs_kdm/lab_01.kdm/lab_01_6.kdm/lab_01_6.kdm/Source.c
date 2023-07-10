#include <stdio.h>
int main()
{
	int a, b, c, d, e, f, g;
	float x, k, m, l;

	printf("Enter a=");
	scanf_s("%d", &a);
	printf("Enter b=");
	scanf_s("%d", &b);
	printf("Enter c=");
	scanf_s("%d", &c);
	printf("Enter d=");
	scanf_s("%d", &d);
	printf("Enter e=");
	scanf_s("%d", &e);
	printf("Enter f=");
	scanf_s("%d", &f);
	printf("Enter g=");
	scanf_s("%d", &g);

	x = (b + d + c - f - e - g - a) / 2.0;
	int t = (b + d + c - f - e - g - a) / 2.0;

	if ((x > 0) && (x == t))
		printf("This realisation is possible: x=%f\n", x);
	else
	{
		printf("This realisation isn`t possible. x=%f\n", x);
	}

	k = b - f - e + x;
	printf("Text information: k=%f\n", k);
	m = c - e - g + x;
	printf("Graphical information: m=%f\n", m);
	l = d - f - g + x;
	printf("Char information: l=%f\n", l);

	return 0;
}