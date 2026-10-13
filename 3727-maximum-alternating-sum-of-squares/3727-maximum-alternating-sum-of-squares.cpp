class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(nums[i] < 0){
                nums[i] = - nums[i];
            }
        }

        sort(nums.begin(), nums.end());
        
        int posContributors = (n % 2 == 1) ? (n / 2 + 1) : (n / 2);

        long long ans = 0;

        for(int i = n-1;i > n - 1 - posContributors; i--){
            ans += (long long) nums[i] * nums[i];
        }
        
        cout<<ans<<endl;
        
        for(int i = n - 1 - posContributors; i >= 0; i--){
            ans -= (long long) nums[i] * nums[i];
        }

        return ans;

    }
};