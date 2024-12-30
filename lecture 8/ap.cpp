#include<iostream>
using namespace std;
int print_ap()
{
    int a,d;
    cout<<"first term is";
    cin>>a;
    cout<<"difference is is";
    cin>>d;
    int n;
    cout<<"total terms we need";
    cin>>n;
     int ap;
    for(int i=0;i<n;i++)
    {
        ap= (a+(i*d));
        cout<<ap<<" ";
    }
    return ap;
}


int main()
{
    int answer;
    answer=print_ap();
    
}

