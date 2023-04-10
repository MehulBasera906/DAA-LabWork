#include <stdio.h>
#include <stdlib.h>
int first(int *arr, int s, int e, int key, int n)
{
    int mid;
    if (s <= e)
    {
        mid = (s + e) / 2;
        if (mid == 0 || key > arr[mid - 1] && arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            return first(arr, mid + 1, e, key, n);
        }
        else
        {
            return first(arr, s, mid - 1, key, n);
        }
    }
    return -1;
}
int last(int *arr, int s, int e, int key, int n)
{
    int mid;
    if (s <= e)
    {
        mid = (s + e) / 2;
        if (mid == n - 1 || key < arr[mid + 1] && arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            return first(arr, mid + 1, e, key, n);
        }
        else
        {
            return first(arr, s, mid - 1, key, n);
        }
    }
    return -1;
}
int count(int *arr, int key, int n)
{
    int i, j;
    i = first(arr, 0, n - 1, key, n);
    if (i == -1)
    {
        return i;
    }
    j = last(arr, i, n - 1, key, n);
    return j - i + 1;
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
        int flag = count(arr, key, n);
        if (flag != -1)
        {
            printf("%d - %d", key, flag);
        }
        else
        {
            printf("Not Present %d", key);
        }
    }

    return 0;
}