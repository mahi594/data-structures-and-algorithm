#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter a decimal number: ";
    cin >> n;
    
    int ans = 0;   
    int i = 1;

    while (n != 0)
    {
        int bit = (n & 1); // Get the last bit of n
        ans += bit * i;    // Construct the binary representation
        n = n >> 1;        // Shift n to the right by 1 bit
        i *= 10;           // Move to the next place value in the binary number
    }

    cout << "Answer is " << ans << endl;
    return 0;
}
