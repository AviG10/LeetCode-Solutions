class Solution {
public:
    bool checkValidString(string s) {
        int mini = 0, maxi = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                mini++;
                maxi++;
            } else if (s[i] == '*') {
                mini = max(mini - 1, 0);
                maxi++;
            } else {
                maxi--;
                mini = max(mini - 1, 0);
            }

            if (maxi < 0)
                return false;
        }

        if (mini == 0)
            return true;
        else
            return false;
    }
};