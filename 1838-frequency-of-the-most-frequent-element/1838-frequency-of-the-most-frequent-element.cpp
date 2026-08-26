class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int i = 0, j = 0;   
        int result = 0;
        long long curSum = 0;

        while(j < n){
            curSum += nums[j];

            while(nums[j] * (long long)(j - i + 1) > (long long) curSum + k){
                curSum -= nums[i];
                i++;
            }

            result = max(result, j - i + 1);
            j++;
        }

        return result;
    }
};