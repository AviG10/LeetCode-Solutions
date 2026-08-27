class Solution {
private:    
    bool solve(string &cur, vector<int> &freq, string &target, int i, bool greater, string &result){
        // Base Case
        if(i == target.length()){
            if(greater){
                result = cur;
                return true;
            }
            else 
                return false;
        }


        for(char ch = 'a'; ch <= 'z'; ch++){
            if(freq[ch - 'a'] == 0)
                continue;
            
            if(greater == false && ch < target[i])
                continue;
            
            // DO Operation
            cur.push_back(ch);
            freq[ch - 'a']--;
            
            // Explore Operation
            bool isGreaterNow = greater || ch > target[i];
            if(solve(cur, freq, target, i + 1, isGreaterNow, result))
                return true;
            
            // Undo Operation
            cur.pop_back();
            freq[ch - 'a']++;
        }

        return false;
    }
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26, 0);

        for(char &ch: s)
            freq[ch - 'a']++;
        
        string cur;
        string result;

        solve(cur, freq, target, 0, false, result);

        return result;
        
    }
};