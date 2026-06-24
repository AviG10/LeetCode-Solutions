class Solution {
    private int kadanesMax(int[] nums){
        int n = nums.length;
        int maxi = Integer.MIN_VALUE;
        int sum = 0;

        for(int i = 0;i < n;i++){
            sum += nums[i];

            if(maxi < sum){
                maxi = Math.max(maxi, sum);
            }

            if(sum < 0) sum = 0;
        }   

        return maxi;
    }

    private int kadanesMin(int[] nums){
        int n = nums.length;
        int mini = Integer.MAX_VALUE;
        int sum = 0;

        for(int i = 0;i < n;i++){
            sum += nums[i];

            if(mini > sum){
                mini = sum;
            }

            if(sum > 0) sum = 0;
        }   

        return mini;
    }

    public int maxSubarraySumCircular(int[] nums) {
        int nonCircularMaxSum = kadanesMax(nums);

        int arrayTotalSum = 0;

        for(int i = 0;i < nums.length;i++){
            arrayTotalSum += nums[i];
        }

        int minimumSubarraySum = kadanesMin(nums);

        int circularMaxSum = arrayTotalSum - minimumSubarraySum;

        if(nonCircularMaxSum > 0) return Math.max(nonCircularMaxSum, circularMaxSum);
        else return nonCircularMaxSum;
    }
}