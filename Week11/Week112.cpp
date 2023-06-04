#include <bits/stdc++.h>

using namespace std;

int coin_sum(int n, vector<int> val, int sum)
{
    vector<vector<int>> t(n + 1, vector<int>(sum + 1));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (j == 0)
                t[i][j] = 1;

            else if (i == 0)
                t[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j >= val[i - 1])
            {
                t[i][j] = t[i][j - val[i - 1]] + t[i - 1][j];
            }

            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[n][sum];
}

int main()
{
    int n, N;
    cin >> n;
    vector<int> val(n);
    for (int i = 0; i < n; i++)
        cin >> val[i];

    cin >> N;

    cout << coin_sum(n, val, N);

    return 0;
}