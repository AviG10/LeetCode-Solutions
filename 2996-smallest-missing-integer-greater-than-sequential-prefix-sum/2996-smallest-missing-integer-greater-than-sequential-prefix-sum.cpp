class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        
        int prefixSum = nums[0];
        bool prefix = true;
        
        unordered_map<int, int> mp;
        mp[nums[0]]++;

        for(int i = 1;i < n;i++){
            if(prefix){
                if(nums[i] == nums[i-1] + 1)
                    prefixSum += nums[i];
                else 
                    prefix = false;
            }

            mp[nums[i]]++;
        }
 
        while(mp[prefixSum] > 0)
            prefixSum++;

        return prefixSum;
    }
};