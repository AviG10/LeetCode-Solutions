class Solution {
private:
    int solve(int player, int i, int M, int& n, vector<int>& piles, vector<vector<vector<int>>> &dp) {
        if (i >= n)
            return 0;

        if(dp[player][i][M] != -1) 
            return dp[player][i][M];

        int stones = 0;
        int ans = (player == 0) ? INT_MIN : INT_MAX;

        for (int x = 1; x <= min(2 * M, n - i); x++) {
            stones += piles[i + x - 1];

            if (player == 0)
                ans = max(ans, stones + solve(1, i + x, max(M, x), n, piles, dp));
            else
                ans = min(ans, solve(0, i + x, max(M, x), n, piles, dp));
        }

        return dp[player][i][M] = ans;
    }

public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(2,vector<vector<int>>(n+1, vector<int>(n+1, -1)));

        return solve(0, 0, 1, n, piles, dp);
    }
};