#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findPivot(vector<int>& arr) {
        int s = 0;
        int e = arr.size() - 1;
        
        while (s < e) {
            int mid = s + (e - s) / 2;
            
            // If mid element is greater than the end element,
            // then the pivot is in the right half.

            // if (arr[mid] > arr[e]) 
            
            if(arr[mid]>=arr[0]){
                s = mid + 1;
            }
            // Otherwise, the pivot is in the left half (including mid).
            else {
                e = mid;
            }
        }
        // At the end of the loop, s will point to the pivot element.
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

    vector<int> arr(size);
    cout << "Enter array elements:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    Solution sol;
    int pivotIndex = sol.findPivot(arr);
    cout << "The pivot of the array is at index: " << pivotIndex << endl;
    cout << "The pivot element is: " << arr[pivotIndex] << endl;

    return 0;
}
