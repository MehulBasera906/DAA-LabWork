#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int jumpSearch(int *arr, int n, int key)
{
    int st = 0;
    int end = sqrt(n);
    while (arr[end] <= key && end < n)
    {
        st = end;
        end += sqrt(n);
        if (end > n - 1)
        {
            end = n;
        }
    }
    for (int i = st; i < end; i++)
    {
        if (arr[i] == key)
        {
            return i;
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
        int key;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        scanf("%d", &key);
        int flag = jumpSearch(arr, n, key);
        if (flag != -1)
        {
            printf("Present at %d\n", flag);
        }
        else
        {
            printf("Not Present %d", key);
        }
    }
    return 0;
}