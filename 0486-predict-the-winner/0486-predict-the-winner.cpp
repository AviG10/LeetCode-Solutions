class Solution {
private:
    int solve(int i, int j, vector<int>& nums, vector<vector<int>> &dp) {
        if (i > j)
            return 0;
        if (i == j)
            return nums[i];

        if(dp[i][j] != -1)
            return dp[i][j];

        int take_i =
            nums[i] + min(solve(i + 1, j - 1, nums, dp), solve(i + 2, j, nums, dp));
        int take_j =
            nums[j] + min(solve(i + 1, j - 1, nums, dp), solve(i, j - 2, nums, dp));

        return dp[i][j] = max(take_i, take_j);
    }

public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;

        for (int i = 0; i < n; i++)
            totalSum += nums[i];
        
        vector<vector<int>> dp(n, vector<int>(n,-1));

        int player1_score = solve(0, n - 1, nums, dp);
        int player2_score = totalSum - player1_score;

        return player1_score >= player2_score;
    }
};