#include <iostream>
#include <climits>
using namespace std;

int find_max(int num[],int n)
{
    int maxi=INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxi=max(maxi,num[i]);   //predefinrd function for maximum
        // if(num[i]>max)
        // {
        //     max=num[i];
        // }
    }
    return maxi;
}

int find_min(int num[],int n)
{
    int min=INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if(num[i]<min)
        {
            min=num[i];
        }
    }
    return min;
}


int main()
{

    int size;
    cout << "enter the size of array" << endl;
    cin >> size;

    int num[100];

    for (int i = 0; i < size; i++)
    {
        cin >> num[i];
    }

    cout<<"maximum value is"<<find_max(num,size)<<endl;
    cout<<"minimum value is"<<find_min(num,size)<<endl;
}