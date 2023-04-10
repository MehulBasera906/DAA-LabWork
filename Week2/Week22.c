#include <stdio.h>
#include <stdlib.h>
void seq(int *arr, int n)
{
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if ((arr[i] + arr[j]) == arr[k])
                {
                    flag = 1;
                    printf("%d, %d, %d\n", i + 1, j + 1, k + 1);
                    return;
                }
            }
        }
    }
    if (flag == 0)
    {
        printf("No Sequence Found\n");
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        seq(arr, n);
    }
    return 0;
}