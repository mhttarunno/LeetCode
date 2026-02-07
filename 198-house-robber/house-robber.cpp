class Solution {
public:
    // Space Optimization:
    vector<int> dp;
    int printF(int idx, vector<int>& v) {
        int prev = 0, prev2 = 0;
        for (int i = 1; i <= v.size(); ++i) {
            int pick = v[i - 1];    
            if (i > 1) {
                pick += prev2;
            }
            int nonPick = 0 + prev;
            int curr = max(pick, nonPick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        dp.resize(nums.size() + 1, -1);
        return printF(nums.size() - 1, nums);
    }
};