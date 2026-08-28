class Solution {
private:
    int f(int i, int &n, vector<int>& nums, vector<int> &dp){
        if(i == n-1) return true;

        if(dp[i] != -1) 
            return dp[i];

        bool isPossible = false;
        for(int jump = 1; jump <= nums[i]; jump++){
            if(i + jump < n) 
                isPossible = isPossible || f(i+jump, n, nums, dp);
            if(isPossible)
                break;
        }

        return dp[i] = isPossible;
    }
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        return f(0, n, nums, dp);
    }
};