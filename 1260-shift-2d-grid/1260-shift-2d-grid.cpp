class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        while(k--){
            for(int i = 0;i < m;i++)
                for(int j = n-1;j >= 1;j--)
                    swap(grid[i][j], grid[i][j-1]);

            for(int i = m-1;i >= 1;i--)
                swap(grid[i][0], grid[i-1][0]);
        }

        return grid;
    }
};