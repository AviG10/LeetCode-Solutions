// KMP Algorithm
class Solution {
private:
    void computeLPS(string &goal, vector<int> &LPS){
        int len = 0;
        LPS[0] = 0;
        int i = 1;

        while(i < goal.length()){
            if(goal[i] == goal[len]){
                len++;
                LPS[i] = len;
                i++;
            }
            else{
                if(len != 0) len = LPS[len-1];
                else len = 0, i++;
            }
        }
    }
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;
        if(s == goal) return true;

        int m = s.length(), n = goal.length();

        // compute LPS - Longest Prefix Suffix till ith index
        vector<int> LPS(n,0);
        computeLPS(goal,LPS);

        s = s + s;

        // KMP Algorithm
        int i = 0, j = 0;
        while(i < 2*m){
            if(s[i] == goal[j]) i++, j++;
            
            if(j == n) return true;
            else if(s[i] != goal[j]){
                if(j != 0) j = LPS[j-1];
                else i++;
            }
        }

        return false;
    }
};