class Solution {
private:
    int findLCP(int i, int j, int &n, string &word,vector<vector<int>> &dp){
        if(i == n-1 || j == n-1){
            if(word[i] == word[j]) return 1;
            else return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];

        if(word[i] == word[j]) return dp[i][j] = 1 + findLCP(i+1,j+1,n,word,dp);
        else return dp[i][j] = 0;
    }

    string verifyLCP(string &word, vector<vector<int>> &lcp){
        int n = word.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                int lcpVal = findLCP(i,j,n,word,dp);
                
                if(lcp[i][j] != lcpVal) return "";
            }
        }

        return word;
    }   
public:
    string findTheString(vector<vector<int>> &lcp) {
        int n = lcp.size();
        
        string word = "";
        for(int i = 0;i < n;i++){
            word += '$';
        }

        for(int i = 0;i < n;i++){

            //step - 1 
            for(int j = 0;j < i;j++){
                if(lcp[j][i] > 0){
                    word[i] = word[j];
                    break;
                }
            }

            //step - 2
            if(word[i] == '$'){

                vector<bool> isCharVis(26,false);

                for(int j = 0;j < i;j++){
                    if(lcp[j][i] == 0){
                        isCharVis[word[j]-'a'] = true;
                    }
                }

                for(int k = 0;k < 26;k++){
                    if(!isCharVis[k]){
                        word[i] = 'a' + k;
                        break;
                    }
                }

                if(word[i] == '$') return "";
            }
        }

        return verifyLCP(word,lcp);
    }
};