#include <iostream>
using namespace std;

// Function to print binary representation
void printBinary(int n) {
    unsigned int mask = 1 << 31; // Create a mask with the highest bit set (32-bit)
    for (int i = 0; i < 32; i++) {
        if (n & mask) {
            cout << "1";
        } else {
            cout << "0";
        }
        mask >>= 1; // Shift the mask to the right
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
