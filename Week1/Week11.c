#include <stdio.h>
#include <stdlib.h>
int linearSearch(int *arr, int n, int key, int *cmp)
{
    for (int i = 0; i < n; i++)
    {
        (*cmp)++;
        if (key == arr[i])
        {
            return i + 1;
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
        int flag = linearSearch(arr, n, key, &cmp);
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