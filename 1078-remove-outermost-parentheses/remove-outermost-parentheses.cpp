class Solution {
public:
    string removeOuterParentheses(string s) {
        int counter = 0;
        string ans = "";
        for (char ch : s) {
            if (ch == '(') {
                if (counter != 0) {
                    ans.push_back(ch);
                }
                counter++;
            } else {
                counter--;
                if (counter != 0) {
                    ans.push_back(ch);
                }
            }
        }
        return ans;
    }
};
