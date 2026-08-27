class Solution {
private:
    int f(int i, int buy, int cap, int& n, vector<int>& prices,
          vector<vector<vector<int>>>& dp) {
        if (cap == 0)
            return 0;

        if (i == n)
            return 0;

        if (dp[i][buy][cap] != -1)
            return dp[i][buy][cap];

        if (buy)
            return dp[i][buy][cap] =
                       max(-prices[i] + f(i + 1, 0, cap, n, prices, dp),
                           0 + f(i + 1, buy, cap, n, prices, dp));
        else
            return dp[i][buy][cap] =
                       max(prices[i] + f(i + 1, 1, cap - 1, n, prices, dp),
                           0 + f(i + 1, buy, cap, n, prices, dp));
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(3, -1)));

        return f(0, 1, 2, n, prices, dp);
    }
};