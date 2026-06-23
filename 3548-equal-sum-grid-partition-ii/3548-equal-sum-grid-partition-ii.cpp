class Solution {
private:
    bool checkHorizontalCuts(vector<vector<int>>& grid, long long &totalSum){
        int m = grid.size();
        int n = grid[0].size();

        unordered_set<long long> st;
        long long topSum = 0;

        for(int i = 0;i < m-1;i++){
            
            for(int j = 0;j < n;j++){
                st.insert((long long)grid[i][j]);
                topSum += (long long) grid[i][j];
            }

            long long bottomSum = totalSum - topSum;
            long long diffSum = topSum - bottomSum;

            if(diffSum == 0) return true;

            // Edge Cases
            if(diffSum == (long long) grid[0][0]) return true;
            if(diffSum == (long long) grid[0][n-1]) return true;
            
            if(diffSum == (long long) grid[i][0]) return true;
            if(diffSum == (long long) grid[i][n-1]) return true;

            if(i > 0 && n > 1 && st.count(diffSum)) return true;
        }  

        return false;
    }

    bool verifyHorizontalCuts(vector<vector<int>>& grid, long long &totalSum){
        bool forwardCheck = checkHorizontalCuts(grid,totalSum);

        reverse(grid.begin(),grid.end());
        bool backwardCheck = checkHorizontalCuts(grid,totalSum);

        reverse(grid.begin(),grid.end()); // Putting Back the Original Matrix Given

        return forwardCheck || backwardCheck;
    }

    bool verifyVerticalCuts(vector<vector<int>>& grid, long long &totalSum){
        int m = grid.size();
        int n = grid[0].size();

        // Transpose of the Original Matrix - Converting Cols into Rows
        vector<vector<int>> transposedGrid(n,vector<int>(m));
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                transposedGrid[j][i] = grid[i][j];
            }
        }

        return verifyHorizontalCuts(transposedGrid, totalSum);
    }
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        long long totalSum = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                totalSum += grid[i][j]; 
            }
        }

        return verifyHorizontalCuts(grid, totalSum) || verifyVerticalCuts(grid,totalSum);
    }
};