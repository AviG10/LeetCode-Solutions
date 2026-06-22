class Solution {
private:
    int dist(int a, int b){
        if(a == 26 || b == 26) return 0;

        int x1 = a/6, y1 = a%6;
        int x2 = b/6, y2 = b%6;

        return abs(x1-x2) + abs(y1-y2);

    }
    int f(int i, int finger1, int finger2, int &n,string &word, vector<vector<vector<int>>> &dp){
        if(i == n) return 0;

        if(dp[i][finger1][finger2] != -1) return dp[i][finger1][finger2];

        int cur = word[i] - 'A';

        int finger1Move = dist(finger1,cur) + f(i+1,cur,finger2,n,word,dp);
        int finger2Move = dist(finger2,cur) + f(i+1,finger1,cur,n,word,dp);

        return dp[i][finger1][finger2] = min(finger1Move, finger2Move);
    }
public:
    int minimumDistance(string word) {
        int n = word.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (27,vector<int>(27,-1)));
        return f(0,26,26,n,word,dp);
    }
};