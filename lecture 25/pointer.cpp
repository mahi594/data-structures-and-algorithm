#include<iostream>
using namespace std;

int main()
{
    int num=5;
    cout<<num<<endl;
    
    // address of operator

    cout<<"address "<<&num<<endl;

    int *ptr=&num;

    cout<<"address is "<<ptr<<endl;
    cout<<"value is "<<*ptr<<endl;

    cout<<"size of integer "<<sizeof(num)<<endl;
    cout<<"size of pointer    integer "<<sizeof(ptr)<<endl;
}