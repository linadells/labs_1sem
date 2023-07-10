#include<stdio.h>;
#include<math.h>;

int main()
{
	double x, y, z, f1, f2;
	int k = 4;

	x = -1.83 * k + 0.5;
	y = -0.74 * k + 1;
	z = 1.3 * k + 1.5;
	printf("x=%lf \n", x);
	printf("y=%lf \n", y);
	printf("z=%lf \n", z);

	f1 = cos(atan((x * x + y) / (z + 1))) * cos(atan((x * x + y) / (z + 1))) + ((x / z) * exp(3 * x + y));
	f2 = z * z + ((x * x + (sin(pow(fabs(f1 + y), 0.4)) * sin(pow(fabs(f1 + y), 0.4)))) / (y * y + fabs((x * x - y) / (z + (x * x * x) / 3)) - log(fabs(z))));

	printf("f1= %lf\n", f1);
	printf("f2= %lf\n", f2);

	return 0;
}
