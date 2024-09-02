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
        bool ans = false;
        cout << ans;
    }
}