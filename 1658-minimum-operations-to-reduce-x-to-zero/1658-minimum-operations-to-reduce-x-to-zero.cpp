class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int i = 0, j = 0;
        int totalSum = 0, curSum = 0;
        int result = -1;

        for(int k = 0; k < n; k++)
            totalSum += nums[k];

        if(totalSum < x)
            return -1;

        while(j < n){
            curSum += nums[j];

            while(curSum > totalSum - x){
                curSum -= nums[i];
                i++;
            }

            if(curSum == totalSum - x)
                result = max(result, j - i + 1);

            j++;
        }

        return result == -1 ? result : n - result;
    }
};