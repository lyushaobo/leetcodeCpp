#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    string s;
    while (getline(cin, s)) {
        string p;
        getline(cin, p);
        unordered_map<char, int> p_map;
        for (char ch : p) {
            if (p_map.find(ch) != p_map.end()) {
                p_map[ch]++;
            } else {
                p_map[ch] = 1;
            }
        }
        int p_size = p.size();
        int p_char = p_map.size();
        vector<int> ans;
        for (int i = 0; i < p_size; i++) {
            if (p_map.find(s[i]) != p_map.end()) {
                p_map[s[i]]--;
            }
        }
        for (auto e: p_map) {
            int val = e.second;
            if (val == 0)
            {
                p_char--;
            }
        }
        if (p_char == 0) {
            ans.push_back(0);
        }
        for (size_t i = p_size; i < s.size(); i++) {
            if (p_map.find(s[i-p_size])!=p_map.end()) {
                if(p_map[s[i-p_size]]++ == 0) {
                    p_char++;
                }
                if(p_map[s[i-p_size]] == 0) {
                    p_char--;
                }
            }
            if (p_map.find(s[i])!=p_map.end()) {
                if(p_map[s[i]]-- == 0) {
                    p_char++;
                }
                if(p_map[s[i]] == 0) {
                    p_char--;
                }
            }
            if (p_char == 0) {
                ans.push_back(i-p_size+1);
            }
        }
        for (auto num: ans)
        {
            cout << num << " ";
        }
        
        
    }
}