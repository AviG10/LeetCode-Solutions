class Solution {
public:
    int maxProduct(int n) {
        vector<int> digits;
        string numStr = to_string(n);

        for(int i = 0; i < numStr.size(); i++)
            digits.push_back(numStr[i] - '0');

        sort(digits.begin(), digits.end());

        int sz = digits.size();

        return digits[sz-1] * digits[sz-2];
    }
};