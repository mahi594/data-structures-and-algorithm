#include <iostream>
using namespace std;

int main()
{
    int size;
    cout << "size is" << endl;
    cin >> size;

    int array[50];
    int sum = 0;
    
    cout << "array members are" << endl;


    for (int i = 0; i < size; i++)
    {

        cin >> array[i];
        sum = sum + array[i];
    }

    cout << "sum is" << sum << endl;
}