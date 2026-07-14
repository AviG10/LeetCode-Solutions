// Space Optimization
// TC: O(n * maxEle * maxEle)
// SC: 2 * O(maxEle * maxEle)
class Solution {
private:
    int MOD = 1e9 + 7;
public:
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int maxEle = *max_element(nums.begin(), nums.end());
 
        vector<vector<int>> prev(maxEle + 1, vector<int>(maxEle + 1, -1)), cur(maxEle + 1, vector<int>(maxEle + 1, -1));

        for(int gcd1 = 0; gcd1 <= maxEle; gcd1++){
            for(int gcd2 = 0; gcd2 <= maxEle; gcd2++){
                bool gcdNonZero = (gcd1 != 0 && gcd2 != 0);
                bool gcdEqual = (gcd1 == gcd2);

                prev[gcd1][gcd2] = (gcdNonZero && gcdEqual) ? 1 : 0;
            }
        }

        for(int i = n-1; i >= 0; i--){
            for(int gcd1 = 0; gcd1 <= maxEle; gcd1++){
                for(int gcd2 = 0; gcd2 <= maxEle; gcd2++){
                    int skip = prev[gcd1][gcd2];

                    int take_seq1 = prev[__gcd(gcd1, nums[i])][gcd2];

                    int take_seq2 = prev[gcd1][__gcd(gcd2, nums[i])];

                    cur[gcd1][gcd2] = ((long long)skip + take_seq1 + take_seq2) % MOD;
                }
            }
            prev = cur;
        }

        return prev[0][0];
    }
};