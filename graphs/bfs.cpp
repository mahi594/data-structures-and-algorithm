#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>
using namespace std;

// Create adjacency list
void predefinedlist(unordered_map<int, set<int>> &adjList, vector<pair<int, int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].insert(v);
        adjList[v].insert(u); // For undirected graph
    }
}

// BFS traversal
void bfs(unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);

        // Traverse all neighbours
        for (auto i : adjList[frontNode])
        {
            if (!visited[i])   // ✅ fixed: removed semicolon and added condition
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

// BFS function
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, set<int>> adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;

    predefinedlist(adjList, edges);

    // Traverse all components
    for (int i = 0; i < vertex; i++)   
    {
        if (!visited[i])
        {
            bfs(adjList, visited, ans, i);
        }
    }

    return ans;
}

// Main function
int main()
{
    int vertex = 5;
    vector<pair<int, int>> edges = {
        {0, 1}, {0, 2}, {1, 2}, {3, 4}
    };

    vector<int> result = BFS(vertex, edges);

    cout << "BFS Traversal: ";
    for (auto i : result)
        cout << i << " ";
    cout << endl;

    return 0;
}
