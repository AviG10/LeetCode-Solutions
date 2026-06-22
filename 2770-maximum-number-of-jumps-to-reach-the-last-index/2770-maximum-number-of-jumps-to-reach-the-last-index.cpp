// Tabulation
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, INT_MIN);

        dp[n-1] = 0;

        for(int i = n-2;i >= 0;i--){
            int jumps = INT_MIN;
            
            for(int j = i+1;j < n;j++){
                if(abs(nums[j] - nums[i]) <= target){
                    jumps = max(jumps, 1 + dp[j]);
                }
            }

            dp[i] = jumps;
        }

        int maxJumps = dp[0];
        return (maxJumps < 0) ? -1 : maxJumps;
    }
};