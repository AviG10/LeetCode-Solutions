class Solution {
private:
    bool solve(int i, int& n, string& s, unordered_map<string, int>& mp, vector<int> &dp) {
        if (i == n)
            return true;
        
        if(dp[i] != -1)
            return dp[i];
        
        for (int len = 1; len <= n; len++) {
            string temp = s.substr(i, len);

            if (mp[temp] > 0 && solve(i + len, n, s, mp, dp))
                return dp[i] = true;
        }

        return dp[i] = false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int> mp;

        for (string& s : wordDict)
            mp[s]++;

        if (mp[s] > 0)
            return true;

        int n = s.length();
        vector<int> dp(n+1, -1);

        return solve(0, n, s, mp, dp);
    }
};