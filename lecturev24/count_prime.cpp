#include<iostream>
using namespace std;

bool isPrime(int n)
{
    if(n<=1)
    {
        return false;
    }
    for(int i=2;i<n;i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}

int countPrime(int n)
{
    int count=0;
    for(int i=2;i<n;i++)
    {
        if(isPrime(i))
        {
            cout<<i<<" ";
            count++;
        }
    }
    return count;
}

int main()
{
    int n;
    cin>>n;

    countPrime(n);
    return 0;
}



//this is giving tle>>>>>>...
//complexity O(n^2)

