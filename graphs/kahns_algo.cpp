#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <unordered_map>


using namespace std;

/*
    Function to perform Topological Sort using BFS (Kahn's Algorithm)
    edges -> list of directed edges
    v     -> number of vertices
    e     -> number of edges
*/
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    // Adjacency list
    unordered_map<int, list<int>> adj;

    // Build adjacency list
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int to = edges[i][1];
        adj[u].push_back(to);
    }

    // Indegree array
    vector<int> indegree(v, 0);

    for (auto i : adj)
    {
        for (auto j : i.second)
        {
            indegree[j]++;
        }
    }

    // Queue for nodes with 0 indegree
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // BFS
    vector<int> ans;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for (auto neighbour : adj[front])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }

    return ans;
}

int main()
{
    int v, e;
    cout << "Enter number of vertices and edges: ";
    cin >> v >> e;

    vector<vector<int>> edges(e, vector<int>(2));

    cout << "Enter directed edges (u v):\n";
    for (int i = 0; i < e; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<int> result = topologicalSort(edges, v, e);

    cout << "Topological Sort Order:\n";
    for (int node : result)
    {
        cout << node << " ";
    }

    return 0;
}
