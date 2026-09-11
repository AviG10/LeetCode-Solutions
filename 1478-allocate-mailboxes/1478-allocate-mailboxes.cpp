class Solution {
private:
    int solve(int i, int mailBoxes, int& n, vector<int>& houses,
              vector<vector<int>>& costs, vector<vector<int>> &dp) {
        if (mailBoxes == 0 && i == n)
            return 0;

        if (mailBoxes == 0 || i == n)
            return 1e9;
        
        if(dp[i][mailBoxes] != -1)
            return dp[i][mailBoxes];
        
        int minTotalDist = 1e9;

        for (int j = i; j < n; j++)
            minTotalDist =
                min(minTotalDist, costs[i][j] + solve(j + 1, mailBoxes - 1, n,
                                                      houses, costs, dp));

        return dp[i][mailBoxes] = minTotalDist;
    }

public:
    int minDistance(vector<int>& houses, int k) {
        sort(houses.begin(), houses.end());

        int n = houses.size();
        vector<vector<int>> costs(n, vector<int>(n, 0));

        // Pre-Calculate Cost for putting mailBoxes at Median for all the houses
        // in [i , j]
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                for (int it = i; it <= j; it++) {
                    costs[i][j] += abs(houses[(i + j) / 2] - houses[it]);
                }
            }
        }

        vector<vector<int>> dp(n, vector<int>(k+1, -1));

        return solve(0, k, n, houses, costs, dp);
    }
};