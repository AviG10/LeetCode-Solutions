class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> dp(n + 1, -1);

        dp[0] = 0;

        for(int num = 1; num <= n;num++){
            bool ans = false;

            for (int i = 1; i * i <= num; i++) {
                if (dp[num - i * i] == false) {
                    ans = true;
                }
            }

            dp[num] = ans;
        }

        return dp[n];
    }
};