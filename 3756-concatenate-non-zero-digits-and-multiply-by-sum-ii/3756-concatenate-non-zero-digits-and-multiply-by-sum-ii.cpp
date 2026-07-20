class Solution {
private:
    int MOD = 1e9 + 7;
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();

        vector<long long> prefixSum(n, 0);
        prefixSum[0] = s[0] - '0';

        for (int i = 1; i < n; i++) {
            int digit = s[i] - '0';
            prefixSum[i] = prefixSum[i - 1] + digit;
        }

        vector<int> prefixNonZeroDigit(n, 0);
        prefixNonZeroDigit[0] = (s[0] != '0') ? 1 : 0;

        for (int i = 1; i < n; i++) {
            int digit = s[i] - '0';
            prefixNonZeroDigit[i] = prefixNonZeroDigit[i - 1] + ((digit != 0) ? 1 : 0);
        }

        vector<long long> prefixNumber(n, 0);
        prefixNumber[0] = s[0] - '0';

        for (int i = 1; i < n; i++) {
            int digit = s[i] - '0';

            if (digit != 0)
                prefixNumber[i] = (prefixNumber[i - 1] * 10 + digit) % MOD;
            else
                prefixNumber[i] = prefixNumber[i - 1];
        }

        vector<long long> pow10(n+1,0);
        pow10[0] = 1;
        
        for(int i = 1; i <= n; i++){
            pow10[i] = (pow10[i-1] * 10) % MOD;
        }

        int q_size = queries.size();
        vector<int> result(q_size, 0);
        for (int i = 0; i < q_size; i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            long long sum = prefixSum[r] - ((l > 0) ? prefixSum[l - 1] : 0);
            int k = prefixNonZeroDigit[r] - ((l > 0) ? prefixNonZeroDigit[l - 1] : 0);
            int numberBefore = (l > 0) ? prefixNumber[l - 1] : 0;
            long long x = (prefixNumber[r] - (numberBefore * pow10[k]) % MOD + MOD) % MOD;

            result[i] = (x * sum) % MOD;
        }

        return result;
    }
};