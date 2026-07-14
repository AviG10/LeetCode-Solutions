class Solution {
private:
    int MOD = 1e9 + 7;
public:
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int maxEle = *max_element(nums.begin(), nums.end());
        
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(maxEle + 1, vector<int>(maxEle + 1, -1)));

        for(int gcd1 = 0; gcd1 <= maxEle; gcd1++){
            for(int gcd2 = 0; gcd2 <= maxEle; gcd2++){
                bool gcdNonZero = (gcd1 != 0 && gcd2 != 0);
                bool gcdEqual = (gcd1 == gcd2);

                dp[n][gcd1][gcd2] = (gcdNonZero && gcdEqual) ? 1 : 0;
            }
        }

        for(int i = n-1; i >= 0; i--){
            for(int gcd1 = 0; gcd1 <= maxEle; gcd1++){
                for(int gcd2 = 0; gcd2 <= maxEle; gcd2++){
                    int skip = dp[i + 1][gcd1][gcd2];

                    int take_seq1 = dp[i + 1][__gcd(gcd1, nums[i])][gcd2];

                    int take_seq2 = dp[i + 1][gcd1][__gcd(gcd2, nums[i])];

                    dp[i][gcd1][gcd2] = ((long long)skip + take_seq1 + take_seq2) % MOD;
                }
            }
        }

        return dp[0][0][0];
    }
};