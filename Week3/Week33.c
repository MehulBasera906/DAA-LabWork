#include <stdio.h>
#include <stdlib.h>
void merge(int A[], int mid, int low, int high)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
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
void mergesort(int A[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergesort(A, low, mid);
        mergesort(A, mid + 1, high);
        merge(A, mid, low, high);
    }
}
int binarySearch(int *arr, int n)
{
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (arr[mid] == arr[mid + 1])
        {
            return 1;
        }
        else if (arr[mid] > arr[mid + 1])
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return 0;
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
        mergesort(arr, 0, n - 1);
        int flag = binarySearch(arr, n);
        if (flag == 1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}