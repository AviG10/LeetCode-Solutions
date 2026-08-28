class Solution {
private:
    bool isPalindrome(int i, int j, string& s, vector<vector<int>> &dp) {
        if (i >= j)
            return true;

        if(dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == s[j])
            return dp[i][j] = isPalindrome(i + 1, j - 1, s, dp);
        else
            return dp[i][j] = false;
    }

public:
    string longestPalindrome(string s) {
        int n = s.length();
        int maxLen = 0;
        string res = "";
        
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalindrome(i, j, s, dp)) {
                    int len = j - i + 1;

                    if (len > maxLen) {
                        maxLen = len;
                        res = s.substr(i, j - i + 1);
                    }
                }
            }
        }

        return res;
    }
};