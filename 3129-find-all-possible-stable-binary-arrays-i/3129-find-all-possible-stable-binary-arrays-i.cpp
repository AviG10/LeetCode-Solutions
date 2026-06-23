class Solution {
private:
    int MOD = 1e9 + 7;
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<int>>> dp(zero+1, vector<vector<int>>(one+1, vector<int>(2,0)));
        
        dp[0][0][0] = dp[0][0][1] = 1;

        for(int zeroLeft = 0;zeroLeft <= zero;zeroLeft++){
            for(int oneLeft = 0;oneLeft <= one;oneLeft++){
                for(int prevNum = 0;prevNum <= 1;prevNum++){

                    if(zeroLeft == 0 && oneLeft == 0) continue;

                    int res = 0;
                    if(prevNum){
                        for(int len = 1;len <= min(limit,zeroLeft); len++){
                            res = (res + dp[zeroLeft-len][oneLeft][false])%MOD;
                        }
                    }
                    else{
                        for(int len = 1;len <= min(limit,oneLeft); len++){
                            res = (res + dp[zeroLeft][oneLeft-len][true])%MOD;
                        }
                    }

                    dp[zeroLeft][oneLeft][prevNum] = res;
                }
            }
        }
        return (dp[zero][one][true] + dp[zero][one][false])%MOD;
    }
};