#include <iostream>
#include <vector>
#include <algorithm>
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
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            int left = i + 1, right = n - 1;
            while (left < right) {
                if (nums[left] + nums[right] + nums[i] == 0) {
                ans.push_back({nums[i], nums[left], nums[right]});
                while (left < right && nums[left] == nums[left+1]) {
                    left++;
                }
                while (left < right && nums[right] == nums[right-1]) {
                    right--;
                }
                left++;
                right--;
                } else if (nums[left] + nums[right] + nums[i] > 0) {
                    right--;
                } else {
                    left++;
                }
            }
            while (i < n - 2 && nums[i] == nums[i+1])
            {
                i++;
            }
            
        }
        for (size_t i = 0; i < ans.size(); i++)
        {
            for (size_t j = 0; j < ans[0].size(); j++)
            {
                cout << ans[i][j];
            }
            cout << endl;
        }
        
        
        
    }
}