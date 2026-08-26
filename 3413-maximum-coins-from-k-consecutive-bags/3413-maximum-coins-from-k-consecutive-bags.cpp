class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        sort(coins.begin(), coins.end());

        int n = coins.size();
        int i = 0, j = 0;
        long long curSum = 0, result = 0;

        // Start with coins[i][0]
        while (i < n) {
            while (j < n && coins[j][1] <= coins[i][0] + k - 1) {
                curSum +=
                    (long long)(coins[j][1] - coins[j][0] + 1) * coins[j][2];
                j++;
            }

            if (j < n) {
                long long partialSum =
                    (long long)max(0, (coins[i][0] + k - 1 - coins[j][0] + 1)) *
                    coins[j][2];
                result = max(result, curSum + partialSum);
            }

            curSum -= (long long)(coins[i][1] - coins[i][0] + 1) * coins[i][2];
            i++;
        }

        i = 0, j = 0, curSum = 0;

        // End with coins[i][1]
        while (i < n) {
            curSum += (long long)(coins[i][1] - coins[i][0] + 1) * coins[i][2];

            while (coins[j][1] < coins[i][1] - k + 1) {
                curSum -=
                    (long long)(coins[j][1] - coins[j][0] + 1) * coins[j][2];
                j++;
            }

            long long partialSum =
                (long long)max(0, coins[i][1] - k + 1 - coins[j][0]) *
                coins[j][2];
            result = max(result, curSum - partialSum);

            i++;
        }

        return result;
    }
};