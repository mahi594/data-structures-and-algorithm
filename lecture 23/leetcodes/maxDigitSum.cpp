#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int maxSum = -1;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) { // Fix: j < n to prevent out-of-bounds
                if (getDigitSum(arr[i]) == getDigitSum(arr[j])) {
                    int sum = arr[i] + arr[j];
                    if (sum > maxSum) {
                        maxSum = sum;
                    }
                }
            }
        }

        return maxSum;
    }

private:
    int getDigitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};

// Main function
int main() {
    Solution obj;

    vector<int> arr = {18,43,36,13,7};  // Example input

    int result = obj.maximumSum(arr);

    cout << "Maximum Sum: " << result << endl;

    return 0;
}
