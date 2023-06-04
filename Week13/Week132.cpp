#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int win;
        cin >> win;
        bool flag = false;
        unordered_set<int> mp;
        for (int i = 0; i < n; i++)
        {
            if (mp.find(v[i]) != mp.end())
            {
                cout << "Duplicate present in window " << win << endl;
                flag = true;
                break;
            }
            mp.insert(v[i]);
            if (i >= win)
            {
                mp.erase(v[i-win]);
            }
        }
        if (flag == false)
        {
            cout << "Duplicate not present in window " << win << endl;
        }
    }
    return 0;
}