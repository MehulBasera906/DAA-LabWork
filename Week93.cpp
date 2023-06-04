#include <bits/stdc++.h>
using namespace std;
int sol(vector<int> v)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < v.size(); i++)
    {
        pq.push(v[i]);
    }
    int tmp = 0;
    while (pq.size() > 1)
    {
        int f = pq.top();
        pq.pop();
        int s = pq.top();
        pq.pop();
        int c = f + s;
        tmp += c;
        pq.push(c);
    }
    return tmp;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << sol(v);
    return 0;
}