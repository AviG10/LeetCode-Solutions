class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> paddedNums;

        paddedNums.push_back(1);

        for (int i = 0; i < n; i++)
            paddedNums.push_back(nums[i]);

        paddedNums.push_back(1);

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int i = n; i >= 1; i--) {
            for (int j = 1; j <= n; j++) {
                if (i > j)
                    continue;

                int ans = 0;

                for (int k = i; k <= j; k++) {
                    ans = max(ans, paddedNums[i - 1] * paddedNums[k] *
                                           paddedNums[j + 1] +
                                       dp[i][k - 1] + dp[k + 1][j]);
                }

                dp[i][j] = ans;
            }
        }

        return dp[1][n];
    }
};