#include<math.h>
void tab1(double a, double b, double h) {
	double x, y;
	printf("Tabylation with for:\n");
	printf("    x\t\t    y\n");
	for (x = a;x <= b;x += h)
	{
		y = x * x * sqrt(4 - x * x);
		printf("%lf\t%lf\n", x, y);
	}
}
void tab2(double a, double b, double h) {
	double x, y;
	x = a;
	printf("Tabylation with while:\n");
	printf("    x\t\t    y\n");
	while(x<=b){
		y = x * x * sqrt(4 - x * x);
		printf("%lf\t%lf\n", x, y);
		x += h;
	}
}
void tab3(double a, double b, double h) {
	double x, y;
	x = a;
	printf("Tabylation with do_while:\n");
	printf("    x\t\t    y\n");
	do {
		y = x * x * sqrt(4 - x * x);
		printf("%lf\t%lf\n", x, y);
		x += h;
	} while (x <= b);
}