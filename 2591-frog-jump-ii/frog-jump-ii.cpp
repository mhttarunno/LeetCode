class Solution {
public:
    int maxJump(vector<int>& h) {
        int n = h.size();
        if (n <= 1)return 0;
        int prev = 0, prev2 = 0;
        for (int i = 1; i < h.size(); ++i) {
            int firstStep = max(prev, abs(h[i] - h[i - 1]));;
            int secondStep = LLONG_MAX;
            if (i > 1) {
                secondStep = max(prev2, abs(h[i] - h[i - 2]));;
            }
            int curr = max(firstStep, secondStep);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};