#include<iostream>
#include<vector>
using namespace std;
 


void addsolution(vector<vector<int>> &board,vector<vector<int>> &ans,int n)
{
	vector<int> temp;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			temp.push_back(board[i][j]);
		}
	}

	ans.push_back(temp);
}




bool isSafe(int row,int col,vector<vector<int>> &board,int n)
{
	int x=row;
	int y=col;

   //for row
	while(y>=0)
	{
		if(board[x][y]==1)
		{
			return false;
		}
		y--;
	}

	 x=row;
	 y=col;

    //for up diagonal
    while(x>=0 && y>=0)
	{
		if(board[x][y]==1)
		{
			return false;
		}
		x--;
		y--;
	}

	 x=row;
	 y=col;

    //for down diagonal
    while(x<n && y>=0)
	{
		if(board[x][y]==1)
		{
			return false;
		}
		x++;
		y--;
	}

	return true;
	



}




void solve(int col,vector<vector<int>> &board,vector<vector<int>> &ans,int n)
{
	//base case
	if(col==n)
	{
		addsolution(board,ans,n);
		return;
	}


    //solve for one case rest all recursion will handle
	for(int row=0;row<n;row++)
	{
		if(isSafe(row,col,board,n))
		{
			//if placing queen is safe
			board[row][col]=1;
			solve(col+1,board,ans,n);
			//backtrack
			board[row][col]=0;
		}
	}

}


vector<vector<int>> nQueens(int n)
{
     vector<vector<int>> board(n,vector<int>(n,0));
	 vector<vector<int>> ans;

	 solve(0,board,ans,n);

	 return ans;	
}



int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<vector<int>> result = nQueens(n);

    cout << "\nAll possible solutions:\n";
    for (int k = 0; k < result.size(); k++) {
        cout << "Solution " << k + 1 << ":\n";
        for (int i = 0; i < n * n; i++) {
            cout << result[k][i] << " ";
            if ((i + 1) % n == 0)
                cout << endl;
        }
        cout << endl;
    }

    cout << "Total solutions = " << result.size() << endl;
    return 0;
}