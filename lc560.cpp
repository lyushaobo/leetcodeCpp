#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    int count;
    cin >> count;
    while (count != -1) {
        vector<int> nums(count);
        for (int i = 0; i < count; i++)
        {
            cin >> nums[i];
        }
        int k;
        cin >> k;

        unordered_map<int, int> map;
        map[0] = 1; // 处理从0开始的子数组
        int sum = 0, ans = 0;

        for (int i = 0; i < count; i++) {
            sum += nums[i];
            // 如果sum - k在map中，说明之前有子数组的和为sum-k
            if (map.find(sum - k) != map.end()) {
                ans += map[sum - k];
            }
            // 更新map
            map[sum]++;
        }
        cout << ans << endl;
        cin >> count;
    }
}
