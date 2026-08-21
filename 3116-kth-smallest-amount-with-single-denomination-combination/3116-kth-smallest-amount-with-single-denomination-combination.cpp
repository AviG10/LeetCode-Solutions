class Solution {
private:
    long long cntLessThanEqualToMid(vector<int>& coins, long long mid) {
        int n = coins.size();
        int maxMaskValue = (1 << n) - 1;
        long long cnt = 0;

        for (int mask = 1; mask <= maxMaskValue; mask++) {
            long long setBitsLCM = 1;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    setBitsLCM = lcm(setBitsLCM, coins[i]);
                }
            }

            if (__builtin_popcount(mask) % 2 == 1)
                cnt += (mid / setBitsLCM);
            else
                cnt -= (mid / setBitsLCM);
        }

        return cnt;
    }

public:
    long long findKthSmallest(vector<int>& coins, int k) {
        long long low = 1;
        long long high = 1e11;
        long long ans = 0;

        while (low <= high) {
            long long mid = high + (low - high) / 2;

            long long cnt = cntLessThanEqualToMid(coins, mid);

            if (cnt < k)
                low = mid + 1;
            else {
                high = mid - 1;
                ans = mid;
            }
        }

        return ans;
    }
};