#include <iostream>
#include <vector>

using namespace std;

int main() {
    int count;
    cin >> count;
    while (count != -1) {
        vector<int> nums(count);
        for (int i = 0; i < count; i++) {
            cin >> nums[i];
        }
        int n = nums.size();
        int pre[n];
        pre[0] = 1;
        int suf[n];
        suf[n-1] = 1;
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i-1] * nums[i-1];
        }
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = suf[i+1] * nums[i+1];
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            ans.push_back(pre[i]*suf[i]);
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i];
        }
    }
}