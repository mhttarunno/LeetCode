class Solution {
public:
    vector<vector<int>> ans;
    vector<int> ds;

    void printF(vector<int>& v, vector<int>& freq) {
        if (ds.size() == v.size()) {
            ans.push_back(ds);
            return;
        }

        for (int i = 0; i < v.size(); ++i) {
            if (freq[i] == false) {
                ds.push_back(v[i]);
                freq[i] = true;
                printF(v, freq);
                freq[i] = false;
                ds.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        ans.clear();
        ds.clear();
        vector<int> freq(nums.size(), 0);
        printF(nums, freq);
        return ans;
    }
};