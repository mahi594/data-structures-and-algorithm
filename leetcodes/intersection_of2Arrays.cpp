#include<iostream>
#include<vector>

using namespace std;

//optimised solution 1

// vector<int> findArrayIntersection(vector<int>& arr1, int n, vector<int>& arr2, int m)
// {
//     vector<int> ans;
//     for(int i = 0; i < n; i++)
//     {
//         int element = arr1[i];
//         for(int j = 0; j < m; j++)
//         {   if(element<arr[j])
//               {
  //                    break;
//                 }
//             else if(element == arr2[j])
//             {
//                 ans.push_back(element);
//                 arr2[j] = -123456789;
//                 break;
//             }
//         }
//     }
//     return ans;
// }


//optimised soliution 2

vector<int> findArrayIntersection(vector<int>& arr1, int n, vector<int>& arr2, int m)
{
    vector<int> ans;
    int i=0,j=0;
    while(i<n&&j<m)
    {
        if(arr1[i]==arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;
            j++;

        }
        else if(arr1[i]<arr2[j])
        {
            i++;
        }
        else{
            j++;
        }

    }
    return ans;
}

    


int main()
{
    int n, m;
    cout << "Enter the size of the first array: ";
    cin >> n;
    vector<int> arr1(n);
    cout << "Enter the elements of the first array: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    
    cout << "Enter the size of the second array: ";
    cin >> m;
    vector<int> arr2(m);
    cout << "Enter the elements of the second array: ";
    for(int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    
    vector<int> intersection = findArrayIntersection(arr1, n, arr2, m);
    
    cout << "The intersection of the two arrays is: ";
    for(int i = 0; i < intersection.size(); i++)
    {
        cout << intersection[i] << " ";
    }
    cout << endl;
    
    return 0;
}
