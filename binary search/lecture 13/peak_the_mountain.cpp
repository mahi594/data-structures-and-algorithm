#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s = 0;
        int e = arr.size() - 1;
        int mid = s + (e - s) / 2;

        while (s < e) {
            if (arr[mid] < arr[mid + 1]) {
                s = mid + 1;
            } else {
                e = mid;
            }
            mid = s + (e - s) / 2;
        }
        return s;
    }
};

int main() {
    int size;
    cout << "Enter size: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid size. Size should be greater than 0." << endl;
        return 1;
    }

    vector<int> arr(50);
    cout << "Enter array elements:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    Solution sol;
    int peakIndex = sol.peakIndexInMountainArray(arr);
    cout << "The peak of the mountain array is at index: " << peakIndex << endl;

    return 0;
}
