class Solution {
private:
    int f(int i, int j, int k, vector<vector<int>>& coins, vector<vector<vector<int>>> &dp){
        if(i == 0 && j == 0){
            if(coins[i][j] >= 0) return coins[i][j];
            else return k > 0 ? 0 : coins[i][j]; 
        }

        if(dp[i][j][k] != INT_MIN) return dp[i][j][k];

        int up = -1e9, left = -1e9;
        if(coins[i][j] >= 0){
            if(i > 0) up = coins[i][j] + f(i-1,j,k,coins,dp);
            if(j > 0) left = coins[i][j] + f(i,j-1,k,coins,dp);
        }
        else{
            if(k > 0){
                if(i > 0) up = max(coins[i][j] + f(i-1,j,k,coins,dp), f(i-1,j,k-1,coins,dp));
                if(j > 0) left = max(coins[i][j] + f(i,j-1,k,coins,dp), f(i,j-1,k-1,coins,dp));
            }
            else{
                if(i > 0) up = coins[i][j] + f(i-1,j,k,coins,dp);
                if(j > 0) left = coins[i][j] + f(i,j-1,k,coins,dp);
            }
        }

        return dp[i][j][k] = max(up, left);
    }
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        int k = 2;

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k+1,INT_MIN)));
        return f(m-1,n-1,k,coins,dp);
    }
};