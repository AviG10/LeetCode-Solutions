class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));

        for(int amt = 0; amt <= amount; amt++){
            if (amt % coins[0] == 0)
                dp[0][amt] = (amt / coins[0]);
            else
                dp[0][amt] = 1e9;
        }

        for(int ind = 1; ind < n; ind++){
            for(int amt = 0; amt <= amount; amt++){
                int notPick = 0 + dp[ind - 1][amt];

                int pick = INT_MAX;
                if (amt - coins[ind] >= 0)
                    pick = 1 + dp[ind][amt - coins[ind]];

                dp[ind][amt] = min(pick, notPick);
            }
        }

        int ans = dp[n - 1][amount];

        return ans >= 1e9 ? -1 : ans;
    }
};