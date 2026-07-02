// DFS + Memoization
// TC: O(m * n * health)
// SC: O(m * n)
class Solution {
private:
    bool isValid(int i, int j, int& m, int& n) {
        return (i >= 0 && i < m && j >= 0 && j < n);
    }

    bool solve(int i, int j, int health, int& m, int& n, vector<vector<int>>& grid, vector<vector<bool>>& vis, vector<vector<vector<int>>>& dp) {
        if(health < 1) return false;

        if (i == m - 1 && j == n - 1) {
            if (health >= 1)
                return true;
            else
                return false;
        }

        if (dp[i][j][health] != -1)
            return dp[i][j][health];

        int dirX[4] = {1, 0, -1, 0};
        int dirY[4] = {0, 1, 0, -1};

        vis[i][j] = true;

        bool res = false;

        for (int idx = 0; idx < 4; idx++) {
            int newX = i + dirX[idx];
            int newY = j + dirY[idx];

            if (isValid(newX, newY, m, n) && !vis[newX][newY]) {
                res = res || solve(newX, newY, health - grid[newX][newY], m, n, grid, vis, dp);
            }
        }

        vis[i][j] = false;

        return dp[i][j][health] = res;
    }

public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(health + 1, -1)));

        return solve(0, 0, health - grid[0][0], m, n, grid, vis, dp);
    }
};