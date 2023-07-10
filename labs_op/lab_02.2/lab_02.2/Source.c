#include<stdio.h>
#include<math.h>

int main()
{
	float x, y, a, b, h, sum, func, eps, i;
	int k;

	printf("Enter eps:");
	scanf_s("%f", &eps);
	printf("Enter a:");
	scanf_s("%f", &a);
	printf("Enter b:");
	scanf_s("%f", &b);
	if (a >= b)
	{
		printf("Incorect input");
		return 0;
	}

	printf("x\t\t ln(1+x)\t tailor\t    differance   k\n");

	h = 0.05;


	for (x=a; x<=b; x+=h) 
	{
		
		y = log(x + 1);

		sum = x;
		func = x;
		i = 1;
		k = 0;
		
		while (fabs(func) > eps)
		{

			func *= (-1) * x * i / (i+1);
			sum += func;
			++i;
			++k;
		}
		printf("% .5f \t % .5lf\t % .5lf % e %d\n", x, y, sum, fabs((y-sum)), k);
	}
	return 0;
	
}