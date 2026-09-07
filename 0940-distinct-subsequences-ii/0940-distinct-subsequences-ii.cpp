class Solution {
private:
    int MOD = 1e9 + 7;
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

        vector<long long> dp(n + 1, -1);

        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            long long total = (2LL * dp[i - 1]) % MOD;

            if (prevOccur[i - 1] >= 0)
                total = (total - dp[prevOccur[i - 1]] + MOD) % MOD;

            dp[i] = total;
        }

        return (dp[n] - 1 + MOD) % MOD;
    }
};