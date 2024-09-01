#include <iostream>
#include <vector>

using namespace std;

int main() {
    int count;
    cin >> count;
    while (count != -1)
    {
        vector<int> nums(count);
        for (int i = 0; i < count; i++)
        {
            cin >> nums[i];
        }
        int n = nums.size();
        int ans = nums[0], sum = nums[0];
        for (int i = 1; i < n; i++) {
            if (sum < 0 && nums[i] >= sum) {
                sum = nums[i];
            } else {
                sum += nums[i];
            }
            ans = max(sum, ans);
        }
        cout << ans;
        
    }
    
}