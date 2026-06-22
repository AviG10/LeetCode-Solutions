class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size(), n = grid[0].size();

        vector<int> nums;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                nums.push_back(grid[i][j]);
            }
        }

        sort(nums.begin(),nums.end());

        int median = nums[(m*n)/2], ans = 0;

        for(int i = 0;i < m*n;i++){
            if(abs(median - nums[i]) % x == 0) ans += (abs(median - nums[i]) / x);
            else return -1;
        }

        return ans;
    }
};