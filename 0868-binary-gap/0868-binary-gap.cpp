class Solution {
public:
    int binaryGap(int n) {
        string s = "";

        while(n > 0){
            s += to_string(n%2);
            n /= 2;
        }

        reverse(s.begin(),s.end());

        int prevInd = -1, ans = 0;

        for(int i = 0;i < s.length();i++){
            if(s[i] == '1'){
                if(prevInd == -1) prevInd = i;
                else{
                    ans = max(ans,i-prevInd);
                    prevInd = i;
                }
            }
        }

        return ans;
    }
};