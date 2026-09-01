class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) 
            return nums[0];

        vector<int> numsWithoutFirstEle, numsWithoutLastEle;

        for(int i = 0; i < n; i++){
            if(i != 0)
                numsWithoutFirstEle.push_back(nums[i]);
            if(i != n - 1)
                numsWithoutLastEle.push_back(nums[i]);
        }

        vector<int> dp1(n, -1), dp2(n, -1);

        dp1[0] = 0;
        dp1[1] = numsWithoutFirstEle[0];

        dp2[0] = 0;
        dp2[1] = numsWithoutLastEle[0];

        for(int i = 2; i < n; i++){
            dp1[i] = max(numsWithoutFirstEle[i-1] + dp1[i - 2], dp1[i - 1]);
            dp2[i] = max(numsWithoutLastEle[i-1] + dp2[i - 2], dp2[i - 1]);
        }

        return max(dp1[n-1], dp2[n-1]);
    }
};