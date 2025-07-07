#include<iostream>
using namespace std;

bool isPalindromeArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;

    while(start < end) {
        if(arr[start] != arr[end])
            {
                return false;
            }
        start++;
        end--;
    }
    return true;
}

int main() {
    int arr[] = {1, 2, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    if(isPalindromeArray(arr, n))
        cout << "Array is a palindrome" << endl;
    else
        cout << "Array is not a palindrome" << endl;
}
