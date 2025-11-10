#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class graph
{
    public:
    unordered_map<int,list<int>> adj;

    void addEdge(int u,int v,bool direction)
    {
        //direction -> 0 = undirected 
        //direction -> 1 = directed 

        // create an edge from u to v
        adj[u].push_back(v);

        if(direction==0)
        {
            adj[v].push_back(u);   // as undirected v to u
        }
    }


    void printAdjList()