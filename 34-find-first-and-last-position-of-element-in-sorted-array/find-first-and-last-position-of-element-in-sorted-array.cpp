class Solution {
public:
    vector<int> searchRange(std::vector<int>& nums, int x) {
    auto lb = lower_bound(nums.begin(), nums.end(), x);
    if (lb == nums.end() || *lb != x) {
        return {-1, -1};
    }
    auto ub = upper_bound(nums.begin(), nums.end(), x);
    return {static_cast<int>(lb - nums.begin()), static_cast<int>(ub - nums.begin() - 1)};
    }
};
