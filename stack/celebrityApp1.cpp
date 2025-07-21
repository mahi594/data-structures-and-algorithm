#include<iostream>
using namespace std;

#define N 4

int findCelebrity(int M[N][N], int n) {
    for (int i = 0; i < n; i++) {
        bool isCelebrity = true;

        // Check if i knows anyone
        for (int j = 0; j < n; j++) {
            if (i != j && M[i][j] == 1) {
                isCelebrity = false;
                break;
            }
        }

        // Check if everyone knows i
        if (isCelebrity)
        {
            for (int j = 0; j < n; j++) {
                if (i != j && M[j][i] == 0) {
                    isCelebrity = false;
                    break;
                }
            }
        }

        if (isCelebrity)
            return i;
    }

    return -1; // No celebrity
}

int main() {
    int M[N][N] = {
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0},  // Person 2 is the celebrity
        {0, 1, 1, 0}
    };

    int celeb = findCelebrity(M, N);
    if (celeb == -1)
        cout << "No celebrity found\n";
    else
        cout << "Celebrity is person " << celeb << "\n";

    return 0;
}
