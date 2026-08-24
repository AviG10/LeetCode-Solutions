class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        vector<int> prefixSum(n, 0);
        prefixSum[0] = stones[0];

        for (int i = 1; i < n; i++)
            prefixSum[i] = prefixSum[i - 1] + stones[i];

        vector<int> dp(n + 1, INT_MIN);
        dp[n-1] = prefixSum[n-1];

        for(int i = n-2;i >= 1; i--){
            int notTake = dp[i + 1];
            int take = prefixSum[i] - dp[i + 1];

            dp[i] = max(take, notTake);
        }

        return dp[1];
    }
};