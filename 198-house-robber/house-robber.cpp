class Solution {
public:
    vector<int> dp;
    int printF(int idx, vector<int>& v) {
        if (idx == 0) return v[idx];
        if (idx < 0) return 0;
        if (dp[idx] != -1) return dp[idx];
        int pick = v[idx] + printF(idx - 2, v);
        int nonPick = printF(idx - 1, v);
        return dp[idx] = max(pick, nonPick);
    }
    int rob(vector<int>& nums) {
        dp.resize(nums.size() + 1, -1);
        return printF(nums.size() - 1, nums);
    }
};