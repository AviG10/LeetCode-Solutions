class Solution {
    public int maximumElementAfterDecrementingAndRearranging(int[] arr) {
        int n = arr.length;
        int maxEle = 1;

        Arrays.sort(arr);

        arr[0] = 1;

        for (int i = 1; i < n; i++) {
            if (arr[i] - arr[i - 1] > 1)
                arr[i] = arr[i - 1] + 1;

            maxEle = Math.max(maxEle, arr[i]);
        }

        return maxEle;
    }
}