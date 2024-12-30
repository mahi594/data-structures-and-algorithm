#include <iostream>
#include<math.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter a decimal number: ";
    cin >> n;
    // int ans=0;
    // The pow function returns a floating-point number, but you are working with integers. This can lead to inaccuracies and is unnecessary for this problem.
    float ans = 0;
    int i = 0;

    while (n != 0)
    {
        int bit = (n & 1); // Get the last bit of n
        ans = (bit * pow(10, i)) + ans; // Calculate the binary representation
        n = n >> 1; // Shift n to the right by 1 bit
        i++;
    }

    cout << "Answer is " << ans << endl;
    return 0;
}
