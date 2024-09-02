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
        int zeroPtr = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                if (i > zeroPtr) {
                    nums[zeroPtr] = nums[i];
                    nums[i] = 0;
                }
                zeroPtr++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << nums[i];
        }
        
        
    }
}