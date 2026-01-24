class Solution {
public:
    bool isAnagram(string s, string ss) {
        sort(s.begin(), s.end());
        sort(ss.begin(), ss.end());
        if (s == ss) {
            return true;
        } else {
            return false;
        }
    }
};