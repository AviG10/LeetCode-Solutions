class Solution {
private:
    bool isValid(int i, int j, int &m, int &n, vector<vector<char>>& grid){
        if(i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == '1')
            return true;
        else 
            return false;
    }

    void dfs(int i, int j, int &m, int &n, vector<vector<char>>& grid){
        grid[i][j] = '0';

        if(isValid(i + 1, j, m, n, grid))
            dfs(i + 1, j, m, n, grid);
        
        if(isValid(i - 1, j, m, n, grid))
            dfs(i - 1, j, m, n, grid);

        if(isValid(i, j + 1, m, n, grid))
            dfs(i, j + 1, m, n, grid);

        if(isValid(i, j - 1, m, n, grid))
            dfs(i, j - 1, m, n, grid);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    dfs(i, j, m, n, grid);
                    ans++;
                }
            }
        }

        return ans;
    }
};