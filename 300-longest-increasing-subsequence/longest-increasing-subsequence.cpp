class Solution {
public:
    vector<int> dp;
    int lis(int n, vector<int> &v) {
        if (dp[n] ^ -1) return dp[n];
        int ans = 1;
        for (int j = 0; j < n; ++j) {
            if (v[n] > v[j]) {
                ans = max(ans, lis(j, v) + 1);
            }   
        }
        return dp[n] = ans;
}
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, -1);    
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, lis(i, nums));
        }
        return ans;
    }
};