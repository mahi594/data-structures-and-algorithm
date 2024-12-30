#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long int binarySearch(int n) {
        int s = 0;
        int e = n;
        long long int mid = s + (e - s) / 2;
        long long int ans = -1;

        while (s <= e) {
            long long int square = mid * mid;

            if (square == n) {
                return mid;
            } else if (square < n) {
                ans = mid;
                s = mid + 1;
            } else {
                e = mid - 1;
            }
            mid = s + (e - s) / 2;
        }
        return ans;
    }

    double morePrecision(int x,int presicion,int tempSol)
    {

    }
};

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    Solution sol;
    int tempSol= sol.binarySearch(num);
    cout << "The square root of " << num << " is: " << sol.morePrecision(num,3,tempSol) << endl;

    return 0;
}
