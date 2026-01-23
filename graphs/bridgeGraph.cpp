#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

/*
 DFS function to find bridges
 node      → current node where DFS is running
 parent    → node from which DFS came
 timer     → global discovery time counter
 disc[]    → discovery time of each node
 low[]     → lowest discovery time reachable
 visited[] → marks visited nodes
 adj       → adjacency list
 result    → stores bridges
*/
void dfs(
    int node,
    int parent,
    int &timer,
    vector<int> &disc,
    vector<int> &low,
    unordered_map<int, bool> &visited,
    unordered_map<int, list<int>> &adj,
    vector<vector<int>> &result
) {
    // Mark current node as visited
    visited[node] = true;

    // Set discovery time and low value
    disc[node] = low[node] = timer++;
    
    // Traverse all neighbours of current node
    for (auto neighbour : adj[node]) {

        // Ignore the edge back to parent
        if (neighbour == parent)
            continue;

        // If neighbour is not visited → DFS tree edge
        if (!visited[neighbour]) {

            dfs(neighbour, node, timer, disc, low, visited, adj, result);

            // After returning, update low value of current node
            low[node] = min(low[node], low[neighbour]);

            // BRIDGE CONDITION
            // If neighbour cannot reach an ancestor of node
            if (low[neighbour] > disc[node]) {
                result.push_back({node, neighbour});
            }
        }
        // If neighbour is visited and not parent → back edge
        else {
            low[node] = min(low[node], disc[neighbour]);
        }
    }
}

/*
 Function to find all bridges
 edges → list of edges
 v     → number of vertices
*/
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v) {

    // Adjacency list
    unordered_map<int, list<int>> adj;

    // Build graph (undirected)
    for (auto &edge : edges) {
        int u = edge[0];
        int vtx = edge[1];
        adj[u].push_back(vtx);
        adj[vtx].push_back(u);
    }

    vector<int> disc(v, -1);   // discovery time
    vector<int> low(v, -1);    // low value
    unordered_map<int, bool> visited;
    vector<vector<int>> result;

    int timer = 0;

    // Run DFS for all components
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            dfs(i, -1, timer, disc, low, visited, adj, result);
        }
    }

    return result;
}

int main() {

    // Example graph (your graph)
    // Left cycle: 0-1-2
    // Right cycle: 3-4-5
    // Bridge: 0-4
    vector<vector<int>> edges = {
        {0,1}, {1,2}, {2,0},
        {0,4},
        {4,3}, {3,5}, {5,4}
    };

    int vertices = 6;

    vector<vector<int>> bridges = findBridges(edges, vertices);

    cout << "Bridges in the graph:\n";
    for (auto &b : bridges) {
        cout << b[0] << " - " << b[1] << endl;
    }

    return 0;
}
