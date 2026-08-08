class Solution {
private:
    long long primeFactorization(long long num) {
        for (int primeFactor : {2, 3, 5, 7}) {
            while (num % primeFactor == 0) {
                num /= primeFactor;
            }
        }
        return num;
    }

    void preComputeRemainingFactor(vector<long long>& remainingFactor,
                                   string& s, int& n) {
        for (int i = 0; i < n; i++) {
            int digit = s[i] - '0';

            if (digit == 0)
                break;

            remainingFactor[i + 1] =
                remainingFactor[i] / gcd(remainingFactor[i], digit);
        }
    }

    int computeZeroIdx(string& s) {
        int n = s.length();
        int idx = n - 1;
        int zeroPos = s.find('0');

        if (zeroPos != -1)
            idx = zeroPos;

        return idx;
    }

    string freeSlotFiller(long long required, int length) {
        string str;

        for (int digit = 9; digit >= 2; digit--) {
            while (required % digit == 0) {
                required /= digit;
                str.push_back(digit + '0');
            }
        }

        while (str.length() < length)
            str.push_back('1');

        reverse(str.begin(), str.end());

        return str;
    }

public:
    string smallestNumber(string s, long long t) {
        int n = s.length();

        if (primeFactorization(t) != 1)
            return "-1";

        vector<long long> remainingFactor(n + 1, t);
        preComputeRemainingFactor(remainingFactor, s, n);

        if (remainingFactor[n] == 1)
            return s;

        int zeroIdx = computeZeroIdx(s);

        for (int i = zeroIdx; i >= 0; i--) {
            long long required = remainingFactor[i];
            int freeSlot = n - i - 1;

            for (int digit = (s[i] - '0')+1; digit <= 9; digit++) {
                long long furtherRequired =
                    required / gcd(required, (long long)digit);
                string requiredNumber =
                    freeSlotFiller(furtherRequired, freeSlot);

                if (requiredNumber.length() == freeSlot)
                    return s.substr(0, i) + char(digit + '0') + requiredNumber;
            }
        }

        return freeSlotFiller(t, n + 1);
    }
};