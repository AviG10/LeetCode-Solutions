class Solution {
public:
    int maximumLengthSubstring(string nums) {
        int n = nums.length();
        int i = 0, j = 0;
        int result = 0;
        unordered_map<char, int> mp;

        while(j < n){
            mp[nums[j]]++;

            while(mp[nums[j]] > 2){
                mp[nums[i]]--;
                i++;
            }

            result = max(result, j - i + 1);
            j++;
        }
        
        return result;
    }
};