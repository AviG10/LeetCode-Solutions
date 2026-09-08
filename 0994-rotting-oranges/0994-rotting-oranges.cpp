class Solution {
private:
    bool isValid(int row, int col, int &m, int &n, vector<vector<int>>& grid){
        if(row >= 0 && row < m && col >= 0 && col < n && grid[row][col] == 1)
            return true;
        else 
            return false;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2)
                    q.push({i, j});
                else if(grid[i][j] == 1)
                    fresh++;
            }
        }

        if(fresh == 0)
            return 0;
        
        int time = 0;

        while(!q.empty()){
            int sz = q.size();
            bool anyFreshHasRottened = false;

            while(sz--){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                int dirX[] = {1, 0, -1, 0};
                int dirY[] = {0, -1, 0, 1};

                for(int i = 0;i < 4; i++){
                    int newRow = row + dirX[i];
                    int newCol = col + dirY[i];

                    if(isValid(newRow, newCol, m, n, grid)){
                        q.push({newRow, newCol});
                        grid[newRow][newCol] = 2;
                        anyFreshHasRottened = true;
                    }
                }
            }

            if(anyFreshHasRottened)
                time++;
        }

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == 1)
                    return -1;

        return time;
    }
};