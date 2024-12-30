#include<iostream>
using namespace std;

int factorial(int n)
{
   //base case
   if(n==0)
   return 1;

   int smallerprb=factorial(n-1);
   int biggerprb=n*smallerprb;
   return biggerprb;

}

int main()
{
    int n;
    cin>>n;
    int ans=factorial(n);
    cout<<ans<<endl;

}