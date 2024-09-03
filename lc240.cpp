#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n;
    cin >> m;
    cin >> n;
    while (m != -1) {
        vector<vector<int>> matrix(m);
        int target;
        for (int i = 0; i < m; i++) {
            matrix[i].resize(n);
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        cin >> target;
        int m = matrix.size();
        int n = matrix[0].size();
        int x = 0, y = n-1;
        bool ans = false;
        while (x < m && y >= 0) {
            if (matrix[x][y] == target) {
                ans =  true;
            }
            if (matrix[x][y] > target) {
                y--;
            } else x++;
        } 
        cout << ans;
    }
}