class Solution {
private:
    bool f(int i, int j, int& m, int& n, string& s, string& t,
           vector<vector<int>>& dp) {
        if (i == m)
            return true;
        if (j == n)
            return false;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == t[j])
            return dp[i][j] = f(i + 1, j + 1, m, n, s, t, dp) ||
                              f(i, j + 1, m, n, s, t, dp);
        else
            return dp[i][j] = f(i, j + 1, m, n, s, t, dp);
    }

public:
    bool isSubsequence(string s, string t) {
        int m = s.length(), n = t.length();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return f(0, 0, m, n, s, t, dp);
    }
};