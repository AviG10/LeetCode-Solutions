class Solution {
private:
    // Subarray starting with index i, and Prev Product remainder prevProd
    long long solve(int i, int prevProd, int& x, int& k, int& n,
                    vector<int>& nums, vector<vector<long long>>& dp) {
        if (i >= n)
            return 0;

        if (dp[i][prevProd] != -1)
            return dp[i][prevProd];

        // Not Take
        long long notTake = 0;

        if (prevProd == k)
            notTake = solve(i + 1, prevProd, x, k, n, nums, dp);

        // Take
        long long curProd;
        if (prevProd == k)
            curProd = nums[i];
        else
            curProd = (prevProd * nums[i]) % k;

        long long take =
            (curProd == x) + solve(i + 1, curProd, x, k, n, nums, dp);

        return dp[i][prevProd] = (notTake + take);
    }

public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> result(k, 0);

        for (int i = 0; i < n; i++)
            nums[i] = nums[i] % k;

        for (int x = 0; x <= k - 1; x++) {
            vector<vector<long long>> dp(n, vector<long long>(k + 1, -1));
            result[x] = solve(0, k, x, k, n, nums, dp);
        }

        return result;
    }
};