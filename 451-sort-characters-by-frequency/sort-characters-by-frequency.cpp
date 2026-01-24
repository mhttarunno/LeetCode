class Solution {
public:
    unordered_map<char, int> mp;
    string frequencySort(string s) {
        for (int i = 0; i < s.size(); ++i) {
            mp[s[i]]++;
        }
        auto cmp = [&](char a, char b) {
            if (mp[a] == mp[b]) {
                return a < b;
            }
            return mp[a] > mp[b];
        };
        sort(s.begin(), s.end(), cmp);
        return s;
    }
};