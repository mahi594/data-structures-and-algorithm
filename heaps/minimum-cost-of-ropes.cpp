#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
  public:
    int minCost(vector<int>& arr) {
       int ans = 0;
       
       // Min-heap
       priority_queue<int, vector<int>, greater<int>> pq;
       
       // Push all elements into min-heap
       for(int val : arr) {
           pq.push(val);
       }
       
       // Keep combining until one rope remains
       while(pq.size() > 1) {
           int a = pq.top(); pq.pop();
           int b = pq.top(); pq.pop();
           
           int sum = a + b;
           ans += sum;
           
           pq.push(sum);
       }
       
       return ans;
    }
};

int main() {
    Solution sol;

    vector<int> arr = {4, 3, 2, 6};
    
    cout << "Minimum cost to connect ropes: " 
         << sol.minCost(arr) << endl;

    return 0;
}
