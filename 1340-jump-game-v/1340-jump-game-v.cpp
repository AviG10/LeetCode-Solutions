// Tabulation / Bottom Up
class Solution {
public:
    int maxJumps(vector<int>& nums, int d) {
        int n = nums.size();
        vector<int> dp(n,-1);
        vector<pair<int,int>> vec;

        for(int i = 0;i < n;i++){
            vec.push_back({nums[i],i});
        }

        sort(vec.begin(),vec.end());

        for(auto &it: vec){
            int ele = it.first;
            int i = it.second;

            int res = 1;
        
            // left
            for(int j = i-1;j >= max(0,i-d);j--){
                if(nums[j] >= nums[i]) break;
                res = max(res, 1 + dp[j]);
            }

            // Right
            for(int j = i+1;j <= min(n-1,i+d);j++){
                if(nums[j] >= nums[i]) break;
                res = max(res, 1 + dp[j]);
            }

            dp[i] = res;

        }

        return *max_element(dp.begin(),dp.end());
    }
};