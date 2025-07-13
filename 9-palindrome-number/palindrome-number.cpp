class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        string ss = s;
        reverse(ss.begin(), ss.end());
        if(s == ss) {
            return true;
        } else {
            return false;
        }
    }
};