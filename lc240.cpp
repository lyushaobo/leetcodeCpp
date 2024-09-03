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
        bool ans = false;
        int left = 0, right = m * n -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int i = mid / n;
            int j = mid % n;
            if (matrix[i][j] == target) {
                ans = true;
                break;
            } else if (matrix[i][j] > target) {
                right = mid - 1;
            } else left = mid + 1;
        }
        cout << ans;
    }
}