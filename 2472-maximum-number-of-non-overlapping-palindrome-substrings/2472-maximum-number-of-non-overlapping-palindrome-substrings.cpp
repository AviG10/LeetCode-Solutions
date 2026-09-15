class Solution {
private:
    bool isPalindrome(int start, int end, string& s) {
        if (start >= end)
            return true;

        if (s[start] == s[end])
            return isPalindrome(start + 1, end - 1, s);
        else
            return false;
    }

    int f(int ind, int& k, int& n, string& s, vector<int>& dp) {
        if (ind == n)
            return 0;

        if (dp[ind] != -1)
            return dp[ind];

        // non-take
        int nonTake = f(ind + 1, k, n, s, dp);

        // take
        int take = INT_MIN;
        for (int end = ind + k - 1; end < n; end++) {
            if (isPalindrome(ind, end, s))
                take = max(take, 1 + f(end + 1, k, n, s, dp));
        }

        return dp[ind] = max(nonTake, take);
    }

public:
    int maxPalindromes(string s, int k) {
        int n = s.length();

        vector<int> dp(n, -1);

        return f(0, k, n, s, dp);
    }
};