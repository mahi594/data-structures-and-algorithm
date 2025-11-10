#include <iostream>
#include <vector>
using namespace std;

// Function to build and return adjacency list
vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>> &edges) {
    // Create an array of vectors to store adjacency information of all indexes
    vector<int> adjList[n];   //edges to edges list

    // Build the adjacency list
    for (int i = 0; i < m; i++) 
    {
        int u = edges[i][0];    // starting vertex
        int v = edges[i][1];   // ending vertex

        // Since it's an undirected graph, add both connections
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Prepare the final adjacency list format
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        // First push the node itself
        adj[i].push_back(i);

        // Then push all its adjacent nodes
        for (int j = 0; j < adjList[i].size(); j++) {
            adj[i].push_back(adjList[i][j]);
        }
    }

    return adj;
}

int main() {
    int n, m;
    cout << "Enter number of vertices (n): ";
    cin >> n;
    cout << "Enter number of edges (m): ";
    cin >> m;

    vector<vector<int>> edges(m, vector<int>(2));  // m is rows and 2 colulmns

    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    // Get adjacency list
    vector<vector<int>> result = printAdjacency(n, m, edges);

    // Print the adjacency list
    cout << "\nAdjacency List:\n";
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
