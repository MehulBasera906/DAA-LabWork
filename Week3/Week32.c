#include <stdio.h>
#include <stdlib.h>
void selSort(int *arr, int n, int *cmp, int *swp)
{
    for (int i = 0; i < n - 1; i++)
    {
        int indMin = i;
        for (int j = i + 1; j < n; j++)
        {
            (*cmp)++;
            if (arr[indMin] > arr[j])
            {
                indMin = j;
            }
        }
        int temp = arr[indMin];
        arr[indMin] = arr[i];
        arr[i] = temp;
        (*swp)++;
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
        int key, cmp = 0, swp = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        selSort(arr, n, &cmp, &swp);
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\nComparison = %d", cmp);
        printf("\nSwaps = %d", swp);
    }
    return 0;
}