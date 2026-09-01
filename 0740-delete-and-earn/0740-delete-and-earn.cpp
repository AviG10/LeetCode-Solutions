class Solution {
private:
    int solve(int i, int& n, vector<int>& nums, vector<int>& dp) {
        if (i == n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int curSum = nums[i];
        int idx = i + 1;

        while (idx < n && nums[idx] == nums[i]) {
            curSum += nums[idx];
            idx++;
        }

        while (idx < n && nums[idx] == nums[i] + 1)
            idx++;

        return dp[i] = max(curSum + solve(idx, n, nums, dp),
                           solve(i + 1, n, nums, dp));
    }

public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int> dp(n + 1, -1);

        return solve(0, n, nums, dp);
    }
};