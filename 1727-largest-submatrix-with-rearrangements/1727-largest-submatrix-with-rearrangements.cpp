class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& nums) {
        int m = nums.size();
        int n = nums[0].size();
        int ans = 0;

        vector<pair<int,int>> prevRow; // {height, col}

        for(int i = 0;i < m;i++){
            
            vector<pair<int,int>> curRow; // {height, col}
            vector<bool> isVis(n,false);

            for(auto it: prevRow){
                int height = it.first;
                int col = it.second;

                if(nums[i][col] == 1){
                    curRow.push_back({height+1,col});
                    isVis[col] = true;
                }
            }

            for(int j = 0;j < n;j++){
                if(nums[i][j] == 1 && isVis[j] == false){
                    curRow.push_back({1,j});
                    isVis[j] = true;
                }    
            }

            int b = 0;
            for(auto it: curRow){
                int h = it.first;
                b++;
                ans = max(ans,h*b);
            }

            prevRow = curRow;
        }

        return ans;
    }
};