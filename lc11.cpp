#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums;
    int n = 1;
    while (n < 10000) { // 注意 while 处理多个 case
        cin >> n;
        nums.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i]; //将输入值存入容器
        }
        int leftPtr = 0, rightPtr = n-1;
        int ans = 0;
        while (leftPtr < rightPtr) {
            ans = max(ans, min(nums[leftPtr], nums[rightPtr]));
        }
        for (int i = 0; i < n; i++)
        {
            cout << ans;
        }
        
        
    }
}