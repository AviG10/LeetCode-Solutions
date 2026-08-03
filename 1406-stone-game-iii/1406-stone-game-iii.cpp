class Solution {
private:
    int solve(int i, int& n, vector<int>& stones, vector<int>& dp) {
        if (i >= n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int result = INT_MIN;

        result = max(result, stones[i] - solve(i + 1, n, stones, dp));

        if (i + 1 < n)
            result = max(result, stones[i] + stones[i + 1] -
                                     solve(i + 2, n, stones, dp));

        if (i + 2 < n)
            result = max(result, stones[i] + stones[i + 1] + stones[i + 2] -
                                     solve(i + 3, n, stones, dp));

        return dp[i] = result;
    }

public:
    string stoneGameIII(vector<int>& stones) {
        int n = stones.size();

        vector<int> dp(n + 1, -1);
        int diffSum = solve(0, n, stones, dp);

        if (diffSum > 0)
            return "Alice";
        else if (diffSum < 0)
            return "Bob";
        else
            return "Tie";
    }
};