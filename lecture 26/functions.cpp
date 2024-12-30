#include<iostream>
using namespace std;

void print(int *p)
{
   cout<<p<<endl;
}


void update(int *p)
{
    // p=p+1;    //only uodate in this function not in main
    //cout<<"inside"<<p<<endl;
   
     *p=*p+1;      // uodate in this function as well in in main
   
    

}
int main()
{
    int value=5;
    int *p=&value;

   
    // print(p);
    
    // cout<<"before  "<<p<<endl;  //in this main function value is updated not bcoz of functions
    // update(p);
    // cout<<"after  "<<p<<endl;   //in this main function value is updated not bcoz of functions  

    cout<<"before  "<<*p<<endl; 
    update(p);
    cout<<"after  "<<*p<<endl;

}