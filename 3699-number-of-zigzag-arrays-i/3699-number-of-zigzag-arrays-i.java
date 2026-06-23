// Tabulation + prefixSum
class Solution {
    int MOD = (int) (1e9 + 7);

    public int zigZagArrays(int n, int l, int r) {
        r = r - l + 1;
        l = 1;

        int[][][] dp = new int[n + 1][r + 1][2];

        for (int prevVal = l; prevVal <= r; prevVal++) {
            dp[n][prevVal][0] = 1;
            dp[n][prevVal][1] = 1;
        }

        for (int i = n - 1; i >= 0; i--) {

            int[] prefixSumIncreasing = new int[r + 1];
            int[] prefixSumDecreasing = new int[r + 1];

            for (int prevVal = l; prevVal <= r; prevVal++) {
                prefixSumIncreasing[prevVal] = (prefixSumIncreasing[prevVal-1] + dp[i+1][prevVal][1]) % MOD;
                prefixSumDecreasing[prevVal] = (prefixSumDecreasing[prevVal-1] + dp[i+1][prevVal][0]) % MOD;
            }

            for (int prevVal = l; prevVal <= r; prevVal++) {
                dp[i][prevVal][1] = ( prefixSumDecreasing[r] - prefixSumDecreasing[prevVal] + MOD ) % MOD;
                dp[i][prevVal][0] = prefixSumIncreasing[prevVal - 1] % MOD;
            }
        }

        long ans = 0;

        for (int startVal = l; startVal <= r; startVal++) {
            ans = (ans + dp[1][startVal][1]) % MOD; //increasing
            ans = (ans + dp[1][startVal][0]) % MOD; //decreasing
        }

        return (int) ans;
    }
}