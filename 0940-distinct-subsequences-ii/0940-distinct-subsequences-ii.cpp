class Solution {
private:
    int MOD = 1e9 + 7;

    long long solve(int i, vector<int>& prevOccur, vector<long long> &dp) {
        if (i < 0)
            return 1;

        if(dp[i] != -1)
            return dp[i];

        long long total = (2LL * solve(i - 1, prevOccur, dp)) % MOD;

        if (prevOccur[i] >= 0)
            total = (total - solve(prevOccur[i] - 1, prevOccur, dp) + MOD) % MOD;

        return dp[i] = total;
    }

public:
    int distinctSubseqII(string s) {
        int n = s.length();
        vector<int> prevOccur(n, -1);
        vector<int> lastSeen(26, -1);

        for (int i = 0; i < n; i++) {
            int ch = s[i] - 'a';
            prevOccur[i] = lastSeen[ch];
            lastSeen[ch] = i;
        }

        vector<long long> dp(n, -1);
        
        return (solve(n - 1, prevOccur, dp) - 1 + MOD) % MOD;
    }
};