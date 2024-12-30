#include <iostream>

using namespace std;

int main() {
    int choice;
        
    while (true) {
        cout << "Enter a number (1 to 3) or 0 to exit: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "You selected option 1" << endl;
                continue;
            case 2:
                cout << "You selected option 2" << endl;
                continue;
            case 3:
                cout << "You selected option 3" << endl;
               continue;
                
           
            default:
                cout << "Invalid choice, try again." << endl;
        }
      
        
    }

    return 0;
}
