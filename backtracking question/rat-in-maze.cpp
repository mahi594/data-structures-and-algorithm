#include<iostream>
#include<vector>
using namespace std; 


bool isSafe(int newx,int newy,vector < vector < int >> & arr,vector<vector<bool>> &vis,int n)
{
    if((newx >= 0 && newx < n) && (newy >= 0 && newy < n) &&
        arr[newx][newy] == 1 && vis[newx][newy] == 0)
     {
         return true;
     }
     else
     {
         return false;
     }
}


void solve(int x,int y,vector < vector < int >> & arr,vector<vector<bool>> &vis,int n,vector<string> &ans,string path)
{
    //base case
    if(x==n-1 && y==n-1)   //reched to destination
    {
        ans.push_back(path);
        return;
    }

    //4 movement D,L,R,U

    //down
    if(isSafe(x+1,y,arr,vis,n))
    {
        vis[x][y]=1;
        solve(x+1,y,arr,vis,n,ans,path+'D');
        vis[x][y]=0;
    }

    //left
    if(isSafe(x,y-1,arr,vis,n))
    {
        vis[x][y]=1;
        solve(x,y-1,arr,vis,n,ans,path+'L');
        vis[x][y]=0;
    }

    //right
     if(isSafe(x,y+1,arr,vis,n))
    {
        vis[x][y]=1;
        solve(x,y+1,arr,vis,n,ans,path+'R');
        vis[x][y]=0;
    }

    //up
     if(isSafe(x-1,y,arr,vis,n))
    {
        vis[x][y]=1;
        solve(x-1,y,arr,vis,n,ans,path+'U');
        vis[x][y]=0;
    }
    

}



vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector<string> ans;
    vector<vector<bool>> visited(n,vector<bool>(n,0));
    string path="";

    if(arr[0][0]==0)   //when the first element is 0 so we cant start
    {
        return ans;
    }

    solve(0,0,arr,visited,n,ans,path);
}

int main()
{
    int n;
    cout << "Enter size of maze (n x n): ";
    cin >> n;

    vector<vector<int>> maze(n, vector<int>(n));

    cout << "Enter maze matrix (0 = blocked, 1 = open):\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> maze[i][j];
        }
    }

    vector<string> result = searchMaze(maze, n);

    if (result.empty())
        cout << "No path found!\n";
    else
    {
        cout << "All possible paths:\n";
        for (string path : result)
            cout << path << " ";
        cout << endl;
    }

    return 0;
}