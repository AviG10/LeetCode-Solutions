class Solution {
private:
    bool solve(int i, int j, int k, int& m, int& n, int& p, string& s1,
               string& s2, string& s3, vector<vector<vector<int>>>& dp) {
        if (k == 0)
            return true;

        if (dp[i][j][k] != -1)
            return dp[i][j][k];

        bool flag1 = false;
        if (i >= 1 && k >= 1 && s1[i - 1] == s3[k - 1])
            flag1 = solve(i - 1, j, k - 1, m, n, p, s1, s2, s3, dp);

        bool flag2 = false;
        if (j >= 1 && k >= 1 && s2[j - 1] == s3[k - 1])
            flag2 = solve(i, j - 1, k - 1, m, n, p, s1, s2, s3, dp);

        return dp[i][j][k] = (flag1 || flag2);
    }

public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length(), n = s2.length(), p = s3.length();

        if (m + n != p)
            return false;
        else {
            vector<vector<vector<int>>> dp(
                m + 1, vector<vector<int>>(n + 1, vector<int>(p + 1, -1)));
            return solve(m, n, p, m, n, p, s1, s2, s3, dp);
        }
    }
};