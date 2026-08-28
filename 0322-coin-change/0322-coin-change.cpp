class Solution {
private:
    int f(int ind, int amt, int& n, vector<int>& coins,
          vector<vector<int>>& dp) {
        if (ind == 0) {
            if (amt % coins[0] == 0)
                return (amt / coins[0]);
            else
                return 1e9;
        }

        if (dp[ind][amt] != -1)
            return dp[ind][amt];

        int notPick = 0 + f(ind - 1, amt, n, coins, dp);

        int pick = INT_MAX;
        if (amt - coins[ind] >= 0)
            pick = 1 + f(ind, amt - coins[ind], n, coins, dp);

        return dp[ind][amt] = min(pick, notPick);
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));

        int ans = f(n - 1, amount, n, coins, dp);

        return ans >= 1e9 ? -1 : ans;
    }
};