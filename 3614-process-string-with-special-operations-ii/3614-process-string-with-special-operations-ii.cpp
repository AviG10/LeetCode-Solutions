class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.length();
        long long len = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                if (len > 0)
                    len--;
            } else if (s[i] == '%')
                continue;
            else if (s[i] == '#')
                len = 2 * len;
            else
                len++;
        }

        if (k >= len)
            return '.';

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '*')
                len++;
            else if (s[i] == '%')
                k = len - k - 1;
            else if (s[i] == '#')
                len /= 2, k = (k >= len) ? k - len : k;
            else
                len--;

            if (k == len)
                return s[i];
        }

        return '.';
    }
};