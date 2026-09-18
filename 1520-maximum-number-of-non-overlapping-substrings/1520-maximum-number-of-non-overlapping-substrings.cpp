class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();

        vector<int> startIdx(26, -1);
        vector<int> endIdx(26, -1);
        vector<int> isValidChar(26, -1);

        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';

            if (startIdx[c] == -1)
                startIdx[c] = i;

            endIdx[c] = i;
        }

        for (int c = 0; c < 26; c++) {
            if (startIdx[c] == -1)
                continue;

            for (int i = startIdx[c]; i <= endIdx[c]; i++) {
                if (startIdx[s[i] - 'a'] < startIdx[c]) {
                    isValidChar[c] = false;
                    break;
                }

                endIdx[c] = max(endIdx[c], endIdx[s[i] - 'a']);
            }
        }

        vector<string> result;
        int lastTakenStrStartIdx = INT_MAX;

        for (int i = n - 1; i >= 0; i--) {
            int c = s[i] - 'a';

            if (isValidChar[c] == false)
                continue;

            if (startIdx[c] == i && endIdx[c] < lastTakenStrStartIdx) {
                result.push_back(s.substr(i, endIdx[c] - i + 1));
                lastTakenStrStartIdx = i;
            }
        }

        return result;
    }
};