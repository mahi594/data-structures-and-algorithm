#include<iostream>
using namespace std;

int main()
{
    int num=5;
    int a=num;
    cout<<"before "<<num<<endl;
    a++;
    cout<<"after "<<num<<endl;

     int *ptr=&num;
     cout<<"before "<<num<<endl;
     (*ptr)++;
    cout<<"after "<<num<<endl;

    
    cout<<"ptr before "<<ptr<<endl;
    ptr++;
    cout<<"ptr after "<<ptr<<endl;


//copying a pointer
    int *q=ptr;
    cout<<ptr<<" - "<<q<<endl;
    cout<<*ptr<<" - "<<*q<<endl;


}