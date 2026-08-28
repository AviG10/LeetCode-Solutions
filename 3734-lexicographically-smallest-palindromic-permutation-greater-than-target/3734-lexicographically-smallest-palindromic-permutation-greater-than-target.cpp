class Solution {
private:
    string buildPalindrome(string &cur, char &midChar){
        string result = "";

        string firstHalf = cur;
        string secondHalf = firstHalf;

        reverse(secondHalf.begin(), secondHalf.end());

        if(midChar != '$')
            result = firstHalf + midChar + secondHalf;
        else 
            result = firstHalf + secondHalf;

        return result;
    }
    
    bool solve(string &cur, vector<int> &freq, string &target, int i, bool greater, string &result, int &halfLen, char &midChar){
        // Base Case
        if(i == halfLen){
            string palindromeStr = buildPalindrome(cur, midChar);
            
            if(palindromeStr > target){
                result = palindromeStr;
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
            if(solve(cur, freq, target, i + 1, isGreaterNow, result, halfLen, midChar))
                return true;
            
            // Undo Operation
            cur.pop_back();
            freq[ch - 'a']++;
        }

        return false;
    }
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> freq(26, 0);

        for(char &ch: s)
            freq[ch - 'a']++;
        
        int oddCharCount = 0;
        char midChar = '$';
        
        for(int c = 0; c < 26; c++){
            if(freq[c] % 2 == 1){
                oddCharCount++;
                midChar = c + 'a';
            }
        }

        if(oddCharCount > 1)
            return "";
        
        for(int c = 0; c < 26; c++)
            freq[c] /= 2;

        int halfLen = n / 2;

        string cur;
        string result;

        solve(cur, freq, target, 0, false, result, halfLen, midChar);

        return result;
    }
};