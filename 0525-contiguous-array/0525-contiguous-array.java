class Solution {
    public int findMaxLength(int[] nums) {
        int n = nums.length;
        int result = 0;
        int cumSum = 0;

        Map<Integer, Integer> mp = new HashMap<>();
        mp.put(cumSum, -1);

        for(int i = 0;i < n;i++){
            cumSum += (nums[i] == 1) ? 1 : -1;

            if(mp.containsKey(cumSum)){
                result = Math.max(result, i - mp.get(cumSum));
            }
            else{
                mp.put(cumSum, i);
            }

        }

        return result;
    }
};