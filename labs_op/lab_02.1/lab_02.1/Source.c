#include<stdio.h>
int main()
{
	long long int x;
	int k;
	printf("Enter x,x>0:");
	scanf_s("%lld", &x);
	if (x <= 0) {
		printf("Your x isn`t positive");
		return 0;
	}

	k = 0;
	for (long long int i = 1; i <= x; i++)
	{
		for (long long int n = 1; n <= i; n++)
		{
			for (long long int m = 1; m <= n; m++)
			{
				if (i * i + n * n + m * m == x)
				{
					printf("x = %lld = %lld*%lld + %lld*%lld + %lld*%lld", x, i, i, n, n, m, m);
					k++;
					break;
				}
				if (k == 1) break;
			}
			if (k == 1) break;
		}
		if (k == 1) break;
	}
	if (k == 0)
		printf("x isn`t sum of squares of any 3 natural figures");
	return 0;
}