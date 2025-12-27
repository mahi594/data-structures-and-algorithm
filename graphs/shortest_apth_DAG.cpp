#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
#include<climits>
using namespace std;

class Graph{
    public:
    unordered_map<int,list<pair<int,int>>> adj;

    void add_edge(int u,int v,int weight)
    {
        pair<int,int> p= make_pair(v,weight);
        adj[u].push_back(p); 
    }

    //print adjavent list
    void printAdj()
    {
        for(auto i: adj)
        {
            cout<<i.first<<"->";
            for(auto j: i.second)
            {
                cout<<"["<<j.first<<" , "<<j.second<<"]";            }
        }
        cout<<endl;
    }


    //dfs
    void dfs(int node,unordered_map<int,bool>&visi,stack<int> &topo)
    {
        visi[node]=true;

        for(auto neighbour:adj[node])
        {
            if(!visi[neighbour.first])
            {
                dfs(neighbour.first,visi,topo);
            }
        }
        topo.push(node);
    }



    //to find the shoretest distance
    void getShortestPath(int src,vector<int> &dist, stack<int> &topo)
    {
       dist[src]=0;

       while(!topo.empty())
      {
        int top=topo.top();
        topo.pop();
        
        if(dist[top]!=INT_MAX)
        {
            for(auto i: adj[top])
            {
                if(dist[top]+ i.second< dist[i.first])
                {
                    dist[i.first]= dist[top]+ i.second;
                }
            }
        }
      }
    } 

};

int main()
{
    Graph g;
    g.add_edge(0,1,5);
    g.add_edge(0,2,3);
    g.add_edge(1,3,6);
    g.add_edge(1,2,2);
    g.add_edge(2,3,7);
    g.add_edge(2,4,4);
    g.add_edge(2,5,2);
    g.add_edge(3,4,-1);
    g.add_edge(4,5,-2);
     
    g.printAdj();



    //topological sort
    int n=6;
    unordered_map<int,bool>visited;
    stack<int>s;
    for(int i=0;i<n;i++)
    {
       if(!visited[i])
       {
        g.dfs(i,visited,s);
       }
    }

    //making distance vector
    int src=1;
    vector<int> dist(n);
    for(int i=0;i<n;i++)
    {
        dist[i]=INT_MAX;
    }

    g.getShortestPath(src,dist,s);

    //print ans
    for(int i=0;i<dist.size();i++)
    {
        cout<<dist[i]<<" ";
    }
    cout<<endl;



    

}