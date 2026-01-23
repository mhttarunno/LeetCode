class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        string ans = "";
        for (int i = 0; i < s.size(); ++i) {
            string words = "";
            while (i < s.size() && s[i] != ' ') {
                words += s[i];
                i++;
            }
            reverse(words.begin(), words.end());
            if (!words.empty()) {
                ans += " " + words;
            }
        }
        return ans.substr(1);
    }
};