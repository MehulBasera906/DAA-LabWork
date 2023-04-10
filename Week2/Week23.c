#include <stdio.h>
#include <stdlib.h>
int countDiff(int *arr, int n, int key)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((arr[i] - arr[j]) == key || (arr[j] - arr[i]) == key)
            {
                cnt++;
            }
        }
    }
    return cnt;
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
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        int key;
        scanf("%d", &key);
        int cnt = countDiff(arr, n, key);
        printf("%d\n", countDiff(arr, n, key));
    }
    return 0;
}