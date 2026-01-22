class Solution {
public:
    bool canBePlaced(vector<int>& v, int distance, int cows) {
        int cntCows = 1, last = v[0];
        for (int i = 1; i < v.size(); ++i) {
            if (v[i] - last >= distance) {
                cntCows++;
                last = v[i];
            }
            if (cntCows >= cows) {
                return true;
            }
        }
        return false;
    }

    int maxDistance(vector<int>& v, int k) {
        sort(v.begin(), v.end());
        int low = 1, high = v.back() - v.front();
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (canBePlaced(v, mid, k)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high;
    }
};