#include <bits/stdc++.h>
using namespace std;
void dfs(int src, vector<int> adj[], vector<int> &vis)
{
    vis[src] = 1;
    for (auto it : adj[src])
    {
        if (vis[it] == 0)
        {
            dfs(it, adj, vis);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 0; i < n; i++)
    {
        vector<int> vis(n, 0);
        bool flag = false;
        dfs(i, adj, vis);
        for (int i = 0; i < n; i++)
        {
            if (vis[i] == 0)
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}