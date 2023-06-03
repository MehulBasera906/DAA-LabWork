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
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int arr[n];
        int key;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        scanf("%d", &key);
        mergesort(arr, 0, n - 1);
        int flag = 0;
        int rt = n - 1, lft = 0;
        while (lft <= rt)
        {
            if (arr[lft] + arr[rt] == key)
            {
                printf("%d %d\n", arr[lft], arr[rt]);
                flag = 1;
                break;
            }
            else if (arr[lft] + arr[rt] > key)
            {
                rt--;
            }
            else
            {
                lft++;
            }
        }
        if (flag == 0)
        {
            printf("No Such Element Exist\n");
        }
    }
    return 0;
}