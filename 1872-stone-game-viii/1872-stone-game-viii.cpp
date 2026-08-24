class Solution {
private:
    int maxDiff(int i, int& n, vector<int>& prefixSum, vector<int>& dp) {
        if (i == n - 1)
            return prefixSum[n - 1];

        if (dp[i] != INT_MIN)
            return dp[i];

        int notTake = maxDiff(i + 1, n, prefixSum, dp);
        int take = prefixSum[i] - maxDiff(i + 1, n, prefixSum, dp);

        return dp[i] = max(take, notTake);
    }

public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        vector<int> prefixSum(n, 0);
        prefixSum[0] = stones[0];

        for (int i = 1; i < n; i++)
            prefixSum[i] = prefixSum[i - 1] + stones[i];

        vector<int> dp(n + 1, INT_MIN);

        return maxDiff(1, n, prefixSum, dp);
    }
};