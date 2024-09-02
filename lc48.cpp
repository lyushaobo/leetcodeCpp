#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n != -1) {
        vector<vector<int>> matrix(n);
        for (int i = 0; i < n; i++) {
            matrix[i].resize(n);
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        int n = matrix.size();
        int left = 0, right = n - 1;
        while (left < right) {
            for (int i = 0; i < right - left; i++) {
                int tmp = matrix[left][left+i];
                matrix[left][left+i] = matrix[right-i][left];
                matrix[right-i][left] = matrix[right][right-i];
                matrix[right][right-i] = matrix[left+i][right];
                matrix[left+i][right] = tmp;
            }
            left++;
            right--;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
}