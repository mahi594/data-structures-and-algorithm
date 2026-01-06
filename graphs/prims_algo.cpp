#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(
    int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // adjacency list
    unordered_map<int, list<pair<int,int>>> adj;

    for(int i = 0; i < m; i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> key(n+1);
    vector<bool> mst(n+1);
    vector<int> parent(n+1);

    // ✅ correct initialization (1-based)
    for(int i = 1; i <= n; i++)
    {
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }

    key[1] = 0;   // start from node 1

    // Prim's algorithm
    for(int i = 1; i < n; i++)
    {
        int mini = INT_MAX;
        int u = -1;

        // find minimum key vertex
        for(int v = 1; v <= n; v++)
        {
            if(!mst[v] && key[v] < mini)
            {
                mini = key[v];
                u = v;
            }
        }

        mst[u] = true;

        // update adjacent vertices
        for(auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;

            if(!mst[v] && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;
    for(int i = 2; i <= n; i++)
    {
        result.push_back({{parent[i], i}, key[i]});
    }

    return result;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<pair<pair<int, int>, int>> g;

    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.push_back({{u, v}, w});
    }

    cout<<endl;
    vector<pair<pair<int, int>, int>> ans = calculatePrimsMST(n, m, g);

    for(auto it : ans)
    {
        cout << it.first.first << " "
             << it.first.second << " "
             << it.second << endl;
    }

    return 0;
}
