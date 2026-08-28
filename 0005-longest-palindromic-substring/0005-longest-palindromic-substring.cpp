class Solution {
private:
    bool isPalindrome(int i, int j, string& s) {
        if (i >= j)
            return true;

        if (s[i] == s[j])
            return isPalindrome(i + 1, j - 1, s);
        else
            return false;
    }

public:
    string longestPalindrome(string s) {
        int n = s.length();
        int maxLen = 0;
        string res = "";

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalindrome(i, j, s)) {
                    int len = j - i + 1;

                    if (len > maxLen) {
                        maxLen = len;
                        res = s.substr(i, j - i + 1);
                    }
                }
            }
        }

        return res;
    }
};