#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n;
    cin >> m;
    cin >> n;
    while (m != -1) {
        vector<vector<int>> matrix(m);
        for (int i = 0; i < m; i++) {
            matrix[i].resize(n);
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        int left = 0, right = n - 1, top = 0, bottom = m - 1;
while (left <= right && top <= bottom) {
            for (int column = left; column <= right; column++) {
                ans.push_back(matrix[top][column]);
            }
            for (int row = top + 1; row <= bottom; row++) {
                ans.push_back(matrix[row][right]);
            }
            if (left < right && top < bottom) {
                for (int column = right - 1; column > left; column--) {
                    ans.push_back(matrix[bottom][column]);
                }
                for (int row = bottom; row > top; row--) {
                    ans.push_back(matrix[row][left]);
                }
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        for (int i = 0; i < m * n; i++) {
                cout << ans[i] << " ";
        }
    }
}