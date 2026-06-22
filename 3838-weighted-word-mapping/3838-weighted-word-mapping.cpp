class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        unordered_map<int, char> mp;
        string s = "abcdefghijklmnopqrstuvwxyz";

        for (int i = 0; i < s.length(); i++) {
            mp[25 - (s[i] - 'a')] = s[i];
        }

        int n = words.size();
        string ans = "";

        for (int i = 0; i < n; i++) {
            int weightSum = 0;

            for (int j = 0; j < words[i].length(); j++) {
                weightSum += weights[words[i][j] - 'a'];
            }

            ans += mp[weightSum % 26];
        }

        return ans;
    }
};