#include <bits/stdc++.h>

using namespace std;

void ks(vector<int> &val, vector<int> &wt, int n, int W)
{

    vector<vector<int>> t(n + 1, vector<int>(W + 1));

    vector<int> sw, sv;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (j >= wt[i - 1])
            {
                t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
            }

            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    int i = n;
    int j = W;

    while (t[i][j] != 0)
    {
        if (j >= wt[i - 1])
        {
            if (val[i - 1] + t[i - 1][j - wt[i - 1]] > t[i - 1][j])
            {
                sv.push_back(val[i - 1]);
                sw.push_back(wt[i - 1]);
                j = j - wt[i - 1];
                i = i - 1;
            }

            else
            {
                i = i - 1;
            }
        }
    }

    cout << "value=" << t[n][W] << endl;
    cout << "Weights selected=";

    for (int i = sw.size() - 1; i >= 0; i--)
    {
        cout << sw[i] << " ";
    }
    cout << endl;

    cout << "values of selected Weights:";

    for (int j = sv.size() - 1; j >= 0; j--)
    {
        cout << sv[j] << " ";
    }
}

int main()
{
    int n, W;
    cin >> n;
    vector<int> val(n), wt(n);

    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }

    for (int j = 0; j < n; j++)
    {
        cin >> val[j];
    }
    cin >> W;

    ks(val, wt, n, W);
    return 0;
}