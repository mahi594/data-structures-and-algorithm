#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool isSafe(int x, int y, int n, vector<vector<int>> &visited, vector<vector<int>> &m) {
    return (x >= 0 && x < n && y >= 0 && y < n && visited[x][y] == 0 && m[x][y] == 1);
}

void solve(vector<vector<int>> &m, int n, vector<string> &ans, int x, int y,
           vector<vector<int>> &visited, string path) {
    
    if (x == n - 1 && y == n - 1) {
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    // Down
    int newx = x + 1, newy = y;
    if (isSafe(newx, newy, n, visited, m)) {
        path.push_back('D');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // Left
    newx = x, newy = y - 1;
    if (isSafe(newx, newy, n, visited, m)) {
        path.push_back('L');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // Right
    newx = x, newy = y + 1;
    if (isSafe(newx, newy, n, visited, m)) {
        path.push_back('R');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    // Up
    newx = x - 1, newy = y;
    if (isSafe(newx, newy, n, visited, m)) {
        path.push_back('U');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    visited[x][y] = 0; // Backtrack
}

vector<string> findPath(vector<vector<int>> &m, int n) {
    vector<string> ans;

    if (m[0][0] == 0) return ans;

    vector<vector<int>> visited(n, vector<int>(n, 0));
    string path = "";
    solve(m, n, ans, 0, 0, visited, path);
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    int n = maze.size();

    vector<string> paths = findPath(maze, n);

    if (paths.empty()) {
        cout << "No path found.\n";
    } else {
        cout << "Paths from source to destination:\n";
        for (string path : paths) {
            cout << path << endl;
        }
    }

    return 0;
}
