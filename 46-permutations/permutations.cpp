class Solution {
public:
    vector<vector<int>> ans;
    void printF(int idx, vector<int>& v) {
        if (idx == v.size()) {
            ans.push_back(v);
            return;
        }

        for (int i = idx; i < v.size(); ++i) {
            swap(v[idx], v[i]);
            printF(idx + 1, v);
            swap(v[idx], v[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        ans.clear();
        printF(0, nums);
        return ans;
    }
};