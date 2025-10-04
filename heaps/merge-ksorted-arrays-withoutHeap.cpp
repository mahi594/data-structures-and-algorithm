#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T; 
    cin >> T; 
    while (T--) {
        int K;
        cin >> K;
        vector<int> result;
        
        for (int i = 0; i < K; i++) {
            int n;
            cin >> n;
            for (int j = 0; j < n; j++) {
                int x;
                cin >> x;
                result.push_back(x);
            }
        }
        
        sort(result.begin(), result.end());
        
        for (int x : result) cout << x << " ";
        cout << endl;
    }
    return 0;
}
