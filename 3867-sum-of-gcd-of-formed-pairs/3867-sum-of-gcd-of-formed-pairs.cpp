class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> mxi(n, 0);

        mxi[0] = max(mxi[0], nums[0]);
        for (int i = 1; i < n; i++) {
            mxi[i] = max(mxi[i - 1], nums[i]);
        }

        vector<int> prefixGcd(n, 0);
        for (int i = 0; i < n; i++) {
            prefixGcd[i] = __gcd(nums[i], mxi[i]);
        }  

        sort(prefixGcd.begin(), prefixGcd.end());

        int start = 0, end = n-1;
        long long ans = 0;

        while(start < end){
            ans += __gcd(prefixGcd[start], prefixGcd[end]);
            start++;
            end--;
        }

        return ans;
    }
};