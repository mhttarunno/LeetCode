class Solution {
public:
    int printF(vector<int>& v) {
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
        vector<int> tmp1, tmp2;
        if(nums.size() == 1) return nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            if(i != 0) {
                tmp1.push_back(nums[i]);
            }
            if(i != nums.size() - 1) {
                tmp2.push_back(nums[i]);
            }
        }
        return max(printF(tmp1), printF(tmp2));
    }
};