class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (auto it : nums) {
            freq[it]++;
        }
        for (auto& [it, cnt] : freq) {
            if (cnt == 1) {
                return it;
            }
        }
        return -1;
    }
};
