class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        int n = nums.length;
        Map<Integer, Integer> mp = new HashMap<>();

        for (int i = 0; i < n; i++) {
            mp.put(nums[i], mp.getOrDefault(nums[i], 0) + 1);
        }

        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b) -> Integer.compare(a[0], b[0]));
        
        for(Map.Entry<Integer, Integer> it: mp.entrySet()){
            pq.add(new int[]{it.getValue(), it.getKey()});

            if(pq.size() > k) 
                pq.poll();
        }

        int[] ans = new int[k];
        int idx = 0;

        while(!pq.isEmpty()){
            ans[idx] = pq.poll()[1];
            idx++;
        }

        return ans;
    }
}