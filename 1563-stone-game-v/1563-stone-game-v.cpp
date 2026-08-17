class Solution {
private:
    int solve(int start, int end, vector<int>& stones, vector<vector<int>> &dp) {
        if (start > end)
            return 0;

        if(dp[start][end] != -1) return dp[start][end];

        int right = 0;
        for (int i = start; i <= end; i++)
            right += stones[i];

        int left = 0;
        int ans = 0;
        for (int i = start; i <= end; i++) {
            left += stones[i];
            right -= stones[i];

            if (left < right)
                ans = max(ans, left + solve(start, i, stones, dp));
            else if (left == right)
                ans = max(ans, left + max(solve(start, i, stones, dp),
                                          solve(i + 1, end, stones, dp)));
            else
                ans = max(ans, right + solve(i + 1, end, stones, dp));
        }

        return dp[start][end] = ans;
    }

public:
    int stoneGameV(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, n - 1, stones, dp);
    }
};