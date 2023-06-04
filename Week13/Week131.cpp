#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<char> arr;
    for (int i = 0; i < n; i++)
    {
        char temp;
        cin >> temp;
        arr.push_back(temp);
    }
    map<char, int> mp;
    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++;
    }
    for (auto it : mp)
    {
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}