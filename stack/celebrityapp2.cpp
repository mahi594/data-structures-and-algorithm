#include<iostream>
#include<stack>
#include<vector>
using namespace std;

bool know(vector<vector<int> >&m,int a,int b,int n)
{
   if(m[a][b]==1)
   {
    return true;
   }
   else{
    return false;
   }
}

int celebrity(vector<vector<int> >&m,int n)
{
    stack<int> s;
    for(int i=0;i<n;i++)
    {
        //push all the people
        s.push(i);
    }

    //step2:>>> while loop
    while(s.size() > 1)
    {
        int a= s.top();
        s.pop();

        int b=s.top();
        s.pop();

        //if a known b
        if(know(m,a,b,n))
        {
            s.push(b);   // a knows b → a can't be celeb
        }

         else 
        {
            s.push(a);   // a doesn't know b → b can't be celeb
        }
    }

    int candidate=s.top();   //single elemnt in stack
    //step 3::>> single element ,verify it
    
    //check row
    bool rowcheck=false;
    int zerocount=0;

    for(int i=0;i<n;i++)
    {
        if(m[candidate][i]==0)
        {
            zerocount++;
        }
    }

   //all zeros
    if(zerocount==n)
    {
        rowcheck=true;
    }


    //column check
    bool columncheck=false;
    int oneCount=0;
    for(int i=0;i<n;i++)
    {
        if(m[i][candidate]==1)
        {
            oneCount++;
        }
    }

    if(oneCount==n-1)
    {
        columncheck=true;
    }


    //step 4::>>
    if(rowcheck==true && columncheck==true)
    {
        return candidate;
    }

    else{
        return -1;
    }
}


int main()
{
    int n = 4;

    // Example matrix: person 2 is celebrity
    vector<vector<int>> m = {
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0},  // ← person 2 knows no one
        {0, 1, 1, 0}
    };

    int result = celebrity(m, n);

    if (result == -1)
        cout << "No celebrity found" << endl;
    else
        cout << "Celebrity is person " << result << endl;

    return 0;
}