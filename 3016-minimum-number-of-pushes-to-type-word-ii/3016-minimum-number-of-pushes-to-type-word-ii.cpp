class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        vector<int> charFreq(26, 0);

        for (int i = 0; i < n; i++)
            charFreq[word[i] - 'a']++;

        sort(charFreq.begin(), charFreq.end());

        int ans = 0;

        for (int i = 25; i >= 0; i--) {
            if (charFreq[i] != 0) {
                int counter = 26 - i;

                if (counter <= 8) 
                    ans += (1 * charFreq[i]);
                else if (counter >= 9 && counter <= 16)
                    ans += (2 * charFreq[i]);
                else if (counter >= 17 && counter <= 24)
                    ans += (3 * charFreq[i]);
                else
                    ans += (4 * charFreq[i]);
            } else
                break;
        }

        return ans;
    }
};
