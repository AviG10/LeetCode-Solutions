class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<char>> ans(n, vector<char>(m));

        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                ans[i][j] = grid[j][i];
            }
        }

        for(vector<char> &row: ans){
            reverse(row.begin(), row.end());
        }

        for(int j = 0;j < m;j++){
            int spaceRow = n-1;
            
            for(int i = n-1;i >= 0;i--){
                if(ans[i][j] == '*'){
                    spaceRow = i-1;
                    continue;
                }

                if(ans[i][j] == '#'){
                    ans[i][j] = '.';
                    ans[spaceRow][j] = '#';
                    spaceRow--;
                }
            }
        }

        return ans;
    }
};