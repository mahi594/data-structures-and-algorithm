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
    {
        for(auto i:adj)
        {
            cout<<i.first<<"->";
            for(auto j:i.second)
            {
                cout<< j <<",";
            }
            cout<<endl;
        }
    }
};

int main()
{
    int n;
    cout<<"enter the no. of nodes"<<endl;
    cin>>n;

    int e;
    cout<<"enter the no. of edges"<<endl;
    cin>>e;

    graph g;

    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        //creating the graph
        g.addEdge(u,v,0);
    }

    //printing graph
    g.printAdjList();




}