class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m-k+1,vector<int>(n-k+1,0));

        for(int i = 0;i < m-k+1;i++){
            for(int j = 0;j < n-k+1;j++){
                
                map<int,int> mp;

                for(int ik = 0;ik < k;ik++){
                    for(int jk = 0;jk < k;jk++){
                        mp[grid[i+ik][j+jk]]++;
                    }
                }

                int prev = INT_MAX, absDiffer = INT_MAX;
                for(auto it: mp){
                    if(prev == INT_MAX){
                        prev = it.first;
                    } 
                    else{
                        absDiffer = min(absDiffer, abs(it.first-prev));
                        prev = it.first;
                    }
                }

                ans[i][j] = (absDiffer == INT_MAX) ? 0 : absDiffer;
            }
        }

        return ans;
    }
};