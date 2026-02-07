class Solution {
public:
    vector<int> dp;
    int printF(int idx, vector<int>& v) {
        if (idx == 0)
            return v[idx];
        if (idx < 0)
            return 0;
        if (dp[idx] != -1)
            return dp[idx];
        int pick = v[idx] + printF(idx - 2, v);
        int notPick = printF(idx - 1, v);
        return dp[idx] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];

        vector<int> tmp1(nums.begin() + 1, nums.end());
        vector<int> tmp2(nums.begin(), nums.end() - 1);

        dp.assign(tmp1.size() + 1, -1);
        int op1 = printF(tmp1.size() - 1, tmp1);

        dp.assign(tmp2.size() + 1, -1);
        int op2 = printF(tmp2.size() - 1, tmp2);

        return max(op1, op2);
    }
};