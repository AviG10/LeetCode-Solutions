class Solution {
private:
    bool solve(int i, int sum, int& n, vector<int>& nums,
               vector<vector<int>>& dp) {
        if (i == n)
            return false;
        if (sum == 0)
            return true;
        if (sum < 0)
            return false;

        if (dp[i][sum] != -1)
            return dp[i][sum];

        bool notTake = solve(i + 1, sum, n, nums, dp);
        bool take = solve(i + 1, sum - nums[i], n, nums, dp);

        return dp[i][sum] = (notTake || take);
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for (int i = 0; i < n; i++)
            sum += nums[i];

        if (sum % 2 != 0)
            return false;
        else {
            vector<vector<int>> dp(n + 1, vector<int>((sum / 2) + 1, -1));

            return solve(0, sum / 2, n, nums, dp);
        }
    }
};