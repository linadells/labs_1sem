#include <stdio.h>
#define N 8

int main(void)
{
    int arr[8][8] =
    {
    0,1,6,7,3,5,4,6,
    1,0,6,5,4,2,3,5,
    6,6,0,1,7,6,1,5,
    7,5,1,0,6,7,5,1,
    3,4,7,6,0,5,6,5,
    5,2,6,7,5,0,5,4,
    4,3,1,5,6,5,0,7,
    6,5,5,1,5,4,7,0 };
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            //scanf_s("%i", &arr[i][j]);
            if (arr[i][j] != arr[j][i])
            {
                printf("Incorrect input.");
                return 0;
            }
        }
    }

    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < N;j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    int marsh[N + 1] = { 0 }, k = 1, min, mini = 0, minj = 0, marshlen = 0;
    marsh[0] = 1;
    while (!marsh[N])
    {
        min = 100000;
        for (int j = 0;j < N;j++)
        {

            if ((arr[mini][j] < min) && arr[mini][j])
            {
                if (j == 0) continue;
                else minj = j;
                min = arr[mini][j];
            }
        }

        if (k == (N))
        {
            marsh[k] = 1;
            marshlen += arr[marsh[k - 1] - 1][marsh[k] - 1];
        }
        else
        {
            marshlen += arr[mini][minj];
            for (int i = 0;i < N;i++)
            {
                arr[i][minj] = 0;
            }
            marsh[k] = minj + 1;
            mini = minj;
        }
        k++;
    }

    printf("\nRoute:\n");
    for (int i = 0;i <= N;i++)
    {
        printf("%d ", marsh[i]);
    }

    printf("\nLength of route %d\n", marshlen);


    return 0;
}

