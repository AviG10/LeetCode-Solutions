class Solution {
private:
    bool isValid(int &row, int &col, int &n){
        if(row >= 0 && row < n && col >= 0 && col < n)
            return true;
        else 
            return false;
    }
    int findOverlap(vector<vector<int>>& grid1, vector<vector<int>>& grid2,
                    int row_offset, int col_offset) {
        int n = grid1.size();
        int overlap = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int newRow = i + row_offset;
                int newCol = j + col_offset;

                if(isValid(newRow, newCol, n)){
                    if(grid1[i][j] == 1 && grid2[newRow][newCol] == 1){
                        overlap++;
                    }
                }
            }
        }

        return overlap;
    }
public:
    int largestOverlap(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int maxOverlap = 0;

        for (int row_offset = -n + 1; row_offset <= n - 1; row_offset++) {
            for (int col_offset = -n + 1; col_offset <= n - 1; col_offset++) {
                int overlap = findOverlap(grid1, grid2, row_offset, col_offset);
                maxOverlap = max(maxOverlap, overlap);
            }
        }

        return maxOverlap;
    }
};