#include<iostream>
using namespace std;

int main()
{
    int a[20]={1,2,3,4};
    cout<<&a<<endl;
    cout<<&a[0]<<endl;
    cout<<a<<endl;

    int *p=&a[0];
    cout<<p<<endl;
    cout<<*p<<endl;
    cout<<&p<<endl;

     int arr[20]={1,2,3,4};
    //  arr=arr=1;   error
     int *ptr=&arr[0];
     cout<<"->>>"<<ptr<<endl;
     ptr=ptr+1;
     cout<<ptr<<endl;
     }