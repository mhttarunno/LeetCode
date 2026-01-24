class Solution {
public:
    bool isAnagram(string s, string ss) {
        if (s.size() ^ ss.size()) {
            return false;
        }
        unordered_map<int, int> mp;
        for (int i = 0; i < s.size(); ++i) {
            mp[s[i]]++;
        }
        for (int i = 0; i < ss.size(); ++i) {
            if (mp.find(ss[i]) != mp.end()) {
                mp[ss[i]]--;
            } else {
                return false;
            }
        }
        for (auto& it : mp) {
            if (it.second != 0) {
                return false;
            }
        }
        return true;
    }
};