class Solution {
    private int[] previous_smaller(int[] nums){
        int n = nums.length;
        int[] ans = new int[n];
        Deque<Integer> st = new ArrayDeque<>();

        for(int i = 0;i < n;i++){
            while(!st.isEmpty() && nums[st.peek()] >= nums[i])
                st.pop();
            
            ans[i] = st.isEmpty() ? -1 : st.peek();

            st.push(i);
        }

        return ans;
    }

    private int[] next_smaller(int[] nums){
        int n = nums.length;
        int[] ans = new int[n];
        Deque<Integer> st = new ArrayDeque<>();

        for(int i = n-1;i >= 0;i--){
            while(!st.isEmpty() && nums[st.peek()] >= nums[i])
                st.pop();
            
            ans[i] = st.isEmpty() ? n : st.peek();

            st.push(i);
        }

        return ans;
    }

    public int largestRectangleArea(int[] heights) {
        int n = heights.length;
        int[] ps = previous_smaller(heights);
        int[] ns = next_smaller(heights);

        int ans = Integer.MIN_VALUE;
        for(int i = 0;i < n;i++){
            ans = Math.max(ans, (ns[i] - ps[i] - 1) * heights[i]);
        }

        return ans;
    }
}