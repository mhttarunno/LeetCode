class Solution {
public:
    vector<int> dp;
    int printF(vector<int>& v) {
        dp[0] = v[0];
        for (int i = 1; i < v.size(); ++i) {
            int pick = v[i];
            if (i > 1) pick += dp[i - 2];
            int notPick = dp[i - 1];
            dp[i] = max(pick, notPick);
        }
        return dp[v.size() - 1];
    }

    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];

        vector<int> tmp1(nums.begin() + 1, nums.end());
        vector<int> tmp2(nums.begin(), nums.end() - 1);

        dp.resize(tmp1.size());
        int op1 = printF(tmp1);

        dp.resize(tmp2.size());
        int op2 = printF(tmp2);

        return max(op1, op2);
    }
};
