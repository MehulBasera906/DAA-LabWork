#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    map<int, pair<int, int>> mp;
    vector<pair<int, int>> ans;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int prod = v[i] * v[j];
            if (mp.find(prod) == mp.end())
            {
                mp.insert({prod, {v[i], v[j]}});
            }
            else
            {
                cout << v[i] << " " << v[j] << endl;
                cout << mp[prod].first << " " << mp[prod].second << endl;
                return 0;
            }
        }
    }
    return 0;
}