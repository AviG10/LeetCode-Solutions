class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        vector<int> prefixSum(n, 0);
        prefixSum[0] = stones[0];

        for (int i = 1; i < n; i++)
            prefixSum[i] = prefixSum[i - 1] + stones[i];

        int prev = INT_MIN, cur = INT_MIN;
        prev = prefixSum[n-1];

        for(int i = n-2;i >= 1; i--){
            int notTake = prev;
            int take = prefixSum[i] - prev;

            cur = max(take, notTake);
            prev = cur;
        }

        return prev;
    }
};