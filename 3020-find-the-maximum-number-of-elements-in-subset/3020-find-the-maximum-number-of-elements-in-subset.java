class Solution {
    public int maximumLength(int[] nums) {
        int n = nums.length;
        Map<Long, Integer> mp = new HashMap<>();

        for (int num : nums) {
            long key = (long) num;
            mp.put(key, mp.getOrDefault(key, 0) + 1);
        }

        int ans = Integer.MIN_VALUE;

        if (mp.containsKey(1L)) {
            int freq = mp.get(1L);
            ans = Math.max(ans, freq % 2 == 1 ? freq : freq - 1);
        }

        for (Map.Entry<Long, Integer> entry : mp.entrySet()) {
            long num = entry.getKey();
            int freq = entry.getValue();

            if (num == 1L)
                continue;

            long x = num;
            int len = 0;

            while (mp.containsKey(x) && mp.get(x) >= 2) {
                len += 2;
                x = x * x;
            }

            if (mp.containsKey(x))
                len++;
            else
                len--;

            ans = Math.max(ans, len);
        }

        return ans;
    }
}