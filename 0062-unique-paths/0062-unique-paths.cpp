class Solution {
private:
    bool isValid(int i, int j, int &m, int &n){
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    int f(int i, int j, int &m, int &n, vector<vector<int>> &dp){
        if(i == m-1 && j == n-1) return 1;
        
        if(dp[i][j] != -1) 
            return dp[i][j];

        int down = 0;
        if(isValid(i+1, j, m, n))
            down = f(i+1,j, m, n, dp);
        
        int right = 0;
        if(isValid(i, j+1, m, n))
            right = f(i, j+1,m, n, dp);

        return dp[i][j] = down + right;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n, -1));

        return f(0, 0, m, n, dp);
    }
};