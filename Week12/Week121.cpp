#include <bits/stdc++.h>

using namespace std;

void lcs(string A, string B, int m, int n)
{
    vector<vector<int>> t(m + 1, vector<int>(n + 1));

    string sol;  
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (A[i - 1] == B[j - 1])
            {
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else
            {
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }

    int i = m, j = n;
    while (t[i][j] != 0)
    {
        if (A[i - 1] == B[j - 1])
        {
            sol.push_back(A[i - 1]);
            i--;
            j--;
        }

        else if (t[i - 1][j] > t[i][j - 1])
        {
            i = i - 1;
        }
        else
        {
            j = j - 1;
        }
    }

    reverse(sol.begin(), sol.end());

    cout << "Longest common Subsequence :" << sol << endl
         << "length=" << t[m][n] << endl;
}

int main()
{
    string A, B;
    cin >> A;
    cin >> B;

    lcs(A, B, A.length(), B.length());

    return 0;
}