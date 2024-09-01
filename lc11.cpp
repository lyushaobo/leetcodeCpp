#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> height;
    int n = 1;
    while (n < 10000) { // 注意 while 处理多个 case
        cin >> n;
        height.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> height[i]; //将输入值存入容器
        }
        int leftPtr = 0, rightPtr = n-1;
        int ans = 0;
        while (leftPtr < rightPtr) {
            int minVal;
            if (height[leftPtr] > height[rightPtr]) {
                minVal = height[rightPtr--];
            } else {
                minVal = height[leftPtr++];
            }
            ans = max(ans, minVal * (rightPtr - leftPtr + 1));
        }
        for (int i = 0; i < n; i++)
        {
            cout << ans;
        }
        
        
    }
}