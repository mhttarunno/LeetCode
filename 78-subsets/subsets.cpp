class Solution {
public:
    vector<vector<int>> res;
    vector<int> ans;

    void printF(int idx, vector<int>& nums) {
        if (idx == nums.size()) {
            res.push_back(ans);
            return;
        }

        ans.push_back(nums[idx]);
        printF(idx + 1, nums);
        ans.pop_back();

        printF(idx + 1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        printF(0, nums);
        return res;
    }
};
