#include<iostream>
using namespace std;

class leetcode2{
   public:
   int check( unsigned int n)
   {
    int count=0;
    while(n!=0)
    {
    //    checking last bit
    if(n&1)
    {
        count++;

    }
    n=n>>1;

    }
    return count;
   }
};

int main()
{
   unsigned int n;
    cout<<"enter a binary no.";
    cin>>n;
    leetcode2 obj;
    obj.check(n);
    return 0;
}