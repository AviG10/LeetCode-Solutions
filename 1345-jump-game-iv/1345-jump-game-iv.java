class Solution {
    public int minJumps(int[] nums) {
        int n = nums.length;
        boolean[] isVis = new boolean[n];
        Map<Integer,List<Integer>> mp = new HashMap<>();

        for(int i = 0;i < n;i++){
            mp.putIfAbsent(nums[i], new ArrayList<>());
            mp.get(nums[i]).add(i);
        }

        Queue<Integer> q = new LinkedList<>();
        int steps = 0;

        q.add(0);
        isVis[0] = true;

        while(!q.isEmpty()){
            int sz = q.size();

            while(sz-- > 0){
                int i = q.poll();

                if(i == n-1) return steps;

                if(i-1 >= 0 && !isVis[i-1]){
                    q.add(i-1);
                    isVis[i-1] = true;
                }

                if(i+1 < n && !isVis[i+1]){
                    q.add(i+1);
                    isVis[i+1] = true;
                }

                if (mp.containsKey(nums[i])){
                    for(int it: mp.get(nums[i])){
                        if(!isVis[it]){
                            q.add(it);
                            isVis[it] = true;
                        }
                    }

                    mp.remove(nums[i]);
                }
            }

            steps++;
        }

        return steps;
    }
}