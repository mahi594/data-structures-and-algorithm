#include<iostream>
using namespace std;

int power(int n)
{
   //base case
   if(n==0)
   return 1;

   int smallerprb=power(n-1);
   int biggerprb=2*smallerprb;
   return biggerprb;

}

int main()
{
    int n;
    cin>>n;
    int ans=power(n);
    cout<<ans<<endl;

}