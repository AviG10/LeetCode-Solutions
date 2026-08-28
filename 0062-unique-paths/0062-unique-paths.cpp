class Solution {
private:
    bool isValid(int i, int j, int& m, int& n) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n, -1));

        dp[m - 1][n - 1] = 1;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1)
                    continue;

                int down = 0;
                if (isValid(i + 1, j, m, n))
                    down = dp[i + 1][j];

                int right = 0;
                if (isValid(i, j + 1, m, n))
                    right = dp[i][j + 1];

                dp[i][j] = down + right;
            }
        }

        return dp[0][0];
    }
};