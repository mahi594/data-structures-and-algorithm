#include<iostream>
using namespace std;

int power(int n)
{
    //base case
    if(n==0)
    {
        return 1;
    }

    // int smaller=power(n-1);
    // int bigger= 2*smaller;

    // return bigger;

    return 2 *power(n-1);

}


int main()
{
    int n;
    cin>>n;

    int ans=power(n);

    cout<<ans<<endl;
}