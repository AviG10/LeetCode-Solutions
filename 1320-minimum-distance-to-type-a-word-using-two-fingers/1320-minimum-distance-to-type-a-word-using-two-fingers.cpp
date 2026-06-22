// Space Optimization
class Solution {
private:
    int dist(int a, int b){
        if(a == 26 || b == 26) return 0;

        int x1 = a/6, y1 = a%6;
        int x2 = b/6, y2 = b%6;

        return abs(x1-x2) + abs(y1-y2);

    }
public:
    int minimumDistance(string word) {
        int n = word.size();
        vector<vector<int>>  next(27,vector<int>(27,-1)), prev(27,vector<int>(27,-1));
        
        for(int finger1 = 0;finger1 <= 26;finger1++){
            for(int finger2 = 0;finger2 <= 26;finger2++){
                next[finger1][finger2] = 0;
            }
        }

        for(int i = n-1;i >= 0;i--){
            for(int finger1 = 0;finger1 <= 26;finger1++){
                for(int finger2 = 0;finger2 <= 26;finger2++){
                    int cur = word[i] - 'A';

                    int finger1Move = dist(finger1,cur) + next[cur][finger2];
                    int finger2Move = dist(finger2,cur) + next[finger1][cur];

                    prev[finger1][finger2] = min(finger1Move, finger2Move);
                }
            }
            next = prev;
        }

        return next[26][26];
    }
};