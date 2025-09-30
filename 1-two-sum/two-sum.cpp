class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> vp;
        for (int i = 0; i < n; ++i) {
            vp.push_back({nums[i], i});
        }
        sort(vp.begin(), vp.end());
        int left = 0, right = n - 1;
        while (left < right) {
            int sum = vp[left].first + vp[right].first;
            if (sum == target) {
                return {vp[left].second, vp[right].second};
            } else if (sum < target) {
                ++left;
            } else {
                --right;
            }
        }
        return {};
    }
};
