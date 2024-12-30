#include<iostream>
using namespace std;

class amount{
    public:
int calculate_notes(int amount)
{
    int notes=0;
    int num=1;
    switch(num)
    {
        case 1:
        notes=amount/100;
        amount=amount%100;
        cout<<"number of 100 notes used are"<<notes<<endl;

         case 2:
        notes=amount/50;
        amount=amount%50;
        cout<<"number of 50 notes used are"<<notes<<endl;

        case 3:
        notes=amount/20;
        amount=amount%20;
        cout<<"number of 20 notes used are"<<notes<<endl;

        case 4:
        notes=amount/1;
        amount=amount%1;
        cout<<"number of 1 notes used are"<<notes<<endl;
    }
}
};

int main() {
    int n;
    cout << "Enter the amount in rupees: ";
    cin >> n;
    amount obj;
    if(n>0)
    {
        obj.calculate_notes(n);
    }
    
    return 0;
}