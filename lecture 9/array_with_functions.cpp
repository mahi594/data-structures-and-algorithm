#include<iostream>
using namespace std;


int print_array(int arr[] ,int size)
{
       cout<<"printing array"<<endl;
       for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"printing done"<<endl;
}

int main()
{   int size=15;

    int one[15]={2,7};
    print_array(one,size);

    int two[15]={0};
    print_array(two,size);

    int three[15]={1};
    print_array(three,size);
}