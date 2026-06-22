class Solution {
    public boolean canReach(int[] nums, int start) {
        int n = nums.length;
        Queue<Integer> q = new LinkedList<>();
        boolean[] isVis = new boolean[n];

        q.add(start);

        while(!q.isEmpty()){
            int sz = q.size();

            for(int i = 0;i < sz;i++){
                int ind = q.poll();

                if(nums[ind] == 0) return true;

                if(ind-nums[ind] >= 0 && !isVis[ind-nums[ind]]){
                    q.add(ind-nums[ind]);
                    isVis[ind-nums[ind]] = true;
                }

                if(ind+nums[ind] < n && !isVis[ind+nums[ind]]){
                    q.add(ind+nums[ind]);
                    isVis[ind+nums[ind]] = true;
                }
            }
        }

        return false;
    }
}