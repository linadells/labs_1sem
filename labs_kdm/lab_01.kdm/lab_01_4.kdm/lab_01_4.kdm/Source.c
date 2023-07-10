#include<stdio.h>
#include<math.h>

int main()
{
	int u[] = {1,2,3,4,5,6,7,8,9,10};
	int a[2][10] = {
		{1,2,3,4,5,6,7},
		{1,1,1,1,1,1,1} };
	int b[2][10] = {
		{0,0,0,0,5,6,7,8,9,10},
		{0,0,0,0,1,1,1,1,1,1} };
	int c[2][10] = { {1,2,3,0,0,0,0,8,9,10},
		{1,1,1,0,0,0,0,1,1,1} };
	int res[2][10] = { { 1,2,3,4,5,6,7,8,9,10 },{0} };
	int sum=0;
	int bool[10] = { 0 };

	//перший
	printf("(A&&C)||B\n");
	for (int i=0; i <= 9; i++) {
		res[0][i] = (a[1][i] && c[1][i])||b[1][i];
		printf("%d", res[0][i]);
		if (i!=9)
		printf(",");
		res[1][i] = res[0][i] * u[i];
	}
	printf("\n");

	for (int i = 0; i <= 9; i++) {
		printf("%d", res[1][i]);
		if (i != 9)
			printf(",");
	}
	printf("\n\n\n");


	//другий
	printf("(B\\C)||(C\\B)\n");
	for (int i = 0; i <= 9; i++) {
		res[0][i] = (b[1][i] && !c[1][i])|| (c[1][i] && !b[1][i]);
		printf("%d", res[0][i]);
		if (i != 9)
			printf(",");
		res[1][i] = res[0][i] * u[i];
	}
	printf("\n");
	for (int i = 0; i <= 9; i++) {
		printf("%d", res[1][i]);
		if (i != 9)
			printf(",");
	}
	printf("\n\n\n");

	//третій
	printf("C\(!A||!C)&&B\n");
	for (int i = 0; i <= 9; i++) {
		res[0][i] = (c[1][i] && b[1][i] && a[1][i]);
		printf("%d", res[0][i]);
		if (i != 9)
			printf(",");
		res[1][i] = res[0][i] * u[i];
		if (res[1][i] == 1)
			sum++;
	}
	printf("\n");
	for (int i = 0; i <= 9; i++) {
		printf("%d", res[1][i]);
		if (i != 9)
			printf(",");
	}

	//булеан
	int k = pow(2, sum);
	for (int i = 0; i < sum; ++i) {
		int j = i, g = 0;
		while (j != 0)
		{
			bool[g] = j % 2;
			j /= 2;
			++g;
		}
	}

	printf("\nPower:%i", sum);


	for (int i = 0; i <= sum; ++i)
	{
		printf("\nBool: {%i}", bool[i]);
	}


}