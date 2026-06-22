class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.length();
        vector<int> upper(26,0), lower(26,0);

        for(int i = 0;i < n;i++){
            if(isupper(word[i])) upper[word[i]-'A']++;
            else lower[word[i]-'a']++;
        }

        int cnt = 0;

        for(int i = 0;i < 26;i++){
            if(upper[i] > 0 && lower[i] > 0) cnt++;
        }

        return cnt;
    }
};