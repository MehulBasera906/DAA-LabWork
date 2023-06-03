#include <bits/stdc++.h>
using namespace std;
class DisJointSet
{
    vector<int> rank, parent;

public:
    DisJointSet(int n)
    {
        rank.resize(n + 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int findUlPar(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findUlPar(parent[node]);
    }
    void unionByRank(int u, int v)
    {
        int ulp_v = findUlPar(u);
        int ulp_u = findUlPar(v);
        if (ulp_v == ulp_u)
            return;
        if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
int main()
{
    int n = 8;
    int m = 7;
    int v[n][m] = {{0, 0, 7, 5, 0, 0, 0},
                   {0, 0, 8, 0, 0, 0, 0},
                   {7, 8, 0, 9, 7, 0, 0},
                   {5, 0, 9, 0, 15, 6, 0},
                   {0, 5, 7, 15, 0, 8, 9},
                   {0, 0, 0, 6, 8, 0, 11},
                   {0, 0, 0, 0, 9, 11, 0}};
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] != 0 && i != j)
            {
                edges.push_back({v[i][j], {i, j}});
            }
        }
    }
    DisJointSet ds(n);
    sort(edges.begin(), edges.end());
    int minWt = 0;
    for (auto it : edges)
    {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;
        if (ds.findUlPar(u) != ds.findUlPar(v))
        {
            minWt += wt;
            ds.unionByRank(u, v);
        }
    }
    cout << "Minimum Spanning Weight: " << minWt << endl;
    return 0;
}