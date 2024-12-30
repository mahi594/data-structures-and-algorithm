#include<iostream>
using namespace std;

int climbStairs(int n)
{
    // base cases
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;

    // recursive call
    int ans=climbStairs(n - 1) + climbStairs(n - 2);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int ans=climbStairs(n);
    cout<<ans<<endl;

    
}
