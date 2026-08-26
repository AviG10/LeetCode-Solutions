class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0, curSum = 0;

        while(j < k)
            curSum += nums[j], j++;

        int maxSum = curSum;

        while(j < n){
            curSum += nums[j] - nums[i];
            maxSum = max(maxSum, curSum);
            i++, j++;
        }

        return (double) maxSum / k;
    }
};