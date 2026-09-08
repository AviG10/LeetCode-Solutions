class Solution {
public:
    int countCommas(int n) {
        int len = to_string(n).length();

        if (len < 4)
            return 0;
        else
            return (n - 999);
    }
};