#include<iostream>
using namespace std;

int main()
{
    int a, b;
    cout << "Enter value of a: ";
    cin >> a;
    cout << "Enter value of b: ";
    cin >> b;

    int choice;
    int ans;

    cout << "Enter your choice (1 for addition, 2 for subtraction, 3 for multiplication, 4 for division): ";
    cin >> choice;

    switch (choice)
    {
        case 1:
            ans = a + b;
            cout << "Result is: " << ans << endl;
            break;

        case 2:
            ans = a - b;
            cout << "Result is: " << ans << endl;
            break;

        case 3:
            ans = a * b;
            cout << "Result is: " << ans << endl;
            break;

        case 4:
            if (b != 0)
            {
                ans = a / b;
                cout << "Result is: " << ans << endl;
            }
            else
            {
                cout << "Division by zero is not allowed." << endl;
            }
            break;

        default:
            cout << "Invalid choice." << endl;
            break;
    }

    return 0;
}
