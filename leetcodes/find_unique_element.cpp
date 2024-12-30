// #include <iostream>

// int findUnique(int arr[], int size) {
//     for (int i = 0; i < size; i++) {
//         int count = 0;
//         for (int j = 0; j < size; j++) {
//             if (arr[i] == arr[j]) {
//                 count++;
//             }
//         }
//         if (count == 1) {
//             return arr[i];
//         }
//     }
//     // If no unique element is found, return -1 or some error value
//     return -1;
// }

// int main() {
//     int arr[] = {2, 3, 5, 4, 5, 3, 4};
//     int size = sizeof(arr) / sizeof(arr[0]);
//     int uniqueElement = findUnique(arr, size);
//     if (uniqueElement != -1) {
//         std::cout << "The unique element is: " << uniqueElement << std::endl;
//     } else {
//         std::cout << "No unique element found." << std::endl;
//     }
//     return 0;
// }


#include <iostream>
using namespace std;

int printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << endl;
}


int findUnique(int arr[], int size)
 {
    int ans=0;
    for (int i = 0; i < size; i++) 
    {
       ans=ans^arr[i]; 
        
}
return ans;
}



int main()
{
    int size;
    cout << "size is" << " ";
    cin >> size;

    int arr[50];

    printArray(arr, size);

    int unique=findUnique(arr, size);
    cout<<"unique element is"<<unique;

    
}
