#include<iostream>
using namespace std;

void update(int num[],int size)
{
    num[0]=120; //updating an array
    cout<<"inside update function"<<endl;
 for(int i=0;i<3;i++)
    {
           cout<<num[i]<<endl;
    }
     cout<<endl;

     cout<<"going in main function"<<endl;

}

int main()
{
    int array[3]= { 3,5,8};

    update(array,3);

    for(int i=0;i<3;i++)
    {
           cout<<array[i]<<endl;
    }

    cout<<endl;
}