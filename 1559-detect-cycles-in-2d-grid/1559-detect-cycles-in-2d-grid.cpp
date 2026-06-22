class Solution {
private:
    bool isValid(int i,int j, int &m, int &n){
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    bool isEqualPrevInd(int i, int j, int prev_i, int prev_j){
        return (i == prev_i) && (j == prev_j);
    }

    bool dfs(int i, int j, int prev_i, int prev_j, char cur_char,int &m, int &n, vector<vector<bool>> &vis, vector<vector<char>> &grid){
        vis[i][j] = true;

        int dirX[] = {-1,1,0,0};
        int dirY[] = {0,0,-1,1};

        for(int idx = 0;idx < 4;idx++){
            int nextX = i + dirX[idx];
            int nextY = j + dirY[idx];
            
            if(isValid(nextX,nextY,m,n)){
                if(!isEqualPrevInd(nextX,nextY,prev_i,prev_j)){
                    if(cur_char == grid[nextX][nextY]){
                        if(vis[nextX][nextY] == true) return true;
                        if(dfs(nextX,nextY,i,j,grid[nextX][nextY],m,n,vis,grid)) return true;
                    } 
                }
            }
        }

        return false;
    }
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(vis[i][j] == false && dfs(i,j,-1,-1,grid[i][j],m,n,vis,grid)){
                    return true;
                }
            }
        }

        return false;
    }
};