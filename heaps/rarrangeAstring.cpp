#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <algorithm> // Required for std::max
#include <utility>   // Required for std::pair and std::make_pair

using namespace std;


string reArrangeString(string &s) {
    // Defines a pair to store {frequency, character}
    typedef pair<int, char> freqChar;
    int n = s.length();
    
    // 1. Count character frequencies using a map
    map<char, int> counts;
    for (char c : s) {
        counts[c]++;
    }

    // 2. Build a Max Heap with {frequency, character} pairs
    priority_queue<freqChar> maxHeap;
    int maxFreq = 0;

    for (auto it = counts.begin(); it != counts.end(); it++) {
    char character = it->first;
    int frequency = it->second;

    if (frequency > 0) {
        // Push {frequency, character} into the max heap
        maxHeap.push({frequency, character});
        if (frequency > maxFreq) {
            maxFreq = frequency;
        }
    }
}

    // 3. Check the maximum allowed frequency condition
    // Max allowed frequency is ceil(N / 2) or (N + 1) / 2
    int maxAllowedFreq = (n + 1) / 2;

    // If the maximum frequency is greater than the allowed limit, it's impossible.
    if (maxFreq > maxAllowedFreq) {
        return "not possible";
    }

    // 4. Greedily build the result string
    string result = "";

    // Continue as long as we have at least two elements to interleave
    while (maxHeap.size() >= 2) {
        // Get the two most frequent characters
        freqChar p1 = maxHeap.top();
        maxHeap.pop();
        freqChar p2 = maxHeap.top();
        maxHeap.pop();

        // Append them to the result string
        result += p1.second;
        result += p2.second;

        // Decrement their frequencies
        p1.first--;
        p2.first--;

        // Push back any characters whose frequency is still > 0
        if (p1.first > 0) {
            maxHeap.push(p1);
        }
        if (p2.first > 0) {
            maxHeap.push(p2);
        }
    }

    // 5. Handle the remaining character (only one character left if N is odd)
    if (!maxHeap.empty()) {
        result += maxHeap.top().second;
    }

    return result;
}

int main() {
    // --- Test Case 1: Possible ---
    string s1 = "aaabbc"; 
    string s1_copy = s1;
    string result1 = reArrangeString(s1_copy);
    cout << "Input: " << s1 << endl;
    cout << "Output: " << result1 << endl; // Expected: abacab or similar

    cout << "\n--------------------------------\n";

    // --- Test Case 2: Not Possible ---
    string s2 = "aaabc"; 
    string s2_copy = s2;
    string result2 = reArrangeString(s2_copy);
    cout << "Input: " << s2 << endl; // N=5, Max Allowed=(5+1)/2=3. 'a' count is 3. It should be possible.
    cout << "Output: " << result2 << endl; // Expected: abaca or similar (It should be possible since 3 is not > 3)
    
    cout << "\n--------------------------------\n";

    // --- Test Case 3: Impossible ---
    string s3 = "aaazzz";
    string s3_copy = s3;
    string result3 = reArrangeString(s3_copy); // N=6, Max Allowed=(6+1)/2=3.5 -> 3. 'a' count is 3, 'z' count is 3. Possible.
    cout << "Input: " << s3 << endl;
    cout << "Output: " << result3 << endl; // Expected: azazaz or similar

    cout << "\n--------------------------------\n";
    
    // --- Test Case 4: Actually Impossible ---
    string s4 = "aaaaabbb";
    string s4_copy = s4;
    string result4 = reArrangeString(s4_copy); // N=8, Max Allowed=(8+1)/2=4. 'a' count is 5 (5 > 4). Impossible.
    cout << "Input: " << s4 << endl;
    cout << "Output: " << result4 << endl; // Expected: not possible

    return 0;
}