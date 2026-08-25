class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(nums[i] % k == 0){
                mp[nums[i] / k]++;
            }
        }

        int multi = 1;

        while(mp[multi] > 0){
            multi++;
        }

        return multi * k;
    }
};