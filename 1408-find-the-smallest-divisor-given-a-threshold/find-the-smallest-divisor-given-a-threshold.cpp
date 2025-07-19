class Solution {
public:
    int sumD(vector<int>& v, int k) {
        int sum = 0;
        for(int i = 0; i < v.size(); ++i) {
            sum += ceil((double)(v[i]) /(double)(k));
        }
        return sum;
    }

    int smallestDivisor(vector<int>& v, int k) {
        int low = 1, high = *max_element(v.begin(), v.end());
        while(low <= high) {
            int mid = low + ((high - low) >> 1);
            if(sumD(v, mid) <= k) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
