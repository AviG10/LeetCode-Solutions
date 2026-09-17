class Solution {
public:
    int minSumOfLengths(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0, j = 0;
        int curSum = 0;
        int curLen = 0, bestMin = INT_MAX;
        int result = INT_MAX;
        vector<int> minLenIdx(n, INT_MAX);

        while (j < n) {
            curSum += nums[j];

            while (curSum > target) {
                curSum -= nums[i];
                i++;
            }

            if (curSum == target) {
                curLen = j - i + 1;

                if (i > 0 && minLenIdx[i - 1] != INT_MAX) {
                    result = min(result, curLen + minLenIdx[i - 1]);
                }

                bestMin = min(bestMin, curLen);
            }

            minLenIdx[j] = bestMin;
            j++;
        }

        return result == INT_MAX ? -1 : result;
    }
};