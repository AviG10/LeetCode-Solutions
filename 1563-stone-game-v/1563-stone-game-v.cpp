class Solution {
public:
    int stoneGameV(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for (int start = n - 1; start >= 0; start--) {
            for (int end = 0; end <= n - 1; end++) {
                if (start > end)
                    continue;

                int right = 0;
                for (int i = start; i <= end; i++)
                    right += stones[i];

                int left = 0;
                int ans = 0;
                for (int i = start; i <= end; i++) {
                    left += stones[i];
                    right -= stones[i];

                    if (left < right)
                        ans = max(ans, left + dp[start][i]);
                    else if (left == right)
                        ans =
                            max(ans, left + max(dp[start][i], dp[i + 1][end]));
                    else
                        ans = max(ans, right + dp[i + 1][end]);
                }

                dp[start][end] = ans;
            }
        }

        return dp[0][n - 1];
    }
};