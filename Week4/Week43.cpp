#include <bits/stdc++.h>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int l, int r)
{
    int part = arr[r], i = l-1;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= part)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }

    swap(&arr[i+1], &arr[r]);
    return i+1;
}

int kthSmallest(int arr[], int l, int r, int K)
{
    if (K > 0 && K <= r - l + 1)
    {

        int pos = partition(arr, l, r);

        if (pos - l == K - 1)
            return arr[pos];
        if (pos - l > K - 1) 
            return kthSmallest(arr, l, pos - 1, K);
        return kthSmallest(arr, pos + 1, r,
                           K - pos + l - 1);
    }
    return INT_MAX;
}

// Driver's code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int k;
        cin >> k;
        cout << kthSmallest(arr, 0, n - 1, k) << endl;
    }
    return 0;
}
