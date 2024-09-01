#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

int main()
{
    string s;
    while (getline(cin, s)) {
        unordered_set<char> set;
        queue<char> q;
        int ans = 0;
        for (char ch : s) {
            if (set.find(ch) == set.end()) {
                set.insert(ch);
                q.push(ch);
                ans = max(ans, (int)set.size());
            } else {
                while (!q.empty() && q.front() != ch) {
                    set.erase(q.front());
                    q.pop();
                }
                if (!q.empty()) {
                    q.pop(); // Remove the duplicate character
                }
                q.push(ch); // Add the current character
            }
        }
        cout << ans;
    }
}