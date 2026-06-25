class Solution {
    public int countMajoritySubarrays(int[] nums, int target) {
        int n = nums.length;
        int result = 0;
        
        for(int i = 0;i < n;i++){
            int cntTarget = 0;

            for(int j = i;j < n;j++){
                if(nums[j] == target) cntTarget++;
                
                int len = j - i + 1;
                if(cntTarget > len / 2) result++;
            }
        }

        return result;
    }
}