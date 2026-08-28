class Solution {
private:
    bool isValid(int col1, int col2, int& n) {
        return col1 >= 0 && col1 < n && col2 >= 0 && col2 < n;
    }

    int solve(int row, int col1, int col2, int& m, int& n,
              vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        if (row == m - 1) {
            if (col1 == col2)
                return grid[row][col1];
            else
                return grid[row][col1] + grid[row][col2];
        }

        if (dp[row][col1][col2] != -1)
            return dp[row][col1][col2];

        int maxCherries = INT_MIN;
        for (int j1 = -1; j1 <= 1; j1++) {
            for (int j2 = -1; j2 <= 1; j2++) {
                int cherries = 0;

                if (col1 == col2)
                    cherries = grid[row][col1];
                else
                    cherries = grid[row][col1] + grid[row][col2];

                if (isValid(col1 + j1, col2 + j2, n))
                    cherries +=
                        solve(row + 1, col1 + j1, col2 + j2, m, n, grid, dp);

                maxCherries = max(maxCherries, cherries);
            }
        }

        return dp[row][col1][col2] = maxCherries;
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(n, -1)));

        return solve(0, 0, n - 1, m, n, grid, dp);
    }
};