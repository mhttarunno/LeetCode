class Solution {
public:
    int findDays(vector<int>& v, int storage) {
        int days = 1, load = 0;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] + load > storage) {
                days++;
                load = v[i];
            } else {
                load += v[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& v, int d) {
        int low = *max_element(v.begin(), v.end()),
            high = accumulate(v.begin(), v.end(), 0);
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (findDays(v, mid) <= d) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};