class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(nums[i] % k == 0){
                mp[nums[i] / k]++;
            }
        }

        int result = 1;
        
        while(mp[result] > 0){
            result++;
        }

        return result * k;
    }
};