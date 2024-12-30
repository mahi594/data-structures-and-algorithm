#include<iostream>
#include<cmath>
using namespace std;

bool isprime(int n)
{
    for(int i=2;i<= sqrt(n);i++)
    {
        if(n%i==0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n;
    cin>>n;
    if (isprime(n))
    {
      cout<<"no. is prime"<<endl;
    }
    else{
        cout<<"no. is not prime"<<endl;
    }
}