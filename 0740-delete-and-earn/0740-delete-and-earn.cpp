class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int curSum = nums[i];
            int idx = i + 1;

            while (idx < n && nums[idx] == nums[i]) {
                curSum += nums[idx];
                idx++;
            }

            while (idx < n && nums[idx] == nums[i] + 1)
                idx++;

            dp[i] = max(curSum + dp[idx], dp[i + 1]);
        }

        return dp[0];
    }
};