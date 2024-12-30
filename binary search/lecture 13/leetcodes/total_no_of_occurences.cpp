#include<iostream>
using namespace std;

void readArray(int arr[], int size) {
    cout << "Enter array elements:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

int first_occurrence(int arr[], int size, int key) {
    int start = 0;
    int end = size - 1;
    int ans = -1;
    int mid = start + (end - start) / 2;
    while (start <= end) {
        
        if (arr[mid] == key) {
            ans = mid;
            end = mid - 1; // move left to find the first occurrence
        } else if (arr[mid] < key) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
        int mid = start + (end - start) / 2;
    }
    return ans;
}

int last_occurrence(int arr[], int size, int key) {
    int start = 0;
    int end = size - 1;
    int ans = -1;
    int mid = start + (end - start) / 2;
    while (start <= end) {
        
        if (arr[mid] == key) {
            ans = mid;
            start = mid + 1; // move right to find the last occurrence
        } else if (arr[mid] < key) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
        int mid = start + (end - start) / 2;
    }
    return ans;
}

int main() {
    int size;
    cout << "Enter size: ";
    cin >> size;

    int arr[50];
    readArray(arr, size);

    int key;
    cout << "Enter key: ";
    cin >> key;

    int total_occurences;
    total_occurences=(last_occurrence(arr,size,key)-first_occurrence(arr,size,key)) +1;
    cout<<"total occurences is"<<total_occurences;

    return 0;
}
