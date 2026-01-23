class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() ^ t.size()) {
            return false;
        }
        map<char, char> mp, mpp;
        for (int i = 0; i < s.size(); i++) {
            if (mp.count(s[i]) && mp[s[i]] != t[i])
                return false;
            if (mpp.count(t[i]) && mpp[t[i]] != s[i])
                return false;

            mp[s[i]] = t[i];
            mpp[t[i]] = s[i];
        }
        return true;
    }
};
