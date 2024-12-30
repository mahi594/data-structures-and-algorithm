#include<iostream>
using namespace std;

void reachedhome(int src,int dest)
{
    //base case
    if(src==dest)
    {
        cout<<"reached"<<endl;
        return;
    }

    //processing
    src++;
    cout<<"sourse "<< src<<" destinaton "<< dest<<endl;

    //recursice call
    reachedhome(src,dest);
     
}

int main()
{
    int dest=10;
    int src=1;
    reachedhome(src,dest);
}