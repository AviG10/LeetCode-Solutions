class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int> zerosBlock;
        int n = s.length();
        int originalActiveSections = 0;
        int idx = 0;

        while (idx < n) {
            if (s[idx] == '0') {
                int startIdx = idx;

                while (idx < n && s[idx] == '0')
                    idx++;

                zerosBlock.push_back(idx - startIdx);
            } else {
                originalActiveSections++;
                idx++;
            }
        }

        int activeSectionsAfterTrade = 0;
        for (int i = 1; i < zerosBlock.size(); i++) 
            activeSectionsAfterTrade = max(activeSectionsAfterTrade, zerosBlock[i] + zerosBlock[i - 1]);

        return originalActiveSections + activeSectionsAfterTrade;
    }
};