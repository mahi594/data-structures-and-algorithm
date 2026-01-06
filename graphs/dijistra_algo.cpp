#include <iostream>
#include <unordered_map> 
#include <list> 
#include <set>
#include <vector>
#include <climits>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    // Adjacency list
    unordered_map<int, list<pair<int,int>>> adj;

    // Create graph
    for(int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Distance array
    vector<int> dist(vertices, INT_MAX);

    // Set for Dijkstra
    set<pair<int,int>> st;

    dist[source] = 0;
    st.insert({0, source});

    while(!st.empty())
    {
        auto top = *st.begin();
        st.erase(st.begin());

        int nodeDistance = top.first;
        int node = top.second;

        for(auto neighbour : adj[node])
        {
            int adjNode = neighbour.first;
            int weight = neighbour.second;

            if(nodeDistance + weight < dist[adjNode])
            {
                auto record = st.find({dist[adjNode], adjNode});
                if(record != st.end())
                {
                    st.erase(record);
                }

                dist[adjNode] = nodeDistance + weight;
                st.insert({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}

int main()
{
    int vertices = 5;
    int edges = 6;

    vector<vector<int>> vec = {
        {0, 1, 2},
        {0, 3, 1},
        {1, 2, 3},
        {3, 2, 1},
        {1, 4, 5},
        {2, 4, 2}
    };

    int source = 0;

    vector<int> result = dijkstra(vec, vertices, edges, source);

    cout << "Shortest distances from source " << source << ":\n";
    for(int i = 0; i < vertices; i++)
    {
        cout << "Node " << i << " -> " << result[i] << endl;
    }

    return 0;
}
