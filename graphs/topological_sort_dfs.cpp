#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <list>
using namespace std;

/*
    DFS function for Topological Sort
    node    -> current node
    visited -> keeps track of visited nodes
    s       -> stack to store topological order
    adj     -> adjacency list
*/
void toposort(int node,
              unordered_map<int, bool> &visited,
              stack<int> &s,
              unordered_map<int, list<int>> &adj)
{
    // mark current node as visited
    visited[node] = true;

    // visit all neighbours
    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            toposort(neighbour, visited, s, adj);
        }
    }

    // push node after visiting all neighbours
    s.push(node);
}

/*
    Function to perform Topological Sort
    edges -> list of directed edges
    v     -> number of vertices
    e     -> number of edges
*/
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    // create adjacency list
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    // visited map and stack
    unordered_map<int, bool> visited;
    stack<int> s;

    // call DFS for all nodes
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            toposort(i, visited, s, adj);
        }
    }

    // store result
    vector<int> ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}

int main()
{
    int v, e;
    cout << "Enter number of vertices and edges: ";
    cin >> v >> e;

    vector<vector<int>> edges(e, vector<int>(2));

    cout << "Enter edges (u v):\n";
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
