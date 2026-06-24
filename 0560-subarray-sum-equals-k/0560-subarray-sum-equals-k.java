class Solution {
    public int subarraySum(int[] nums, int k) {
        int n = nums.length;
        Map<Integer, Integer> mp = new HashMap<>();
        int sum = 0;
        int result = 0;

        for(int i = 0;i < n;i++){
            sum += nums[i];

            if(sum == k) result++;

            if(mp.containsKey(sum - k)) 
                result += mp.get(sum - k);

            mp.put(sum, mp.getOrDefault(sum, 0) + 1);
        }

        return result;
    }
}