class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int i = 0, j = 0;
        int result = 0;
        unordered_map<char, int> mp;

        while(j < n){
            mp[s[j]]++;

            while(mp[s[j]] > 1){
                mp[s[i]]--;
                i++;
            }

            result = max(result, j - i + 1);
            
            j++;
        }

        return result;
    }
};