// Standard Sort
// TC : O(n * logn)
// SC : O(1)
// class Solution {
//     public int maximumElementAfterDecrementingAndRearranging(int[] arr) {
//         int n = arr.length;
//         int maxEle = 1;

//         Arrays.sort(arr);

//         arr[0] = 1;

//         for (int i = 1; i < n; i++) {
//             if (arr[i] - arr[i - 1] > 1)
//                 arr[i] = arr[i - 1] + 1;

//             maxEle = Math.max(maxEle, arr[i]);
//         }

//         return maxEle;
//     }
// }

// Counting Sort (Optimized)
// TC : O(n)
// SC : O(n)
class Solution {
    public int maximumElementAfterDecrementingAndRearranging(int[] arr) {
        int n = arr.length;
        int[] freq = new int[n + 1];

        for (int i = 0; i < n; i++) {
            freq[Math.min(arr[i], n)]++;
        }

        int maxEle = 1;

        for (int val = 2; val <= n; val++) {
            maxEle = Math.min(maxEle + freq[val], val);
        }

        return maxEle;
    }
}
