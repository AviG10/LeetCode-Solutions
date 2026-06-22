class Solution {
public:
    string decodeCiphertext(string s, int row) {
        int len = s.length();
        
        if(len == 0) return "";

        int col = len / row;
        string ans = "";
        
        for(int k = 0;k < col;k++){
            int i = k;

            while(i < len){
                ans += s[i];
                i += (col+1);
            }
        }

        int n = ans.size();
        int lastIdx = n-1;
        while(ans[lastIdx] == ' '){
            ans.pop_back();
            lastIdx--;
        }
        
        return ans;
    }
};