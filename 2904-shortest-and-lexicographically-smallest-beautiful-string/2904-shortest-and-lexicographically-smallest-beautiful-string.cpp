class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int start = 0, end = 0, cntOfOne = 0;
        string ans = "";

        while(end < n){
            if(s[end] == '1') 
                cntOfOne++;

            while(start <= end && cntOfOne > k){
                if(s[start] == '1') 
                    cntOfOne--;

                start++;
            }

            if(cntOfOne == k){
                while(start <= end && s[start] == '0')
                    start++;

                string subString = s.substr(start, end-start+1);
                
                if(ans == "") 
                   ans = subString;
                else if(subString.length() < ans.length())
                    ans = subString;
                else if(subString.length() == ans.length() && subString < ans)
                    ans = subString;
            }

            end++;
        }

        return ans;
    }
};