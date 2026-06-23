class Solution {
public:
    int minFlips(string s) {
        // Alternating Strings Possible
        // 010101010101...
        // 10101010101010....

        int n = s.length();
        int i = 0, j = 0;
        int flip1 = 0, flip2 = 0;
        int ans = INT_MAX;

        while(j < 2*n){
            int charAlter1_j = (j%2) ? '1' : '0';
            int charAlter2_j = (j%2) ? '0' : '1';

            if(s[j%n] != charAlter1_j) flip1++;
            if(s[j%n] != charAlter2_j) flip2++;

            if(j-i+1 > n){
                int charAlter1_i = (i%2) ? '1' : '0';
                int charAlter2_i = (i%2) ? '0' : '1';

                if(s[i%n] != charAlter1_i) flip1--;
                if(s[i%n] != charAlter2_i) flip2--;
                
                i++;
            }

            if(j-i+1 == n){
                ans = min(ans,min(flip1,flip2));
            } 
            
            j++;
        }

        return ans;
    }
};