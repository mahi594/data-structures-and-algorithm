#include<iostream>
using namespace std;

int gcd(int a, int b) {
    int gcd = 1;  // Initialize GCD as 1 (smallest possible GCD)
    for (int i = 1; i <= (a < b ? a : b); i++) {
        if (a % i == 0 && b % i == 0) {
            gcd = i;  // Update GCD if both a and b are divisible by i
        }
    }
    return gcd;
}

int main() {
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    cout << "GCD of " << num1 << " and " << num2 << " is: " << gcd(num1, num2) << endl;

    return 0;
}



// i <= (a < b ? a : b)
// if (a < b) 
//{
//     limit = a;
// } else {
//     limit = b;
// }

// for (int i = 1; i <= limit; i++) {
//     // loop body
// }
