class Solution {
private:
    int solve(int i, int j, vector<int>& paddedNums, vector<vector<int>> &dp) {
        if (i > j)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;

        for (int k = i; k <= j; k++) {
            ans =
                max(ans, paddedNums[i - 1] * paddedNums[k] * paddedNums[j + 1] +
                             solve(i, k - 1, paddedNums, dp) +
                             solve(k + 1, j, paddedNums, dp));
        }

        return dp[i][j] = ans;
    }

public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> paddedNums;

        paddedNums.push_back(1);

        for (int i = 0; i < n; i++)
            paddedNums.push_back(nums[i]);

        paddedNums.push_back(1);

        vector<vector<int>> dp(n+2, vector<int>(n+2, -1));

        return solve(1, n, paddedNums, dp);
    }
};