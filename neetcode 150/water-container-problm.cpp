#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxvolume = 0;

        while (left < right) {
            int width = right - left;
            int currHeight = min(height[left], height[right]);
            int volume = width * currHeight;

            if (volume > maxvolume)
                maxvolume = volume;

            // Move the pointer with smaller height
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return maxvolume;
    }
};

int main() {
    Solution s;

    vector<int> heights = {
        1,7,1,1,1,1,2,5,12,3,
        500,50,7,8,4,7,38,9,10,12,6
    };

    cout << "Maximum water that can be stored: "
         << s.maxArea(heights) << endl;

    return 0;
}
