class Solution {
private:
    int MOD = 1e9 + 7;
    
    int getIntFromChar(char ch){
        return ch != 'S' ? ch - '0' : 0;
    }

    bool isValid(int i, int j, int n, vector<string>& board){
        return i >= 0 && i < n && j >= 0 && j < n && board[i][j] != 'X';
    }
    
    pair<int, int> solve(int i, int j, int &n, vector<string>& board, vector<vector<pair<int, int>>> &dp){
        if(board[i][j] == 'E') 
            return {0,1};
        
        if(board[i][j] == 'X')
            return {0,0};

        if(dp[i][j] != make_pair(-1, -1))
            return dp[i][j];
        
        int upScore = 0, upPaths = 0;
        int leftScore = 0, leftPaths = 0;
        int diagScore = 0, diagPaths = 0;

        char ch = board[i][j];

        if(isValid(i-1,j, n, board)){ // up
            auto [score, paths] = solve(i-1, j, n, board, dp);

            upScore += score;
            upPaths += paths;

            if(upPaths > 0){
                upScore += getIntFromChar(ch);
            }
        }

        if(isValid(i,j-1, n, board)){ // left
            auto [score, paths] = solve(i, j-1, n, board, dp);

            leftScore += score;
            leftPaths += paths;

            if(leftPaths > 0){
                leftScore += getIntFromChar(ch);
            }
        }

        if(isValid(i - 1,j-1, n, board)){ // diagonal
            auto [score, paths] = solve(i-1, j-1, n, board, dp);

            diagScore += score;
            diagPaths += paths;

            if(diagPaths > 0){
                diagScore += getIntFromChar(ch);
            }
        }

        int bestScore = 0, bestPaths = 0;

        if(upScore ==  leftScore && leftScore == diagScore){
            bestScore = upScore;
            bestPaths = upPaths + leftPaths + diagPaths;
        }
        else if(upScore == leftScore){
            bestScore = upScore;
            bestPaths = upPaths + leftPaths;

            if(diagScore > bestScore || (diagScore == bestScore && diagPaths > bestPaths)){
                bestScore = diagScore;
                bestPaths = diagPaths;
            }
        }
        else if(leftScore == diagScore){
            bestScore = leftScore;
            bestPaths = leftPaths + diagPaths;

            if(upScore > bestScore || (upScore == bestScore && upPaths > bestPaths)){
                bestScore = upScore;
                bestPaths = upPaths;
            }
        }
        else if(upScore == diagScore){
            bestScore = upScore;
            bestPaths = upPaths + diagPaths;

            if(leftScore > bestScore || (leftScore == bestScore && leftPaths > bestPaths)){
                bestScore = leftScore;
                bestPaths = leftPaths;
            }
        }
        else{
            bestScore = leftScore;
            bestPaths = leftPaths;

            if(upScore > bestScore || (upScore == bestScore && upPaths > bestPaths)){
                bestScore = upScore;
                bestPaths = upPaths;
            }

            if(diagScore > bestScore || (diagScore == bestScore && diagPaths > bestPaths)){
                bestScore = diagScore;
                bestPaths = diagPaths;
            }
        }

        return dp[i][j] = {bestScore, bestPaths % MOD};
    }
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();

        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {-1,-1}));
        pair<int, int> result = solve(n - 1, n - 1, n, board, dp);

        return {result.first, result.second};
    }
};