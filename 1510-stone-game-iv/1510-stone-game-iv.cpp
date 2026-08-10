class Solution {
private:
    bool solve(int n, vector<int>& dp) {
        if (n <= 0)
            return false;

        if (dp[n] != -1)
            return dp[n];

        bool ans = false;
        for (int i = 1; i * i <= n; i++) {
            if (solve(n - i * i, dp) == false) {
                ans = true;
            }
        }

        return dp[n] = ans;
    }

public:
    bool winnerSquareGame(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};