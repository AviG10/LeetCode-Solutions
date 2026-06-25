class Solution {
    public long countMajoritySubarrays(int[] nums, int target) {
        Map<Integer, Integer> mp = new HashMap<>();
        int n = nums.length;
        long result = 0;
        int validLeftPoints = 0;
        int cumSum = 0;

        mp.put(cumSum, 1);

        for (int i = 0; i < n; i++) {
            if(nums[i] == target){
                validLeftPoints += mp.getOrDefault(cumSum,0);
                cumSum++;
            }
            else{
                cumSum--;
                validLeftPoints -= mp.getOrDefault(cumSum,0);
            }

            mp.put(cumSum, mp.getOrDefault(cumSum, 0) + 1);
            result += validLeftPoints;
        }

        return result;
    }
};