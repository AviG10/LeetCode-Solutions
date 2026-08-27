class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int> mp;

        for (string &word : wordDict)
            mp[word]++;

        if (mp[s] > 0)
            return true;

        int n = s.length();
        vector<int> dp(n+1, false);
        
        dp[n] = true;

        for(int i = n-1; i >= 0; i--){
            for (int len = 1; i + len <= n; len++) {
                string temp = s.substr(i, len);

                if (mp[temp] > 0 && dp[i + len]){
                    dp[i] = true;
                    break;
                } 
            }
        }

        return dp[0];
    }
};