#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        int deficit = 0;
        int balance = 0;
        int start = 0;

        for (int i = 0; i < gas.size(); i++) {
            balance += gas[i] - cost[i];

            if (balance < 0) {
                deficit += balance;
                start = i + 1;
                balance = 0;
            }
        }

        if (balance + deficit >= 0) {
            return start;
        } else {
            return -1;
        }
    }
};

int main() {
    Solution obj;
    
    // Sample test case
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    
    int result = obj.startStation(gas, cost);
    cout << "Starting Station Index: " << result << endl;

    return 0;
}
