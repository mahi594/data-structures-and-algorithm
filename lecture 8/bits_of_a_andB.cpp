#include<iostream>
using namespace std;

int bits_of_a_and_b()
{
    int a,b;
    cout<<"a is";
    cin>>a;
    cout<<"b is";
    cin>>b;
    int bit1=0,bit2=0;
    int total_bits;

   
   while(a!=0)
{
    if(a&1)
    {
        bit1++;

    }
    a>>1;
   }
   cout<<"total bits of a is"<<bit1<<endl;

    while(b!=0)
{
    if(b&1)
    {
        bit2++;

    }
    b>>1;
   }
   cout<<"total bits of a is"<<bit2<<endl;

   total_bits=bit1+bit2;

  return total_bits;

}

int main()
{
    int answer= bits_of_a_and_b();
    cout<<"answer is"<<answer;
    return 0;

}