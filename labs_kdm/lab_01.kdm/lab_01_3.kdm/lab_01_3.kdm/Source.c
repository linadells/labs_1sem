#include <stdio.h>

int main()
{
	int p[2] = {0,1},res;
	char x[2] = {'a','b'};

	printf("P\tx\t!P\tRes\n\n");
	for (int i = 0; i <= 1; i++)
	{
		
		printf("%i\t%c\t%i", p[i],x[i],!p[i]);
		if (i == 0)
			printf("\n");
	}
	res = !p[1] * !p[0];
	printf("\t%i", res);
	return 0;
}