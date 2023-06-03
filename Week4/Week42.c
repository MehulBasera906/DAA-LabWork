#include <stdio.h>
#include <stdlib.h>
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int partition(int *A, int s, int e, int *swp)
{
    int pivot = A[s];
    int i = s + 1;
    int j = e;
    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }
        while (A[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(&A[i], &A[j]);
            (*swp)++;
        }
    } while (i < j);
    swap(&A[s], &A[j]);
    (*swp)++;
    return j;
}
void quickSort(int *A, int s, int e, int *swp)
{
    int partInd;
    if (s < e)
    {
        partInd = partition(A, s, e, swp);
        quickSort(A, s, partInd - 1,swp);
        quickSort(A, partInd + 1, e, swp);
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
        quickSort(arr, 0, n - 1, &swp);
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\nSwaps = %d", swp);
    }
    return 0;
}