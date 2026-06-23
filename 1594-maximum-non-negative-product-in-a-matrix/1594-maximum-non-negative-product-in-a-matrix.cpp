class Solution {
private:
    int MOD = 1e9+7;

    bool isValid(int i, int j, int &m, int &n){
        return (i >= 0 && i < m && j >= 0 && j < n);
    }

    pair<long long,long long> f(int i, int j, int &m, int &n, vector<vector<int>>& grid, vector<vector<pair<long long, long long>>> &dp){
        if(i == m-1 && j == n-1) return {grid[i][j], grid[i][j]};

        if(dp[i][j] != make_pair(LLONG_MAX, LLONG_MIN)) return dp[i][j];

        long long minVal = LLONG_MAX;
        long long maxVal = LLONG_MIN;

        // Down
        if(isValid(i+1,j,m,n)){
            auto [downMin, downMax] = f(i+1,j,m,n,grid,dp);

            minVal = min({minVal, grid[i][j] * downMin, grid[i][j] * downMax});
            maxVal = max({maxVal, grid[i][j] * downMin, grid[i][j] * downMax});
        }

        // right
        if(isValid(i,j+1,m,n)){
            auto [rightMin, rightMax] = f(i,j+1,m,n,grid,dp);

            minVal = min({minVal, grid[i][j] * rightMin, grid[i][j] * rightMax});
            maxVal = max({maxVal, grid[i][j] * rightMin, grid[i][j] * rightMax});
        }

        return dp[i][j] = {minVal, maxVal};
    }
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<pair<long long, long long>> prev(n,{LLONG_MAX,LLONG_MIN}), cur(n,{LLONG_MAX,LLONG_MIN});

        cur[n-1] = {grid[m-1][n-1], grid[m-1][n-1]};

        for(int i = m-1;i >= 0;i--){
            for(int j = n-1;j >= 0;j--){
                if(i == m-1 && j == n-1) continue;
                
                long long minVal = LLONG_MAX;
                long long maxVal = LLONG_MIN;

                // Down
                if(isValid(i+1,j,m,n)){
                    auto [downMin, downMax] = prev[j];

                    minVal = min({minVal, grid[i][j] * downMin, grid[i][j] * downMax});
                    maxVal = max({maxVal, grid[i][j] * downMin, grid[i][j] * downMax});
                }

                // right
                if(isValid(i,j+1,m,n)){
                    auto [rightMin, rightMax] = cur[j+1];

                    minVal = min({minVal, grid[i][j] * rightMin, grid[i][j] * rightMax});
                    maxVal = max({maxVal, grid[i][j] * rightMin, grid[i][j] * rightMax});
                }

                cur[j] = {minVal, maxVal};
            }
            prev = cur;
        }

        auto [minVal, MaxVal] = prev[0];

        return MaxVal < 0 ? -1 : MaxVal % MOD;
    }
};