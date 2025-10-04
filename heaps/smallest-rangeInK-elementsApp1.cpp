#include <iostream>
#include <vector>
#include <climits>
#include <utility>
using namespace std;

pair<int, int> smallestRange(vector<vector<int>> &lists) 
{
    int k = (int)lists.size();

    pair<int, int> smallest = {0, INT_MAX}; // start with a safe large range

    for (int i = 0; i < k; i++)
    {
        for (int a : lists[i]) 
        {
            for (int j = 0; j < k; j++) {
                for (int b : lists[j]) {
                    int L = min(a, b);
                    int R = max(a, b);

                    bool valid = true;
                    for (int p = 0; p < k; p++) {
                        bool found = false;
                        for (int val : lists[p]) {
                            if (L <= val && val <= R) {
                                found = true;
                                break;
                            }
                        }
                        if (!found) {
                            valid = false;
                            break;
                        }
                    }

                    if (valid && (R - L) < (smallest.second - smallest.first)) {
                        smallest = {L, R};
                    }
                }
            }
        }
    }
    return smallest;
}

int main() {
    vector<vector<int>> lists = {
        {4, 10, 15, 24, 26},
        {0, 9, 12, 20},
        {5, 18, 22, 30}
    };

    pair<int, int> ans = smallestRange(lists);
    cout << "Smallest Range: [" << ans.first << ", " << ans.second << "]\n";

    return 0;
}
