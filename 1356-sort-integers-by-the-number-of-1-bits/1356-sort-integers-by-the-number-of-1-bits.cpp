class Solution {
public:
    vector<int> sortByBits(vector<int>& nums) {
        map<int,vector<int>> mp;
        int n = nums.size();

        for(int i = 0;i < n;i++){
            int cntSetBits = __builtin_popcount(nums[i]);
            mp[cntSetBits].push_back(nums[i]);
        }

        vector<int> ans;
        for(auto itMap: mp){
            sort(itMap.second.begin(),itMap.second.end());
            for(int i = 0;i < itMap.second.size();i++){
                ans.push_back(itMap.second[i]);
            }
        }

        return ans;
    }
};