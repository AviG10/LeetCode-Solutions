class Solution {
public:
    int reverseDegree(string s) {
        int n = s.length();
        int product = 0;

        for (int i = 0; i < n; i++) {
            int reverseIdx = 26 - (s[i] - 'a');
            int orginalIdx = i + 1;

            product += reverseIdx * orginalIdx;
        }

        return product;
    }
};