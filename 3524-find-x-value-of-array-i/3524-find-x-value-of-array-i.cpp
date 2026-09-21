class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> result(k, 0);

        for (int i = 0; i < n; i++)
            nums[i] = nums[i] % k;

        for (int x = 0; x <= k - 1; x++) {
            vector<long long> prev(k+1, 0), cur(k + 1, 0);

            for (int i = n - 1; i >= 0; i--) {
                
                for (int prevProd = 0; prevProd <= k; prevProd++) {
                    // Not Take
                    long long notTake = 0;

                    if (prevProd == k)
                        notTake = prev[prevProd];

                    // Take
                    long long curProd;
                    if (prevProd == k)
                        curProd = nums[i];
                    else
                        curProd = (prevProd * nums[i]) % k;

                    long long take = (curProd == x) + prev[curProd];

                    cur[prevProd] = (notTake + take);
                }

                prev = cur;
            }

            result[x] = prev[k];
        }

        return result;
    }
};