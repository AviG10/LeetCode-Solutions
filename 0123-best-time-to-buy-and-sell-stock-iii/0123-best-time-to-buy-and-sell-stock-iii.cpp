class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> prev(2, vector<int>(3, 0)), cur(2, vector<int>(3, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy < 2; buy++) {
                for (int cap = 1; cap <= 2; cap++) {
                    if (buy)
                        cur[buy][cap] = max(-prices[i] + prev[0][cap],
                                              0 + prev[buy][cap]);
                    else
                        cur[buy][cap] = max(prices[i] + prev[1][cap - 1],
                                              0 + prev[buy][cap]);
                }
            }

            prev = cur;
        }

        return prev[1][2];
    }
};