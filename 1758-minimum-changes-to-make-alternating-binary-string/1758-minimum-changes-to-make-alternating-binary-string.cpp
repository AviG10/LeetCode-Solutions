class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int cnt = 0; // string starting with 0 -- 01010101..

        for(int i = 0;i < n;i++){
            if((i%2 == 0 && s[i] != '0') || (i%2 == 1 && s[i] != '1')) 
                cnt++;            
        }

        return min(cnt,n-cnt);
    }
};