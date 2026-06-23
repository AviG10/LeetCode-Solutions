class Solution {
private:
    int MOD = 12345;
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> prevPrefixProduct(m,vector<int>(n)); 
        vector<vector<int>> postPrefixProduct(m,vector<int>(n));

        long long prod = 1;

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                prevPrefixProduct[i][j] = prod;
                prod *= grid[i][j];
                prod %= MOD;
            }
        }

        prod = 1;

        for(int i = m-1;i >= 0;i--){
            for(int j = n-1;j >= 0;j--){
                postPrefixProduct[i][j] = prod;
                prod *= grid[i][j];
                prod %= MOD;
            }
        }
        
        vector<vector<int>> ans(m,vector<int>(n));

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                ans[i][j] = prevPrefixProduct[i][j] * postPrefixProduct[i][j];
                ans[i][j] %= MOD; 
            }
        }
        
        return ans;
    }
};