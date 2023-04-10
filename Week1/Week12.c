#include <stdio.h>
#include <stdlib.h>
int binarySearch(int *arr, int n, int key, int *cmp)
{
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        (*cmp)++;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return -1;
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
        int key, cmp = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        scanf("%d", &key);
        int flag = binarySearch(arr, n, key, &cmp);
        if (flag != -1)
        {
            printf("Present %d\nComparison = %d", flag, cmp);
        }
        else
        {
            printf("Not Present %d", key);
        }
    }
    return 0;
}