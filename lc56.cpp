#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a1, vector<int> a2) {
    return a1[0] < a2[0];
}

int main() {
    int count;
    cin >> count;
    while (count != -1)
    {
        vector<vector<int>> intervals(count);
        for (int i = 0; i < count; i++)
        {
            intervals[i].resize(2);
            for (int j = 0; j < 2; j++) cin >> intervals[i][j];
        }
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), cmp);
        int beginNum = intervals[0][0], endNum = intervals[0][1];
        for (int i = 1; i < n; i++) {
            if (endNum >= intervals[i][0]) {
                endNum = max(endNum, intervals[i][1]);
            } else {
                ans.push_back({beginNum, endNum});
                beginNum = intervals[i][0], endNum = intervals[i][1];
            }
        }
        ans.push_back({beginNum, endNum});
        for (size_t i = 0; i < ans.size(); i++)
        {
            for (size_t j = 0; j < 2; j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
        
    }
    
}