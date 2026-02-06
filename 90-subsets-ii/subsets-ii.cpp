class Solution {
public:
    vector<vector<int>> ans;
    vector<int> ds;

    void backtrack(int idx, vector<int>& nums) {
        ans.push_back(ds);
        for (int i = idx; i < nums.size(); i++) {
            if (i > idx && nums[i] == nums[i - 1]) {
                continue;
            }
            ds.push_back(nums[i]);
            backtrack(i + 1, nums);
            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        ans.clear();
        ds.clear();
        sort(nums.begin(), nums.end());
        backtrack(0, nums);
        return ans;
    }
};
