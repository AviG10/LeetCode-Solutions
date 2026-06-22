// Space Optimization
class Solution {
private:
    int calculateCost(int val){
        if(val == 0) return 0;
        else return 1;
    }

    bool isValid(int i, int j, int &m, int &n){
        if(i >= 0 && i < m && j >= 0 && j < n) return true;
        else return false;
    }
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> cur(n,vector<int>(k+1, INT_MIN)), prev(n,vector<int>(k+1, INT_MIN));

        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                for(int cost = 0; cost <= k; cost++){
                    int next_cost = cost + calculateCost(grid[i][j]);
                    
                    if(next_cost > k) prev[j][cost] = -1e9;
                    else if(i == m-1 && j == n-1) prev[j][cost] = grid[m-1][n-1];
                    else{
                        int right = -1e9, down = -1e9;
                        if(isValid(i,j+1,m,n)){
                            right = max(right,grid[i][j] + prev[j+1][next_cost]);
                        }

                        if(isValid(i+1,j,m,n)){
                            down = max(down,grid[i][j] + cur[j][next_cost]);
                        }
                        
                        prev[j][cost] = max(down, right);
                    } 
                }
            }
            cur = prev;
        }

        int ans = prev[0][0];

        return ans < 0 ? -1 : ans;
    }
};