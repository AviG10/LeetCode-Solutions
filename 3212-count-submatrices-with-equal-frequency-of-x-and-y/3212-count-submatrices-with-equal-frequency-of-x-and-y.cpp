class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<pair<int,int>>> freqGrid(m,vector<pair<int,int>>(n,{0,0})); // {x,y} = {cnt of x, cnt of y} 

        for(int i = 0;i < m;i++){
            int cntX = 0, cntY = 0;
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 'X') cntX++;
                if(grid[i][j] == 'Y') cntY++;
                
                freqGrid[i][j] = {cntX,cntY};
            }
        }

        for(int j = 0;j < n;j++){
            for(int i = 1;i < m;i++){
                int prevRowCntX = freqGrid[i-1][j].first;
                int prevRowCntY = freqGrid[i-1][j].second;

                int curRowCntX = freqGrid[i][j].first;
                int curRowCntY = freqGrid[i][j].second;

                freqGrid[i][j] = {prevRowCntX + curRowCntX, prevRowCntY + curRowCntY};
            }
        }

        int ans = 0;

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                int curRowCntX = freqGrid[i][j].first;
                int curRowCntY = freqGrid[i][j].second;

                if((curRowCntX >= 1) && (curRowCntX == curRowCntY)){
                    ans++;
                }
            }
        }

        return ans;
    }
};