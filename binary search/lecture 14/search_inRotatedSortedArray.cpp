#include<iostream>
#include<vector>
using namespace std;

int findPivot(vector<int>& arr, int n) {
    int s = 0;
    int e = n - 1;
    
    while (s < e) {
        int mid = s + (e - s) / 2;
        
        // If mid element is greater than the end element,
        // then the pivot is in the right half.
        if (arr[mid] > arr[e]) {
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

int binarySearch(vector<int>& arr, int s, int e, int key) {
    int start = s;
    int end = e;
    
    while (start <= end) {
        int mid = start + (end - start) / 2;
        
        if (arr[mid] == key) {
            return mid;
        }
        if (key > arr[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return -1;
}

int search(vector<int>& arr, int n, int target) {
    int pivot = findPivot(arr, n);
    if (target >= arr[pivot] && target <= arr[n - 1]) {
        return binarySearch(arr, pivot, n - 1, target);
    } else {
        return binarySearch(arr, 0, pivot - 1, target);
    }
}

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

    int k;
    cout<<"target element is"<<endl;
    cin>>k;


    int targetIndex = search(arr,size,k);
    cout << "The pivot of the array is at index: " << targetIndex << endl;
    cout << "The pivot element is: " << arr[targetIndex] << endl;

    return 0;
}