class Solution {
private:
    int MOD = 1e9 + 7;

public:
    int numberOfSets(int n, int segment) {
        vector<vector<int>> dp(n + 1, vector<int>(segment + 1, 0));

        for (int i = 0; i <= n - 1; i++)
            dp[i][0] = 1;

        for (int k = 1; k <= segment; k++) {
            vector<int> suffixSum(n + 1, 0);

            for (int i = n - 1; i >= 0; i--) {
                suffixSum[i] = (suffixSum[i + 1] + dp[i][k - 1]) % MOD;
            }

            for (int i = n - 1; i >= 0; i--) {
                int notTake = dp[i + 1][k];
                int take = suffixSum[i + 1];

                dp[i][k] = (notTake + take) % MOD;
            }
        }

        return dp[0][segment];
    }
};