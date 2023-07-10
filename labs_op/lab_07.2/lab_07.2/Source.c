#include<stdio.h>
#include"func.h"
int main() {
	double x, y, h;
	int var;
	int (*ptr)(double, double, double);
	printf("Enter h:");
	scanf_s("%lf", &h);
	printf("Choose tabylation:\n press \'1\' to \
cycle with \'for\'\n press \'2\' to cycle with \'while\'\n \
press \'3\' to cycle with \'do...while\'\n");
	scanf_s("%i", &var);

	if (var == 1) {
		ptr = &tab1;
	}
	else if (var == 2) {
		ptr = &tab2;
	}
	else if (var==3) {
		ptr = &tab3;
	}
	else {
		printf("Uncorrect input");
		return 0;
	}
	(*ptr)(0, 2, h);
	return 0;
}