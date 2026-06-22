class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.length();
        unordered_map<char, int> mp;

        for(int i = 0;i < n;i++){
            mp[text[i]]++;
        }

        int word = INT_MAX;

        word = min(word, mp['b']);
        word = min(word, mp['a']);
        word = min(word, mp['n']);
        word = min(word, mp['l'] / 2);
        word = min(word, mp['o'] / 2);
        
        return word;
    }
};