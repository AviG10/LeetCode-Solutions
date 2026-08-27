class Solution {
private:
    int findNext(int j, char ch, string &t, vector<vector<int>> &dp){
        if(j == t.length())
            return -1;
        
        if(dp[j][ch - 'a'] != -2) 
            return dp[j][ch - 'q'];

        if(ch == t[j]) 
            return dp[j][ch - 'a'] = j;
        else 
            return dp[j][ch - 'a'] = findNext(j+1, ch, t, dp);
    }
public:
    bool isSubsequence(string s, string t) {
        int cur_j = 0;
        int n = t.length();

        vector<vector<int>> dp(n+1, vector<int>(26, -2));

        for(char &ch : s){
            int next_idx = findNext(cur_j, ch, t, dp);
            
            if(next_idx == -1) 
                return false;
            else
                cur_j = next_idx + 1;
        }

        return true;
    }
};