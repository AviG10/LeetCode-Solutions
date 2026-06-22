class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.length();
        int cntL = 0, cntR = 0, cnt_ = 0;

        for(int i = 0;i < n;i++){
            if(moves[i] == 'L') cntL++;
            else if(moves[i] == 'R') cntR++;
            else cnt_++;
        }

        if(cntL > cntR) return (cntL-cntR+cnt_);
        else return (cntR-cntL+cnt_);
    }
};