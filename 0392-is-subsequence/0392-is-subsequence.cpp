class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.length(), n = t.length();
        vector<int> prev(n + 1, -1), cur(n + 1, -1);

        for (int j = 0; j <= n; j++)
            prev[j] = true;

        cur[n] = false;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (s[i] == t[j])
                    cur[j] = prev[j + 1] || cur[j + 1];
                else
                    cur[j] = cur[j + 1];
            }
            prev = cur;
        }

        return prev[0];
    }
};