#include<iostream>
using namespace std;

int main()
{
    int arr[10]={2,5,4,7,8,9};
    cout<<"address of first memory block is"<<arr<<endl;
    cout<<"address of first memory block is"<<&arr[0]<<endl;
    cout<<*arr<<endl;
    cout<<*arr+1<<endl;
    cout<<*(arr+1)<<endl;

    int i=3;
    cout<<i[arr]<<endl;

    int a[10];
    int *ptr= &a[0];

    cout<<sizeof(a)<<endl;
    cout<<sizeof(*a)<<endl;
    cout<<sizeof(&a)<<endl;
    
    

    cout<<sizeof(ptr)<<endl;   //8
    cout<<sizeof(*ptr)<<endl;
    cout<<sizeof(&ptr)<<endl;   //8
     

     


     
}