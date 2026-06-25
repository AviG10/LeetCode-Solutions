class Solution {
    public List<List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> Integer.compare(b[0], a[0])); // Max - Heap

        for(int i = 0;i < nums1.length;i++){
            for(int j = 0;j < nums2.length;j++){
                int sum = nums1[i] + nums2[j];

                if(pq.size() < k){
                    pq.add(new int[] {sum, nums1[i], nums2[j]});
                }
                else if(pq.peek()[0] > sum){
                    pq.poll();
                    pq.add(new int[]{sum, nums1[i], nums2[j]});
                }
                else
                    break;
            }
        }
        
        List<List<Integer>> result = new ArrayList<>();

        while(!pq.isEmpty()){
            int[] temp = pq.poll();
            result.add(Arrays.asList(temp[1], temp[2]));
        }

        return result;
    }
}