class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.length(), n = t.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 2, -1));

        for (int j = 0; j < n; j++)
            dp[m][j] = true;

        for (int i = 0; i < m; i++)
            dp[i][n] = false;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (s[i] == t[j])
                    dp[i][j] = dp[i + 1][j + 1] || dp[i][j + 1];
                else
                    dp[i][j] = dp[i][j + 1];
            }
        }

        return dp[0][0];
    }
};