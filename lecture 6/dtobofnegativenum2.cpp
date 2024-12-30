#include <iostream>
using namespace std;

// Function to print binary representation
void printBinary(int n) {
    for (int i = 31; i >= 0; i--) {
        cout << ((n >> i) & 1);
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter a decimal number: ";
    cin >> n;

    cout << "Binary representation is: ";
    printBinary(n);

    return 0;
}
