class Solution {
private:
    int solve(int i, vector<int>& nums, vector<int> &dp){
        if(i == 1)
            return nums[i-1];
        if(i == 0) 
            return 0;
        
        if(dp[i] != -1)
            return dp[i];

        return dp[i] = max(nums[i-1] + solve(i - 2, nums, dp), solve(i - 1, nums, dp));
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) 
            return nums[0];

        vector<int> numsWithoutFirstEle, numsWithoutLastEle;

        for(int i = 0; i < n; i++){
            if(i != 0)
                numsWithoutFirstEle.push_back(nums[i]);
            if(i != n - 1)
                numsWithoutLastEle.push_back(nums[i]);
        }

        vector<int> dp1(n, -1), dp2(n, -1);

        return max(solve(n-1, numsWithoutFirstEle, dp1), solve(n-1, numsWithoutLastEle, dp2));
    }
};