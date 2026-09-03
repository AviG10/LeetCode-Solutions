class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        int ans = 0;

        vector<int> freq(26,0);
        for(int i = 0; i < n; i++)
            freq[s[i] - 'a']++;
        
        int uniqueChars = 0;

        for(int i = 0; i < 26; i++)
            if(freq[i] > 0)
                uniqueChars++;
        
        
        for(int curUniqueChars = 1; curUniqueChars <= uniqueChars; curUniqueChars++){
            vector<int> freqMap(26, 0);

            int i = 0, j = 0;
            int cntUniqueChar = 0, cntGreaterThanK = 0;

            while(j < n){
                // 1. Expand Window by including s[j]
                if(freqMap[s[j] - 'a'] == 0)
                    cntUniqueChar++;

                freqMap[s[j] - 'a']++;
                
                if(freqMap[s[j] - 'a'] == k) 
                    cntGreaterThanK++;
                
                j++;

                // 2. Shrink Window by excluding s[i]
                while(cntUniqueChar > curUniqueChars){
                    if(freqMap[s[i] - 'a'] == k) 
                        cntGreaterThanK--;
                    
                    freqMap[s[i] - 'a']--;

                    if(freqMap[s[i] - 'a'] == 0)
                        cntUniqueChar--;
                    
                    i++;
                }

                // 3. Update the answer if the current window is valid
                if(cntUniqueChar == curUniqueChars && cntGreaterThanK == curUniqueChars)
                    ans = max(ans, j - i);
            }
        }

        return ans;
    }   
};