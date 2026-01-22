class Solution {
public:
    bool possible(vector<int>& v, int day, int m, int k) {
        int cnt = 0, noOfBouquets = 0;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] <= day) {
                cnt++;
            } else {
                noOfBouquets += (cnt / k);
                cnt = 0;
            }
        }
        noOfBouquets += (cnt / k);
        return noOfBouquets >= m;
    }

    int minDays(vector<int>& v, int m, int k) {
        if (1LL * m * k > v.size()) {
            return -1;
        }
        int low = *min_element(v.begin(), v.end()),
            high = *max_element(v.begin(), v.end());
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (possible(v, mid, m, k)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};