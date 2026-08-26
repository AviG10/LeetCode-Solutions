class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        unordered_map<int, int> mp;
        long long sum = 0, ans = 0;

        while(j < n){
            mp[nums[j]]++;
            sum += nums[j];

            while(mp[nums[j]] > 1){
                mp[nums[i]]--;
                sum -= nums[i];
                i++;
            }

            if(j - i + 1 == k){
                ans = max(ans, sum);
                
                mp[nums[i]]--;
                sum -= nums[i];
                i++;
            }

            j++;
        }

        return ans;
    }
};