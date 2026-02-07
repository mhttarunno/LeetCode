class Solution {
public:
    // Tabulation:
    vector<int> dp;
    int printF(int idx, vector<int>& v) {
        dp[0] = 0;
        for (int i = 1; i <= v.size(); ++i) {
            int pick = v[i - 1];
            if(i > 1) {
                pick += dp[i - 2];
            }
            int nonPick = 0 + dp[i - 1];
            dp[i] = max(pick, nonPick);
        }
        return dp[v.size()];
    }
    int rob(vector<int>& nums) {
        dp.resize(nums.size() + 1, -1);
        return printF(nums.size() - 1, nums);
    }
};