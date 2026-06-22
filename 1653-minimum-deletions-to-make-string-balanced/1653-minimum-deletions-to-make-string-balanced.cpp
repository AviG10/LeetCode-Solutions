// Space Optimization
class Solution {
public:
    int minimumDeletions(string s) {
        
        int n = s.length();

        vector<int> prev(2,0), cur(2,0);

        for(int i = 1;i <= n;i++){
            for(int state = 0;state < 2;state++){
                if(state == 0){
                    if(s[i-1] == 'a') cur[state] = prev[state];
                    else cur[state] = 1 + prev[state];
                }
                else {
                    if(s[i-1] == 'a') cur[state] = min(prev[0], 1 + prev[state]);
                    else cur[state] = prev[state];
                }
            }
            prev = cur;
        }

        // 0 - We have seen a's on Right Side
        // 1 - We have b's in Right Side
        // First give options to accept b's. So, initializing state at 1
        return prev[1];
        
    }
};