#define _CTR_NO_SECURE_
#include<stdio.h>;
#include<math.h>;

int main()
{
	float x, y, z, u, max=1;
	printf("Enter x: ");
	scanf_s("%f", &x);
	printf("Enter y: ");
	scanf_s("%f", &y);
	printf("Enter z: ");
	scanf_s("%f", &z);
	if (x >= y)
		max = x;
	else {
		max = y;
	}
	if (z >= max)
		max = z;
	if (max < 19)
		u = sqrt(fabs(x * y * z));
	else {
		u = x / (fabs(y) + z * z);
	}
	printf("u=%f", u);
	return 0;
}
