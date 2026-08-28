class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length(), n = t.length();

        if(n > m) 
            return "";
        
        unordered_map<char, int> mp;
        for(char ch : t)
            mp[ch]++;
        
        int i = 0, j = 0;
        int start_i = 0;
        int minWindowSize = INT_MAX;
        int countRequired = n;

        while(j < m){
            char ch = s[j];

            if(mp[ch] > 0)
                countRequired--;
            
            mp[ch]--;
            
            while(countRequired == 0){
                int curWindowSize = j - i + 1;
                
                if(curWindowSize < minWindowSize){
                    minWindowSize = curWindowSize;
                    start_i = i;
                }

                mp[s[i]]++;

                if(mp[s[i]] > 0)
                    countRequired++;
                
                i++;
            }

            j++;
        }

        return minWindowSize == INT_MAX ? "" : s.substr(start_i, minWindowSize);
    }
};