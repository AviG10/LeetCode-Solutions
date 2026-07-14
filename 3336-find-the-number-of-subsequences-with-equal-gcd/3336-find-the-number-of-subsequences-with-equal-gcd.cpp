class Solution {
private:
    int MOD = 1e9 + 7;

    int solve(int i, int gcd1, int gcd2, int& n, vector<int>& nums, vector<vector<vector<int>>> &dp) {
        if (i == n) {
            bool gcdNonZero = (gcd1 != 0 && gcd2 != 0);
            bool gcdEqual = (gcd1 == gcd2);

            return (gcdNonZero && gcdEqual) ? 1 : 0;
        }

        if(dp[i][gcd1][gcd2] != -1) return dp[i][gcd1][gcd2];

        int skip = solve(i + 1, gcd1, gcd2, n, nums, dp);

        int take_seq1 = solve(i + 1, __gcd(gcd1, nums[i]), gcd2, n, nums, dp);

        int take_seq2 = solve(i + 1, gcd1, __gcd(gcd2, nums[i]), n, nums, dp);

        return dp[i][gcd1][gcd2] = ((long long)skip + take_seq1 + take_seq2) % MOD;
    }

public:
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int maxEle = *max_element(nums.begin(), nums.end());
        
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(maxEle + 1, vector<int>(maxEle + 1, -1)));

        return solve(0, 0, 0, n, nums, dp);
    }
};