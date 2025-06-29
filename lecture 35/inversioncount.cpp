#include <iostream>
using namespace std;

long long merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;     // left subarray
    int j = mid + 1;  // right subarray
    int k = left;
    long long inv_count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1);
            //Not just 1 inversion — all elements from arr[i] to arr[mid] are greater than arr[j].

//So we add (mid - i + 1) to inv_count. 
// All remaining elements in left subarray are greater
        } 

    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];
    for (int p = left; p <= right; p++) arr[p] = temp[p];

    return inv_count;
}

long long mergeSort(int arr[], int temp[], int left, int right) {
    long long inv_count = 0;
    if (left < right) {
        int mid = (left + right) / 2;

        inv_count += mergeSort(arr, temp, left, mid);
        inv_count += mergeSort(arr, temp, mid + 1, right);

        inv_count += merge(arr, temp, left, mid, right);
    }
    return inv_count;
}

long long countInversions(int arr[], int n) {
    int temp[n];
    return mergeSort(arr, temp, 0, n - 1);
}

// Driver
int main() {
    int arr[] = {2, 4, 1, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Inversion Count: " << countInversions(arr, n) << endl;
    return 0;
}
