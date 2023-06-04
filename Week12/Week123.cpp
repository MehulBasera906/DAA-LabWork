#include <bits/stdc++.h>
using namespace std;
void permute(vector<char> &ds, string str, map<char, int> &mp, vector<vector<char>> &ans)
{
    if (ds.size() == str.length())
    {
        ans.push_back(ds);
        return;
    }
    for (int i = 0; i < str.length(); i++)
    {
        if (mp[str[i]] == 0)
        {
            ds.push_back(str[i]);
            mp[str[i]] = 1;
            permute(ds, str, mp, ans);
            ds.pop_back();
            mp[str[i]] = 0;
        }
    }
}
int main()
{
    string str;
    cin >> str;
    sort(str.begin(), str.end());
    vector<vector<char>> ans;
    map<char, int> mp;
    for (int i = 0; i < str.length(); i++)
    {
        mp[str[i]] = 0;
    }
    vector<char> ds;
    permute(ds, str, mp, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        string temp = "";
        for (int j = 0; j < ans[i].size(); j++)
        {
            temp += ans[i][j];
        }
        cout << temp << endl;
    }
    return 0;
}