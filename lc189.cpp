#include <iostream>
#include <vector>

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

        int n = nums.size();
        k = k % n;
        for (int i = 0; i < n / 2; i++) {
            int tmp = nums[i];
            nums[i] = nums[n-i-1];
            nums[n-i-1] = tmp;
        }
        for (int i = 0; i < k / 2; i++) {
            int tmp = nums[i];
            nums[i] = nums[k-i-1];
            nums[k-i-1] = tmp;
        }
        for (int i = k; i < k + (n - k) / 2; i++) {
            int tmp = nums[i];
            nums[i] = nums[n-1-i+k];
            nums[n-1-i+k] = tmp;
        }
        for (size_t i = 0; i < nums.size(); i++)
        {
            cout << nums[i] << " ";
        }
        
    }
}
