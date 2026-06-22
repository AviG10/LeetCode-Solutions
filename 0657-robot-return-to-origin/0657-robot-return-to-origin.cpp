class Solution {
public:
    bool judgeCircle(string moves) {
        int n = moves.size();
        int up = 0, down = 0, left = 0, right = 0;

        for(int i = 0;i < n;i++){
            if(moves[i] == 'U') up++;
            else if(moves[i] == 'D') down++;
            else if(moves[i] == 'L') left++;
            else right++;
        }

        if((left == right) && (up == down)) return true;
        else return false;
    }
};