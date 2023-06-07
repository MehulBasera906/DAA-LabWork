#include <bits/stdc++.h>
using namespace std;
void shortestPath(int st, int dest, vector<pair<int, int>> adj[], int V, vector<pair<vector<int>, int>> &ans)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> parent(V), dist(V, 1e9);
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
    }
    dist[st] = 0;
    pq.push({0, st});
    while (pq.empty() == false)
    {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;
        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int adjWt = it.second;
            if (dist[adjNode] > adjWt + wt)
            {
                dist[adjNode] = adjWt + wt;
                pq.push({adjWt + wt, adjNode});
                parent[adjNode] = node;
            }
        }
    }
    if (dist[V] == 1e9)
    {
        pair<vector<int>, int> pt;
        pt.first = {st, dest};
        pt.second = -1;
        ans.push_back(pt);
        return;
    }
    vector<int> path;
    int node = dest;
    while (parent[node] != node)
    {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(st);
    reverse(path.begin(), path.end());
    pair<vector<int>,int> pt;
    pt.first = path;
    pt.second = dist[dest];
    ans.push_back(pt);
    return;
}
bool sol(vector<vector<int>> mat, int V, vector<pair<vector<int>, int>> &ans, int dest)
{
    vector<pair<int, int>> adj[V];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (mat[i][j] != 0 && i != j)
            {
                adj[i].push_back({j, mat[i][j]});
                adj[j].push_back({i, mat[i][j]});
            }
        }
    }
    for (int i = 0; i < V; i++)
    {
        shortestPath(i, dest, adj, V, ans);
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
    sol(mat, n, ans, dest-1);
    for (int i = 0; i < ans.size(); i++)
    {
        auto it = ans[i];
        for (int j = 0; j < it.first.size(); j++)
        {
            cout << it.first[j]+1 << " ";
        }
        cout << ": " << it.second << endl;
    }
    return 0;
}