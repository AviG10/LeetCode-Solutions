class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int result = 0;
        unordered_map<int, int> mp;

        while(j < n){
            mp[nums[j]]++;

            while(mp.size() > 2){
                mp[nums[i]]--;
                
                if(mp[nums[i]] == 0)
                    mp.erase(nums[i]);

                i++;
            }

            result = max(result, j - i + 1);
            j++;
        }

        return result;
    }
};