class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {

        int maxEle = *max_element(nums.begin(), nums.end());

        vector<long long> factorsFreq(maxEle + 1, 0);

        for (auto& num : nums) {
            for (int i = 1; i * i <= num; i++) {
                if (num % i == 0) {
                    factorsFreq[i]++;

                    if (num / i != i)
                        factorsFreq[num / i]++;
                }
            }
        }

        vector<long long> pairsGCDInfo(maxEle + 1, 0);

        for (int i = maxEle; i >= 1; i--) {
            long long count = factorsFreq[i];
            pairsGCDInfo[i] = count * (count - 1) / 2;

            for (int j = 2 * i; j <= maxEle; j += i) {
                pairsGCDInfo[i] -= pairsGCDInfo[j];
            }
        }

        // Compute Cummulative Sum
        for (int i = 1; i <= maxEle; i++) {
            pairsGCDInfo[i] += pairsGCDInfo[i - 1];
        }

        vector<int> result;

        for (auto& q : queries) {
            int l = 1;
            int r = maxEle;
            int ans = -1;

            while (l <= r) {
                int mid = l + (r - l) / 2;

                if (pairsGCDInfo[mid] > q) {
                    ans = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            result.push_back(ans);
        }

        return result;
    }
};