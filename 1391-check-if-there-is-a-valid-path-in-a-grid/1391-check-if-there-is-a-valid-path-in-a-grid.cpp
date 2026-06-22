class Solution {
private:
    bool isValid(int i, int j, int &m, int &n, vector<vector<int>> &vis){
        return i >= 0 && i < m && j >= 0 && j < n && !vis[i][j];
    }

    bool dfs(int i, int j, int &m, int &n, vector<vector<int>>& grid, vector<vector<int>> &vis, unordered_map<int,vector<vector<int>>> &mp){
        if(i == m-1 && j == n-1) return true;

        vis[i][j] = true;

        for(auto &dir: mp[grid[i][j]]){
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if(isValid(new_i,new_j,m,n,vis)){
                for(auto &backDir: mp[grid[new_i][new_j]]){
                    if((new_i + backDir[0] == i) && (new_j + backDir[1] == j)){
                        if(dfs(new_i,new_j,m,n,grid,vis,mp)){
                            return true;
                        }
                    }
                }
            }
        }

        return false;
    }
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        unordered_map<int,vector<vector<int>>> mp = {
            {1, {{0,-1}, {0,1}}},
            {2, {{1,0}, {-1,0}}},
            {3, {{0,-1}, {1,0}}},
            {4, {{0,1}, {1,0}}},
            {5, {{0,-1}, {-1,0}}},
            {6, {{-1,0}, {0,1}}}
        };

        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,false));

        return dfs(0,0,m,n,grid,vis,mp);
    }
};