class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,vector<int>> mp;
        int ans = INT_MAX;

        for(int k = 0;k < n;k++){
            mp[nums[k]].push_back(k);

            if(mp[nums[k]].size() >= 3){
                int i = mp[nums[k]][mp[nums[k]].size()-3];
                ans = min(ans,2*(k-i));
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};