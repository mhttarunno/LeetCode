class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());

        nums.clear();
        for (auto it : s) {
            nums.push_back(it);
        }

        return nums.size();
    }
};
