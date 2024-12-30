#include <iostream>
#include <cstdlib> // Required for the exit function

using namespace std;

int main() {
    int choice;

    while (true) {
        cout << "Enter a number (1 to 3) or 0 to exit: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "You selected option 1" << endl;
                break;
            case 2:
                cout << "You selected option 2" << endl;
                break;
            case 3:
                cout << "You selected option 3" << endl;
                break;
                
            case 0:
                // This block is executed when the user enters 0
                cout << "Exiting the program..." << endl; // Inform the user
                exit(0); // Terminate the program with status code 0
            default:
                cout << "Invalid choice, try again." << endl;
        }
        
    }

    return 0;
}
