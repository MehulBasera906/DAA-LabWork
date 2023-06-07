#include <bits/stdc++.h>
using namespace std;
void bellmannFord(int st, int dest, vector<vector<int>> edges, int V, vector<pair<vector<int>, int>> &ans)
{
    vector<int> dist(V, 1e9);
    vector<int> par(V);
    for (int i = 0; i < V; i++)
    {
        par[i] = i;
    }
    dist[st] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[u] != 1e9 && dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
                par[v] = u;
            }
        }
    }
    if (dist[dest] == 1e9)
    {
        pair<vector<int>, int> pt;
        pt.first = {st, dest};
        pt.second = -1;
        return;
    }
    vector<int> path;
    int node = dest;
    while (par[node] != node)
    {
        path.push_back(node);
        node = par[node];
    }
    path.push_back(st);
    reverse(path.begin(), path.end());
    pair<vector<int>, int> pt;
    pt.first = path;
    pt.second = dist[dest];
    ans.push_back(pt);
    return;
}
bool sol(vector<vector<int>> mat, int V, vector<pair<vector<int>, int>> &ans, int dest)
{
    vector<vector<int>> edges;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (mat[i][j] != 0 && i != j)
            {
                edges.push_back({i + 1, j + 1, mat[i][j]});
            }
        }
    }
    for (int i = 0; i <= V; i++)
    {
        bellmannFord(1, i, edges, V, ans);
    }
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int temp;
            cin >> temp;
            mat[i][j] = temp;
        }
    }
    int dest;
    cin >> dest;
    vector<pair<vector<int>, int>> ans;
    sol(mat, n, ans, dest);
    for (int i = 0; i < ans.size(); i++)
    {
        auto it = ans[i];
        for (int j = 0; j < it.first.size(); j++)
        {
            cout << it.first[j] << " ";
        }
        cout << ": " << it.second << endl;
    }
    return 0;
}