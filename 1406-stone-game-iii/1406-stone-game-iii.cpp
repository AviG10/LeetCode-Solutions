class Solution {
public:
    string stoneGameIII(vector<int>& stones) {
        int n = stones.size();

        vector<int> dp(n + 1, 0);

        for(int i = n-1;i >= 0;i--){
            int result = INT_MIN;

            result = max(result, stones[i] - dp[i + 1]);

            if (i + 1 < n)
                result = max(result, stones[i] + stones[i + 1] -
                                        dp[i + 2]);

            if (i + 2 < n)
                result = max(result, stones[i] + stones[i + 1] + stones[i + 2] -
                                       dp[i + 3]);

            dp[i] = result;
        }

        int diffSum = dp[0];

        if (diffSum > 0)
            return "Alice";
        else if (diffSum < 0)
            return "Bob";
        else
            return "Tie";
    }
};