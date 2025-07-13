class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int sum = 0, start = 0;
        int ansStart = -1, ansEnd = -1;

        for(int i = 0; i < nums.size(); ++i) {
            if(sum == 0) {
                start = i;
            }
            sum += nums[i];
            if(sum > maxSum) {
                maxSum = sum;
                ansStart = start;
                ansEnd = i;
            }

            if(sum < 0) {
                sum = 0;
            }
        }
        return maxSum;
    }
};
