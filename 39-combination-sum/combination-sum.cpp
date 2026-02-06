class Solution {
public:
    vector<vector<int>> res;
    vector<int> ans;

    void printF(int idx, int sum, vector<int>& candidates, int target) {
        if (sum > target) return;
        if (sum == target) {
            res.push_back(ans);
            return;
        }

        for (int i = idx; i < candidates.size(); ++i) {
            ans.push_back(candidates[i]);
            printF(i, sum + candidates[i], candidates, target);
            ans.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        res.clear();
        ans.clear();
        printF(0, 0, candidates, target);
        return res;
    }
};
