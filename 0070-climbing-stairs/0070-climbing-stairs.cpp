class Solution {
private:
    int f(int i, int &n, vector<int> &dp){
        if(i == n) 
            return 1;
        if(i > n) 
            return 0;
        
        if(dp[i] != -1) 
            return dp[i];

        return dp[i] = f(i+1, n, dp) + f(i+2, n, dp);
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+2, -1);
        return f(0, n, dp);
    }
};