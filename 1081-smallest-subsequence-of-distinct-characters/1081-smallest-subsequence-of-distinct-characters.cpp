class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.length();
        vector<int> lastSeen(26,-1);
        vector<bool> isTaken(26, false);

        for(int i = 0;i < n;i++){
            lastSeen[s[i] - 'a'] = i;
        }
        
        string res = "";

        for(int i = 0;i < n;i++){
            if(isTaken[s[i] - 'a']) continue;
            
            while(res.length() > 0 && res.back() > s[i] && lastSeen[res.back() - 'a'] > i){
                isTaken[res.back() - 'a'] = false;
                res.pop_back();
            }

            isTaken[s[i] - 'a'] = true;
            res += s[i];
        }

        return res;
    }
};