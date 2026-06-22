class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.length();
        vector<int> upper(26, 0), lower(26, 0);
        vector<int> marker(26, false);

        for (int i = 0; i < n; i++) {
            if (islower(word[i])) {
                int idx = word[i] - 'a';
                lower[idx]++;
                if (upper[idx] > 0)
                    marker[idx] = true;
            }
            if (isupper(word[i]))
                upper[word[i] - 'A']++;
        }

        int cnt = 0;

        for (int i = 0; i < 26; i++) {
            if (upper[i] > 0 && lower[i] > 0 && !marker[i])
                cnt++;
        }

        return cnt;
    }
};