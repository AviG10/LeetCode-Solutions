class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = 0, f_0 = 0;

        for(int i = 0;i < n;i++){
            sum += nums[i];
            f_0 += (i * nums[i]);
        }

        int lastInd = n-1;
        int f_k = f_0, f_k_1 = 0;
        int ans = f_0;

        for(int k = 1;k < n;k++){
            f_k_1 = (f_k + sum) - (n * nums[lastInd]);
            ans = max(ans,f_k_1);
            lastInd--;
            f_k = f_k_1;
        }

        return ans;
    }
};