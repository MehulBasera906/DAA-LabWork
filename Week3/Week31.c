#include <stdio.h>
#include <stdlib.h>
void insSort(int *arr, int n, int *cmp, int *sft)
{
    int i = 0;
    int key;
    for (int i = 1; i <= n - 1; i++)
    {
        (*sft)++;
        int j = i - 1;
        key = arr[i];
        while (key < arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            (*cmp)++;
            (*sft)++;
            j--;
        }
        arr[j + 1] = key;
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
        int key, cmp = 0, sft = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        insSort(arr, n, &cmp, &sft);
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\nComparison = %d", cmp);
        printf("\nShifts = %d", sft);
    }
    return 0;
}