class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        Map<Integer, Integer> mp = new HashMap<>();
        int n = nums.length;
        int result = 0;
        int cumSum = 0;
        int rem = 0;

        mp.put(rem, 1);

        for (int i = 0; i < n; i++) {
            cumSum += nums[i];

            rem = cumSum % k;

            if(rem < 0) rem += k;
            
            if(mp.containsKey(rem)){
                result += mp.get(rem);
            }

            mp.put(rem,mp.getOrDefault(rem, 0) + 1);
        }

        return result;
    }
}