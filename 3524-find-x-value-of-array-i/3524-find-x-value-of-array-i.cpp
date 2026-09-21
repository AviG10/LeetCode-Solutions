class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> result(k, 0);

        for (int i = 0; i < n; i++)
            nums[i] = nums[i] % k;

        for (int x = 0; x <= k - 1; x++) {
            vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));

            for (int i = n - 1; i >= 0; i--) {
                
                for (int prevProd = 0; prevProd <= k; prevProd++) {
                    // Not Take
                    long long notTake = 0;

                    if (prevProd == k)
                        notTake = dp[i + 1][prevProd];

                    // Take
                    long long curProd;
                    if (prevProd == k)
                        curProd = nums[i];
                    else
                        curProd = (prevProd * nums[i]) % k;

                    long long take = (curProd == x) + dp[i + 1][curProd];

                    dp[i][prevProd] = (notTake + take);
                }
            }

            result[x] = dp[0][k];
        }

        return result;
    }
};