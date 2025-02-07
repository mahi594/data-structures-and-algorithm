#include<iostream>
using namespace std;

inline int getMax(int& a,int &b)    //
{
    return ;
}

int main()
{
    int a=1,b=2;
    int ans=0;

    // ans=getMax(a,b);
    ans=(a>b)?a:b;
    cout<<ans<<endl;

    a=a+3;
    b=b+1;
   
    // ans=getMax(a,b);
    ans=(a>b)?a:b;
    cout<<ans<<endl;
    

}