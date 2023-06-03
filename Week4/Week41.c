#include <stdio.h>
#include <stdlib.h>
void merge(int A[], int mid, int low, int high, int *cmp, int *inv)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            (*cmp)++;
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            (*cmp)++;
            (*inv) += (mid + 1) + (low + i);
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        j++;
        k++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}
void mergesort(int A[], int low, int high, int *cmp, int *inv)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergesort(A, low, mid, cmp, inv);
        mergesort(A, mid + 1, high, cmp, inv);
        merge(A, mid, low, high, cmp, inv);
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
        mergesort(arr, 0, n - 1, &cmp, &sft);
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\nComparison = %d", cmp);
        printf("\nShifts = %d", sft);
    }
    return 0;
}