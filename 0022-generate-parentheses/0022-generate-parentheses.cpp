class Solution {
private:
    void solve(int openBracket, int closedBracket, string &s, vector<string> &result){
        if(closedBracket == 0)
            return;

        if(openBracket == 0){
            for(int i = 0;i < closedBracket; i++)
                s += ")";

            result.push_back(s);

            for(int i = 0;i < closedBracket; i++)
                s.pop_back();

            return;
        }
        
        s += "(";
        solve(openBracket - 1, closedBracket, s, result);
        s.pop_back();

        if(openBracket < closedBracket){
            s += ")";
            solve(openBracket, closedBracket-1, s, result);
            s.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string s = "";
        
        solve(n, n, s, result);

        return result;
    }
};