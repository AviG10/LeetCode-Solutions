class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.length();
        int segment = 1;

        for(int i = 1;i < n;i++){
            if(s[i] == '1' && s[i] != s[i-1]){
                segment++;
            }
        }

        return (segment == 1) ? true : false;
    }
};