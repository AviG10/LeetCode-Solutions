class Solution {
private:
    long long nCr(int n, int r, int& k) {
        r = min(r, n - r);

        long long result = 1;

        for (int i = 1; i <= r; i++) {
            result = result * (n - r + i) / i;

            if (result >= k)
                return k;
        }

        return result;
    }

public:
    string smallestPalindrome(string s, int k) {
        int n = s.length();

        char mid = ' ';
        if (n % 2 == 1)
            mid = s[n / 2];

        vector<int> freqChar(26, 0);
        for (int i = 0; i < n; i++) {
            if (n % 2 == 1 && i == n / 2)
                continue;
            freqChar[s[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++)
            freqChar[i] /= 2;

        string halfResult = "";
        int halfResultLen = n / 2;

        for (int i = 0; i < halfResultLen; i++) {
            bool characterPlaced = false;

            for (int j = 0; j < 26; j++) {
                if (freqChar[j] > 0) {
                    freqChar[j]--;

                    long long ways = 1;

                    int letters = 0;
                    for (int c = 0; c < 26; c++) {
                        letters += freqChar[c];
                    }

                    for (int c = 0; c < 26; c++) {
                        if (freqChar[c] > 0) {
                            ways *= nCr(letters, freqChar[c], k);
                            letters -= freqChar[c];
                        }

                        if (ways >= k)
                            break;
                    }

                    if (ways >= k) {
                        halfResult.push_back(j + 'a');
                        characterPlaced = true;
                        break;
                    } else {
                        k -= ways;
                        freqChar[j]++;
                    }
                }
            }

            if (!characterPlaced)
                return "";
        }

        string reverseHalfResult = halfResult;
        reverse(reverseHalfResult.begin(), reverseHalfResult.end());

        if (mid != ' ')
            halfResult.push_back(mid);

        return halfResult + reverseHalfResult;
    }
};